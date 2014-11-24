/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 31일 11시 07분 54초
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

/* getline: read a line into s, return length */
int _getline(char *s, int lim)
{
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    *(s + i) = c;
  if (c == '\n') {
    *(s + i) = c;
    ++i;
  }
  *(s + i) = '\0';
  return i;
}

/* atoi: convert s to integer */
int _atoi(char *s)
{
  int i, n;
  n = 0;
  for (i = 0; *(s + i) >= '0' && *(s + i) <= '9'; ++i)
    n = 10 * n + (*(s + i) - '0');
  return n;
} 

/*  itoa: convert n to characters in s */
void itoa(int n, char *s)
{
  int i, sign;
  if ((sign = n) < 0) /*  record sign */
    n = -n; /*  make n positive */

  i = 0;
  do { /*  generate digits in reverse order */
    *(s + i++) = n % 10 + '0'; /*  get next digit */
  } while ((n /= 10) > 0); /*  delete it */
  if (sign < 0)
    *(s + i++) = '-';
  *(s + i) = '\0';
  reverse(s);
}

/*  reverse: reverse string s in place */
void _reverse(char *s)
{
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = *(s + i);
    *(s + i) = *(s + j);
    *(s + j) = c;
  }
} 

/*  strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
  int i, j, k;
  for (i = 0; *(s + i) != '\0'; i++) {
    for (j=i, k=0; *(t + k)!='\0' && *(s + j)==*(t + k); j++, k++)
      ;
    if (k > 0 && *(t + k) == '\0')
      return i;
  }
  return -1;
} 


/*  getop: get next character or numeric operand */
int getop(char *s)
{
  int i, c;
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s + 1) = '\0';
  if (!isdigit(c) && c != '.')
    return c; /*  not a number */
  i = 0;
  if (isdigit(c)) /*  collect integer part */
    while (isdigit(*(s + ++i) = c = getch()))
      ;
  if (c == '.') /*  collect fraction part */ 

    while (isdigit(*(s + ++i) = c = getch()))
      ;
  *(s + i) = '\0';
  if (c != EOF)
    ungetch(c);
  return 0;
} 

int main(int argc, char* argv[])
{

  return 0;
}

