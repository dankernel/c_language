/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 10일 11시 37분 50초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jun-Hyung Park, google@dankook.ac.kr
 *   Organization:  Dankook Univ.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* squeeze(char *str1, char *str2)
{
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int i = 0, j = 0;
  int tmp = 0;
  char *ret;
  int ind = 0;

  ret = malloc(100);
  memset(ret, '\0', 100);

  if (!str1 || !str2)
    return NULL;

  while (*(str2 + j) != '\0') {

    while ((*(str1 + i) != '\0') && (*(str1 + i) != *(str2 + j)))
      i++;

 
    if ((*(str1 + i) != *(str2 + j))) {
      ret[ind++] = *(str2 + j);
      printf("__ret : %s \n", ret);
    }

    j++;
    i=0;
  }
  printf("ret : %s \n", ret);

  return ret;
}

int main(int argc, char* argv[]) {

  char *ret = NULL;

  ret = squeeze("a7b", "ab12ab34ab56a2b7a77ab7ab7ba77va7ba7ab");
  printf("%s \n", ret);

  return 0;
}

