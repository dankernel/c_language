/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 25일 21시 35분 43초
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

/*  printd: print n in decimal */
void _itoa(char *str)
{
  char tmp = *str;
  
  //printf("tmp : %c \n", tmp);
  
  putchar(tmp);

  if (*(str+1) != '\0')
    _itoa(str+1);

}

int main(int argc, char* argv[])
{
  _itoa("940406");

  return 0;
}

