/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 31일 10시 39분 31초
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

/*  strcat: concatenate t to end of s; s must be big enough */
void _strcat(char *s, char *t)
{ 
  int i, j;
  i = j = 0;
  while (*(s + i) != '\0') /*  find end of s */
    i++;
  while ((*(s + i++) = *(t + j++)) != '\0'); /*  copy t */

} 

int main(int argc, char* argv[])
{
  char arr1[10] = "123";
  char arr2[10] = "asd";

  _strcat(arr1, arr2);
  printf("%s\n", arr1);
  printf("%s\n", arr2);


  return 0;
}

