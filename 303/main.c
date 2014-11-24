/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 15일 11시 38분 26초
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

#define MAX 100

char *_expand(char start, char end)
{
  int i, j = 0;
  char *ret = NULL;
  ret = malloc(sizeof(char) * (end - start));

  for (i=start; i<=end; i++)
    *(ret + j++) = i;
  
  return ret;
}

char *expand(char *str1, char *str2)
{
  int i = 0, j = 0;
  int len = 0;
  char *ret = NULL;
  char *tmp;
  char start, end;

  if (!str1 || !str2)
    return NULL;

  while (*(str1 + i)){
  
    tmp = (str1 + i);
    if (*tmp == '-'){
      //pick char
      start = *(tmp - 1);
      end = *(tmp + 1);

      //get start~end string
      ret = _expand(start, end);
      len = strlen(ret);

      //copy
      memcpy(str2 + j, ret, len);
      free(ret);
      j += len;
    } else {
      start = '\0';
      end = '\0';
    }
    
    //next..//
    i++;
  }
  
  return str2;
}

int main(int argc, char* argv[]) {

  char str1[MAX] = "a-f0-6";
  char str2[MAX] = {'\0', };
  char *ret = NULL;

  ret = expand(str1, str2);
  printf("%s\n", ret);
  printf("%s\n", str2);

  return 0;
}

