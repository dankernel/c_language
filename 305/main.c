/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 15일 12시 24분 55초
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
#include <string.h>

int itob(char *ret, int num, int b)
{
  int i = 0, tmp = 0, unit = 0, len = 0;
  char *ret_tmp = NULL;

  if (!ret || b <= 0)
    return -1;

  if (!(b == 2 || b == 4 || b == 8 || b == 16))
    return -1;

  //get unit..//
  while (b >>= 1)
    unit++;

  //get index..//
  len = 32 / unit;
  i = len - 1;
  ret_tmp = malloc(sizeof(char) * len);

  while (0 <= i) {
    tmp = (num >> unit * i) & ((1<<unit) - 1);

    if (tmp <= 9)
      tmp += '0';
    else
      tmp = 'A' + (tmp - 10);

    ///insert..///
    *(ret_tmp + len - i - 1) = tmp;
    i--;
  }

  //ret..//
  strcpy(ret, ret_tmp);
  free(ret_tmp);

  return 0;
}

int main(int argc, char* argv[]) {

  char ret[32];
  if (itob(ret, 255, 16) >= 0)
    printf("ret : %s \n", ret);
  else
    printf("err.. \n");

  return 0;
}

