/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 23일 19시 30분 46초
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

/*  lower: convert c to lower case; ASCII only */
int lower(int c)
{
  return ('A' <= c && c <= 'Z') ? c + 'a' - 'A' : c;
} 

int main(int argc, char* argv[])
{
  int ret = 0;
  ret = lower('F');
  printf("%c \n", ret);

  return 0;
}

