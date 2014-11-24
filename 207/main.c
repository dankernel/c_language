/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 13일 16시 57분 29초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         author:   (), 
 *   organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

/* 
 * tmp func
 */
void print_bin(unsigned int num)
{/*{{{*/
  int i = 31;
  while (0 <= i)
    printf("%d", (num>>i--) & 1);
  printf("\n\n");
}/*}}}*/

int invert(int x, int p, int n)
{
  int bit = 0;

  //get  bit..//
  printf("bit \n");
  bit = ((1<<n) - 1);
  bit <<= p - n + 1;
  print_bin(bit);

  printf("result \n");
  x ^= bit;
  print_bin(x);

  return bit;
}

int main(int argc, char* argv[]) {

  print_bin(31);
  invert(31, 2, 2);

  return 0;
}
