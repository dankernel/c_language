/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Write a loop equivalent to the for loop above without using && or ||. 
 *
 *        Version:  1.0
 *        Created:  2014년 07월 09일 14시 15분 34초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

  int i = 0;
  int lim = 10;
  char s[100] = {'\0', };
  char c = '\0';

  for (i=0; i < lim - 1; ++i) {

    if ((c=getchar()) == '\n')
      break;
    if (c == EOF)
      break;

     s[i] = c;
  }

  printf("\n \n");
  printf("result : %s \n", s);



  return 0;
}

