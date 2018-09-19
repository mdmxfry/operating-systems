#!/usr/bin/env bash
if !([ -f "task2.txt" ])
then
    echo 1 >> task2.txt
fi

while :
do
  if ln task2.txt task2.txt.lock 2>/dev/null;
  then
    num=$( tail -n 1 task2.txt )
    echo $((num+1)) >> task2.txt
    rm task2.txt.lock
  fi
done