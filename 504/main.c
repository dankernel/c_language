/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 31일 10시 42분 38초
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

int strend(char *str, char *key)
{
  int s_len = 0;
  int k_len = 0;
  int len = 0;

  int i = 0;

  while (*(str + s_len++) != '\0');
  while (*(key + k_len++) != '\0');
  len = s_len - k_len;

  printf("len : %d\n", s_len);
  printf("len : %d\n", k_len);

  while (i < len) {

    //printf("%c  %c \n", *(key + i), *(str + len + i));
    if (*(key + i) == *(str + len + i)) {
    } else
      return -1;

    i++;
  }

  return 0;
}

int main(int argc, char* argv[])
{
  int ret = 0;
  char arr1[10] = "asd12a";
  char arr2[10] = "12a";

  ret = strend(arr1, arr2);
  printf("%d\n", ret);

  return 0;
}

