/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 15일 11시 27분 58초
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

#define MAX 100

char* escape(char *str1, char *str2)
{
  int i = 0, j = 0;
  char *ret = NULL;
  char tmp = '\0';

  if (!str1 || !str2)
    return NULL;

  while ((tmp = *(str1 + i))){

    switch (tmp){
      case '\n':
        *(str2 + j) = '\\';
        *(str2 + j + 1) = 'n';
        j += 2;
        break;
      case '\t':
        *(str2 + j) = '\\';
        *(str2 + j + 1) = 't';
        j += 2;
        break;
      default:
        *(str2 + j) = *(str1);
        j += 1;
        break;
    }
    i++;
  }
  
  ret = str2;
  return ret;
}

int main(int argc, char* argv[]) {

  char str1[MAX] = "aa\tbb\ncc";
  char str2[MAX] = {'\0', };

  escape(str1, str2);
  printf("%s\n", str1);
  printf("%s\n", str2);

  return 0;
}

