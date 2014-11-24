/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 15일 11시 25분 17초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         author:   (), 
 *   organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;

  while (low <= high && x != v[mid]) {
    mid = (low+high)/2;

    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;

  }

  if (x == v[mid])
    return mid;

  return -1; /*  no match */
}

int main(int argc, char* argv[]) {

  return 0;
}

