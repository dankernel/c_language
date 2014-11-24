/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  .
 *
 *        Version:  1.0
 *        Created:  2014년 07월 14일 19시 37분 54초
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

void print_bin(unsigned int num)
{/*{{{*/
  int i = 31;
  while (0 <= i)
    printf("%d", (num>>i--) & 1);
  printf("\n\n");
}/*}}}*/



int rightrot(int get, int n)
{
  int ret;
  int bit;
  
  printf("shift \n");
  ret= get >>= n;
  print_bin(ret);

  printf("right bit\n");
  bit = get & ((1<<n) - 1);
  print_bin(bit);

  printf("set result\n");
  ret = ret | (bit << (32 - n));
  print_bin(ret);




  return ret;
}

int main(int argc, char* argv[])
{
  int tmp = 10;
  int ret = 0;

  print_bin(tmp);
  ret = rightrot(tmp, 2);

  return 0;
}

