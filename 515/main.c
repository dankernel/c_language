/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 08월 18일 09시 57분 14초
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

#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /*  max #lines to be sorted */

int main(int argc, char *argv[]);

char *lineptr[MAXLINES]; /*  pointers to text lines */ 

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void _qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int r);
int numcmp(char *, char *);

#define MAXLEN 1000 /*  max length of any input line */ 
#define ALLOCSIZE 10000 /*  size of available space */

int _getline(char *line, int max); 

static char allocbuf[ALLOCSIZE]; /*  storage for alloc */
static char *allocp = allocbuf; /*  next free position */

char *alloc(int n) /*  return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /*  it fits */
    allocp += n;
    return allocp - n; /*  old p */
  } else /*  not enough room */
    return 0;
}
void afree(char *p) /*  free storage pointed to by p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

/*  getline: read a line into s, return length */
int _getline(char s[],int lim)
{
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/*  readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = _getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; /*  delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/*  writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/*
 * argv option cheek function
 */
int cheek_option(int i, char *argv[], char *op)
{
  int ret = 0;

  while (i--) {
    if (strcmp(argv[i], op) == 0)
      return 1;
  }

  return ret;
}

/*  sort input lines */
int main(int argc, char *argv[])
{
  int nlines; /*  number of input lines read */
  int numeric = 0; /*  1 if numeric sort */
  int r = 0; /* "-r" option */
  int f = 0; /* "-f" option */

  /* cheek argv option */
  numeric = cheek_option(argc, argv, "-n");
  r = cheek_option(argc, argv, "-r");
  f = cheek_option(argc, argv, "-f");
  printf("n : %d\n", numeric);
  printf("r : %d\n", r);
  printf("f : %d\n", f);

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    /* sort */
    _qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(f ? strcmp : strcasecmp), r);

    /* print */
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

/*  _qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right, int (*comp)(void *, void *), int r)
{
  int i, last;
  void swap(void *v[], int, int);
  
  if (left >= right) /*  do nothing if array contains */
    return; /*  fewer than two elements */
  
  swap(v, left, (left + right)/2);
  last = left;

  for (i = left + 1; i <= right; i++) 
    if (r == 0 && (*comp)(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    } else if (r == 1 && (*comp)(v[i], v[left]) > 0) {
      swap(v, ++last, i);
    }

  swap(v, left, last);
  _qsort(v, left, last-1, comp, r);
  _qsort(v, last+1, right, comp, r);
}

/*  numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
