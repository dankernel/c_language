/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 25일 23시 06분 04초
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

/*  swap: interchange v[i] and v[j] */
inline void reverse_swap(char v[], int len, int i)
{
  int temp;

  //swap..//
  temp = v[i];
  v[i] = v[len - i - 1];
  v[len - i - 1] = temp;

  i++;

  if (i <= len/2 - 1)
    reverse_swap(v, len, i); //XXX : ..//

}

/*  reverse: reverse string s in place */
void reverse(char s[])
{
  int len = strlen(s);

  printf("len : %d  \n", len);

  reverse_swap(s, len, 0);

} 

int main(int argc, char* argv[])
{
  char str[100] = "12345";

  printf("1 : %s\n", str);
  reverse(str);
  printf("2 : %s\n", str);

  return 0;
}

