/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Write a function htoi(s), which converts a string of hexadecimal digits
 *
 *        Version:  1.0
 *        Created:  2014년 07월 09일 14시 16분 17초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jun-Hyung Park
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAX 1024

int htoi(char *get){

  int ret = 0;
  int i = 0;
  int tmp_i;
  char tmp_c = '\0';

  //exception..//
  if (!get)
    return -1;

  //first pic and loop..//
  tmp_c = *(get + i);
  while (tmp_c != '\n') {

    if ('0' <= tmp_c && tmp_c <= '9')
      tmp_i = tmp_c - '0';
    else if ('A' <= tmp_c && tmp_c <= 'Z')
      tmp_i = tmp_c - 'A' + 10;
    else if ('a' <= tmp_c && tmp_c <= 'z')
      tmp_i = tmp_c - 'a' + 10;
    else
      return -2;

    //XXX : shift and bit-or..//
    ret <<=4;
    ret |= tmp_i;
    printf("debug : %d \n", ret);

    //next..//
    i++;
    tmp_c = *(get + i);
  }

  //over..// 
  if (INT_MAX>>1 <= ret)
    return -3;

  return ret;
}

int main(int argc, char* argv[]) {

  char str[MAX];
  int ret = 0;
  fgets(str, MAX, stdin);

  ret = htoi(str);
  printf("%d \n", ret);

  return 0;
}

