#!/bin/bash

WORK=1
#find -size +70M -not -path "./" | grep -q "\." && WORK=0
find -size +30M -not -path "./" | grep -q "\." && WORK=0

if [ $WORK = 1 ]; then
  echo "1"
else
  echo "0"
fi

########################

if [ ! -d .git/ ]
then
  git init
fi

git add .

MSG=auto'-'`date +%Y%m%d'-'%H%M%S`
git commit -m "$MSG"

git push

work="[OK] ".$(pwd)
echo -e '\E[34m'"\033[1m$work\033[0m"
