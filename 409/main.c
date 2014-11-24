/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 24일 19시 28분 58초
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
#include <ctype.h>
#include <math.h>

#define MAXVAL 100  /*  maximum depth of val stack */
#define MAXOP 100   /*  max size of operand or operator */
#define BUFSIZE 1
#define NUMBER '0'  /*  signal that a number was found */

#define SIN 0x00000001

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

char buf[BUFSIZE];  /*  buffer for ungetch */
int bufp = 0;       /*  next free position in buf */
int sp = 0;         /*  next free stack position */
double val[MAXVAL]; /*  value stack */
double most_recently = 0;

int getch(void) /*  get a (possibly pushed-back) character */
{
  int ret = 0;

  if (bufp > 0){ 
    ret =  buf[--bufp];
    printf(">>get Buf\n");
  } else {
    ret = getchar();
    printf(">>get Char : %c \n", ret);
  }

  return ret;
}

/* push character back on input */
void ungetch(int c) {
  printf("ungetch!!\n");
  if (bufp >= BUFSIZE)
    printf("ungetch : too many characters\n");
  else
    buf[bufp++] = c;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
  int i, c;

  // ' ' or '\t' => call more getch()
  while ((s[0] = c = getch()) == ' ' || c == '\t');

  printf("buf = %s \n", buf);

  s[1] = '\0';

  if (!isdigit(c) && c != '.') {
    if (c == EOF) 
      printf("EOF!!!!!!\n");
    return c; /* not a number */
  }

  i = 0;
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()));
  
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()));

  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
} 


/*  push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL) {
    val[sp++] = f;
    printf("[ok] push...  f : %f \n", f);
    printf("[ok] push... sp : %d \n", sp);
    printf("[ok] push...val : %f \n", val[sp - 1]);
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/*  pop: pop and return top value from stack */
double pop_all(void)
{
  while (pop() != 0.0)
    pop();
}

/*  pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int main(int argc, char* argv[])
{

  int type;
  double op1;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {

    printf("=type : %c \n", type);
    printf("=sp   : %d \n", sp);
    switch (type) {
      case NUMBER:            // ='0'
        printf("push %s \n", s);
        push(atof(s));
        break;
      case '+':
        printf("+\n");
        push(pop() + pop());
        break;
      case '*':
        printf("*\n");
        push(pop() * pop());
        break;
      case '-':
        printf("-\n");
        op2 = pop();
        push(pop() - op2);
        break;
      case '%':
        printf("%\n");
        op2 = pop();
        op1 = pop();
        push( op1 - (((int)(op1/op2))*op2) );
        break;
      case '/':
        printf("/\n");
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '\n':
        //printf("pop : %.8g\n", pop());
        break;
      case 'l':                       
        printf("l\n");
        printf("%f \n", val[sp - 1]);
        most_recently = val[sp - 1];  //XXX most_recentl..//
        break;
      case 'c':                       
        printf("c\n");
        pop_all();
        break;
      case 's':                       
        printf("s\n");
        push( sin(pop()) );
        break;
      case 'e':                       
        printf("e\n");
        push( exp(pop()) );
        break;
      case 'p':                       
        printf("p\n");
        push( pow(pop(), pop()) );
        break;

      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

