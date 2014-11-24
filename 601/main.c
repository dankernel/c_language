/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 08월 21일 03시 59분 04초
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
#include <fcntl.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /*  buffer for ungetch */
int bufp = 0; /*  next free position in buf */

int getch(void) /*  get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*  push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/*  getword: get next word or character from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;
  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;

  if (!isascii(c)) {
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++) {
    //if (!isalnum(*w = getch())) {
    if ((*w = getch()) == '\n') {
      ungetch(*w);
      break;
    }
  }

  *w = '\0';
  return word[0];
}

int main(int argc, char* argv[])
{
  char ret[10];

  getword(ret, 10);
  printf("%s \n", ret);

  return 0;
}

