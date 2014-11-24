/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 08월 02일 08시 42분 54초
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

int tail(char *str, int n)
{
  int line = 0;
  int i = 0;

  while (*(str + i) != '\0') {
    if (*(str + i) == '\n')
      line++;
    i++;
  }

  line--;
  while (i > 0 && line > 0) {
    if (*(str + i) == '\n')
      line--;
    i--;
  }

  i += 2;

  printf("%s\n", (str + i));

  

  return 0;
}

int main(int argc, char* argv[])
{

  char str[] = "Hi\nDKDK\njun\nHyung~\n";
  printf("%s\n", str);

  tail(str, 2);

  return 0;
}

