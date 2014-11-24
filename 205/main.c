/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 12일 02시 52분 02초
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

char *any(char *str1, char *str2)
{
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int i = 0, j = 0;

  while (j < len2) {
   
    while (*(str1 + i) == *(str2 + j))
      i++, j++;

    if (i == len1)
      return (str2 + j - len1);
    else
      i = 0, j++;
  }

  return NULL;
}

int main(int argc, char* argv[]) {

  char *ret = NULL;

  ret = any("ab", "123ab45");
  printf("%s \n", ret);


  return 0;
}

