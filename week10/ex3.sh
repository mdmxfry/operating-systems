#!/usr/bin/env bash

mkdir files
touch files/_ex3.txt

chmod -R -x files/_ex3.txt > ex3.txt
chmod -rwx files/_ex3.txt > ex3.txt
chmod -R g=u files > ex3.txt
