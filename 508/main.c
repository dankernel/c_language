/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014년 07월 31일 20시 45분 34초
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

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*  day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  
  if (month < 1 || 12 < month) {
    return -1;
  }

  if (day < 1 || daytab[leap][month] < day) {
    return -1;
  }

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
} 

/*  month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i = -1, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  if (year < 1) {
    yearday = -1;
    goto ret;
  }

  if (yearday < 1 || 365 < yearday) {
    yearday = -1;
    goto ret;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

ret:
  *pmonth = i;
  *pday = yearday;
} 

int main(int argc, char* argv[])
{
  int ret = 0;

  int m;
  int d;


  ret = day_of_year(2014, 3, 3);
  printf("ret :  %d\n", ret);

  month_day(2014, 400, &m, &d);
  printf("%d \n", m);
  printf("%d \n", d);

  return 0;
}

