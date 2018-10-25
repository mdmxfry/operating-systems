#!/usr/bin/env bash

mkdir ../week1
mkdir files
touch ../week1/file.txt

ln ../week1/file.txt _ex2.txt
ls -i ../week1/file.txt
find ../week1/file.txt -inum 10608522 > ./files/ex2.txt
find ../week1/file.txt -inum 10608522 -exec rm {} \;
