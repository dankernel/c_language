/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 09일 14시 11분 15초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int main(int argc, char* argv[]) {

  /*
  unsigned char u_ch;
  unsigned short u_sh;
  unsigned int u_in;
  unsigned long u_lo;

  char ch;
  short sh;
  int in;
  long lo;
  */

  printf("CHAR_BIT %u \n", CHAR_BIT);
  printf("SCHAR_MIN %d \n", SCHAR_MIN);
  printf("SCHAR_MAX %d \n", SCHAR_MAX);
  printf("UCHAR_MAX %d \n", UCHAR_MAX);
  printf("CHAR_MAX %d \n", CHAR_MAX);
  
  printf("SHRT_MIN %d \n", SHRT_MIN);
  printf("SHRT_MAX %d \n", SHRT_MAX);
  printf("USHRT_MAX %d \n", USHRT_MAX);

  printf("INT_MAX %u \n", INT_MAX);
  printf("INT_MIN %u \n", INT_MIN);
  printf("UINT_MAX %u \n", UINT_MAX);

  printf("LONG_MAX %lu \n", LONG_MAX);
  printf("LONG_MIN %lu \n", LONG_MIN);
  printf("ULONG_MAX %lu \n", ULONG_MAX);

  return 0;
}

