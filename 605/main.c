/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 09월 05일 03시 28분 45초
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

#define IN 1
#define HASHSIZE 101

char *_strdup(char *);
struct nlist *lookup(char *);

struct nlist { /*  table entry: */
  struct nlist *next; /*  next entry in chain */
  char *name; /*  defined name */
  char *defn; /*  replacement text */
};
static struct nlist *hashtab[HASHSIZE]; /*  pointer table */

char *_strdup(char *s) /*  make a duplicate of s */
{
  char *p;
  p = (char *) malloc(strlen(s)+1); /*  +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

/*  hash: form hash value for string s */
unsigned hash(char *s)
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  /* make a some number, and & max size */
  return hashval % HASHSIZE;
}

/*  lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;
  /* insert a table(array) */
  for (np = hashtab[hash(s)]; np != NULL; np = np->next) {

    if (strcmp(s, np->name) == 0) {
      return np; /*  found */
    }

  }
  return NULL; /*  not found */
}


/*  install: put (name, defn) in hashtab */
int _undef(char *name)
{
  struct nlist *np;
  unsigned hashval;
  if ((np = lookup(name)) == NULL) { /*  not found */

    return -1;

  } else { /*  already there */
    printf("free np\n");

    memset(np, '\0', sizeof(HASHSIZE));
    free(np);

    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = NULL;

    return 0;
  }
}

/*  install: put (name, defn) in hashtab */
struct nlist *_install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;
  if ((np = lookup(name)) == NULL) { /*  not found */
    np = (struct nlist *) malloc(sizeof(*np));

    if (np == NULL || (np->name = _strdup(name)) == NULL)
      return NULL;

    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
    
  } else { /*  already there */
    printf("already there\n");
    free((void *) np->defn); /* free previous defn */
  }

  if ((np->defn = _strdup(defn)) == NULL)
    return NULL;
  return np;
}

int main(int argc, char* argv[])
{
  struct nlist *tmp = NULL;

  int i = 101;
  while (i--) {
    if (hashtab[i])
      printf("%d : %s\n", i, hashtab[i]->defn);
  }

  _install("aa", "11");
  tmp = lookup("aa");
  printf("%s %s \n", tmp->name, tmp->defn);

  _install("bb", "22");
  _undef("bb");
  tmp = lookup("bb");
  if (tmp)
    printf("%s %s \n", tmp->name, tmp->defn);
  else
    printf("null\n");

  return 0;
}

