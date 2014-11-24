/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 23일 19시 36분 43초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         author:  Jun-Hyung Park (), google@dankook.ac.kr
 *   organization:  Dankook Univ.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*  bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;

  return b;
} 

int main(int argc, char* argv[])
{
  unsigned int ret = 0;

  ret = bitcount(16);
  printf("%u \n", ret);

  return 0;
}

