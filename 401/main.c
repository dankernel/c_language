/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 24일 19시 11분 36초
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

#define MAXLINE 1000 /*  maximum input line length */

char pattern[] = "dk"; /*  pattern to search for */  

/*  getline: get line into s, return length */
int _getline(char s[], int lim)
{
  int c, i;
  i = 0;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c; 

  s[i] = '\0';

  return i;
}

/*  strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;
  int prev = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);

    if (k > 0 && t[k] == '\0')
        prev = i;

  }

  if (prev >= 0)
    return prev;
  else
    return -1;
} 

int main(int argc, char* argv[])
{
  char line[MAXLINE];
  int found = 0;
  int ret = 0;
  while (_getline(line, MAXLINE) > 0)
    if ((ret = strindex(line, pattern)) >= 0) {
      printf("%s", line);
      printf("ret : %d ", ret);
      printf("%s", line + ret);
      found++;
    } else {
      printf("No \n");
    }

  return 0;
}

