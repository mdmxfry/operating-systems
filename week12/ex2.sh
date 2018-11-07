#!/usr/bin/env bash

# sysctl -a | grep machdep.cpu ~ /proc/cpuinfo on linux
sysctl -a | grep machdep.cpu | ./exe2 ex2.txt
