#include <stdio.h>

#define MAX_FREQ 0x1fff
#define FIRST_QTR (0xffff + 1) / 4
#define HALF (0xffff + 1) / 2
#define THIRD_QTR (0xffff + 1) / 4 * 3
#define MAX_VALUE 0xffff
#define SYMBOLS 257
#define AGRESSION 26

int bits_to_follow;
int bits;
unsigned bit_mask;
int ending;

int low_old, high_old, value, range;
int range_new, low_new, high_new;

int freq[SYMBOLS];
int sum_freq[SYMBOLS + 1];

void compress_ari(FILE *ifp, FILE *ofp);

void decompress_ari(FILE *ifp, FILE *ofp);

void Compress_Prepare(void);

void Decompress_Prepare(void);

void Create_Table(void);

void Update_Table(int symbol);

int Bit_In(FILE *ifp);

void Bit_Out(int bit, int flag, FILE *ofp);

void Bits_Plus_Follow(int bit, FILE *ofp);

void Compress_Symbol(int symbol, FILE *ofp);

void Compress_Ending(FILE *ofp);

void Decompress_First_Value(FILE *ifp);

void Decompress_And_Update(FILE *ifp, FILE *ofp);



void Compress_Prepare(void)
{

 bits = 0;
 bit_mask = 0x80;
 low_old = 0;
 high_old = MAX_VALUE;
 range = high_old - low_old + 1;
 bits_to_follow = 0;
 ending = 0;

 return;
}

void Decompress_Prepare(void)
{

 bit_mask = 0;
 low_old = 0;
 high_old = MAX_VALUE;
 value = 0;
 range = high_old - low_old + 1;

 return;
}

void Create_Table(void)
{

 sum_freq[0] = 0;
 for (int i = 0; i < SYMBOLS; i++)
 {
  freq[i] = 1;
  sum_freq[i + 1] = sum_freq[i] + freq[i];
 }

 return;
}

void Update_Table(int symbol)
{

 if (sum_freq[SYMBOLS] > MAX_FREQ)
  for (int i = 0; i < SYMBOLS; i++)
   freq[i] -= freq[i]/2;

 freq[symbol] += AGRESSION;
 sum_freq[0] = 0;
 for (int i = 1; i <= SYMBOLS; i++)
  sum_freq[i] = sum_freq[i - 1] + freq[i - 1];

}

int Bit_In(FILE *ifp)
{

 if (bit_mask == 0)
 {
  bit_mask = 0x80;
  bits = getc(ifp);
  if (bits == EOF)
   return EOF;
 }

 int result_mask = (int) (bits & bit_mask);

 bit_mask >>= 1;
 if (result_mask)
  return 1;
 else
  return 0;

}

void Bit_Out(int bit, int flag, FILE *ofp)
{

 if (flag == 1)
 {
  putc(bits, ofp);
  return;
 }

 if (bit_mask == 0)
 {
  bit_mask = 0x80;
  putc(bits, ofp);
  bits = 0;
 }

 if (bit != 0)
  bits |= (int) bit_mask;

 bit_mask >>= 1;

}

void Bits_Plus_Follow(int bit, FILE *ofp)
{

 Bit_Out(bit, 0, ofp);
 for (; bits_to_follow > 0; (bits_to_follow)--)
  Bit_Out(!bit, 0, ofp);

}

void Compress_Symbol(int symbol, FILE *ofp)
{

 low_new = low_old + sum_freq[symbol] * range / sum_freq[SYMBOLS];
 high_old = low_old + sum_freq[symbol + 1] * range / sum_freq[SYMBOLS] - 1;
 low_old = low_new;

 for (;;)
 {
  if (high_old < HALF)
   Bits_Plus_Follow(0, ofp);
  else if (low_old >= HALF)
  {
   Bits_Plus_Follow(1, ofp);
   low_old -= HALF;
   high_old -= HALF;
  }
  else if ((low_old >= FIRST_QTR) && (high_old < THIRD_QTR))
  {
   bits_to_follow++;
   low_old -= FIRST_QTR;
   high_old -= FIRST_QTR;
  }
  else break;

  low_old += low_old;
  high_old += high_old + 1;
 }

 range = high_old - low_old + 1;
 range_new = 0;

 low_new = low_old + sum_freq[symbol] * range / sum_freq[SYMBOLS];
 high_new = low_old + sum_freq[symbol + 1] * range / sum_freq[SYMBOLS] - 1;

 if (high_new > low_new && high_new - low_new > range_new)
  range_new = high_new - low_new;

 return;
}

void Compress_Ending(FILE *ofp)
{

 bits_to_follow++;
 if (low_old < FIRST_QTR)
  Bits_Plus_Follow(0, ofp);
 else
  Bits_Plus_Follow(1, ofp);

 Bit_Out(0, 1, ofp);

 return;
}

void compress_ari(FILE *ifp, FILE *ofp)
{

 int symbol;

 //FILE *ifp = (FILE *) fopen(ifile, "rb");
 //FILE *ofp = (FILE *) fopen(ofile, "wb");

 Create_Table();
 Compress_Prepare();

 while (ending != 1)
 {
  if ((symbol = getc(ifp)) == EOF)
   ending++;

  if (symbol == -1)
   symbol = SYMBOLS - 1;

  Compress_Symbol(symbol, ofp);

  Update_Table(symbol);

 }

 Compress_Ending(ofp);
 fflush(ofp);

 //fclose(ifp);
 //fclose(ofp);

}

void Decompress_First_Value(FILE *ifp)
{

 for (int i = 0; i < 2; i++)
 {
  value = (int) ((unsigned int) value << 8);
  value += getc(ifp);
 }

 return;
}

void Decompress_And_Update(FILE *ifp, FILE *ofp)
{

 int symbol;
 int freq_low, freq_high;

 for (;;)
 {
  symbol = 0;

  freq_high = ((value - low_old + 1) * sum_freq[SYMBOLS] - 1) / (high_old - low_old + 1);
  freq_low = 0;

  for (;;)
  {
   if ((freq_low + freq[symbol]) <= freq_high)
    freq_low += freq[symbol];
   else break;

   symbol++;
  }

  if (symbol == 256) break;

  low_new = low_old + sum_freq[symbol] * range / sum_freq[SYMBOLS];
  high_old = low_old + sum_freq[symbol + 1] * range / sum_freq[SYMBOLS] - 1;
  low_old = low_new;

  for (;;)
  {
   if (high_old < HALF)
    ;
   else if (low_old >= HALF)
   {
    value -= HALF;
    low_old -= HALF;
    high_old -= HALF;
   }
   else if ((low_old >= FIRST_QTR) && (high_old < THIRD_QTR))
   {
    value -= FIRST_QTR;
    low_old -= FIRST_QTR;
    high_old -= FIRST_QTR;
   }
   else break;

   low_old += low_old;
   high_old += high_old + 1;
   value += value + Bit_In(ifp);
  }

  putc((int) symbol, ofp);

  range = high_old - low_old + 1;
  range_new = 0;

  low_new = low_old + sum_freq[symbol] * range / sum_freq[SYMBOLS];
  high_new = low_old + sum_freq[symbol + 1] * range / sum_freq[SYMBOLS] - 1;

  if (high_new > low_new && high_new - low_new > range_new)
   range_new = high_new - low_new;

  Update_Table(symbol);
 }

}

void decompress_ari(FILE *ifp, FILE *ofp)
{

 //FILE *ifp = (FILE *) fopen(ifile, "rb");
 //FILE *ofp = (FILE *) fopen(ofile, "wb");

 Create_Table();
 Decompress_Prepare();
 Decompress_First_Value(ifp);
 Decompress_And_Update(ifp, ofp);

 //fclose(ifp);
 //fclose(ofp);

 return;
}

int main(void)
{
 FILE *ifp = fopen("input.txt", "rb");
 FILE *ofp = fopen("output.txt", "wb");

 compress_ari(ifp, ofp);

 fclose(ifp);
 fclose(ofp);

 FILE *ifp2 = fopen("output.txt", "rb");
 FILE *ofp2 = fopen("int.txt", "wb");

 decompress_ari(ifp2, ofp2);

 fclose(ifp2);
 fclose(ofp2);
return 0;
}
