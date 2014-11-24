/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  6글자 뒤로는 안보고 같다고 함.
 *
 *        Version:  1.0
 *        Created:  2014년 08월 21일 04시 12분 44초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         author:  Jun-Hyung Park (), google@dankook.ac.kr
 *   organization:  Dankook Univ.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define MAXWORD 100
#define BUFSIZE 100

char buf[BUFSIZE]; /*  buffer for ungetch */
int bufp = 0; /*  next free position in buf */

struct tnode {  /*  the tree node: */
  char *word;   /*  points to the text */
  int count;    /*  number of occurrences */
  struct tnode *left;   /*  left child */
  struct tnode *right;  /*  right child */
} Treenode;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int _strncmp(char *str1, char *str2, int n);
char *_strndup(char *s, int n); /*  make a duplicate of s */
struct tnode *talloc(void);
char *_strdup(char *);

/* get a (possibly pushed-back) character */
int getch(void) 
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* make a duplicate of s */
char *_strdup(char *s) 
{
  char *p;
  p = (char *) malloc(strlen(s)+1); /*  +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

/* make a duplicate of s */
char *_strndup(char *s, int n) 
{
  char *p;
  p = (char *) malloc(n); /*  +1 for '\0' */
  if (p != NULL)
    strncpy(p, s, n);
  return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;
  while (isspace(c = getch()));

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++) {
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  }

  *w = '\0';
  return word[0];
}

typedef struct tnode *Treeptr;
Treeptr talloc(void)
{
  return (Treeptr) malloc(sizeof(Treenode));
}

int _strncmp(char *str1, char *str2, int n)
{
  return strncmp(str1, str2, n);
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;
  if (p == NULL) { /*  a new word has arrived */
    p = talloc(); /*  make a new node */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++; /*  repeated word */
  else if (cond < 0) /*  less than into left subtree */
    p->left = addtree(p->left, w);
  else /*  greater than into right subtree */
    p->right = addtree(p->right, w);
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

char *_strtok(char *str, char tok)
{
  int i = 0;
  char *tmp = NULL;

  if (!str)
    return NULL;

  /* next str */
  while (*(tmp = (str + i)) != tok) {
    i++;
  }
  tmp++;

  return tmp;
}

char *_strtok_next(char *str, char tok)
{
  char *ret = NULL;

  ret = _strtok(str, tok);
  printf("%s\n", ret);
  printf("%d\n", strlen(ret));

  return ret;
}

/* word frequency count */
int main(int argc, char* argv[])
{
  struct tnode *root;
  char word[MAXWORD];
  root = NULL;

  char sentence[MAXWORD * 100];
  char *p = NULL;

  /* get str */
  memset(sentence, '\0', MAXWORD * 100);
  fgets(sentence, MAXWORD * 100, stdin);

  p = _strtok_next(sentence, ' ');
  printf("p : %s\n", p);

  while (p) {
    p = _strtok_next(p, ' ');
    printf("p : %s\n", p);
  }

  printf("END\n");

  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      root = addtree(root, word);
    }
  }

  treeprint(root);
  return 0;
}

