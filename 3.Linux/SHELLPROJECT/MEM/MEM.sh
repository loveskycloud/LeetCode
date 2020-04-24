#!/bin/bash
echo -n $(date "+%Y-%m-%d__%H:%M:%S")
#awk -v'{printf("%s ", nowtime)}'
last=$1
cat /proc/meminfo | grep MemTotal | awk '{printf(" %sM  ", $2 / 1024)}'
cat /proc/meminfo | grep MemFree | awk '{printf("%sM  ", $2 / 1024)}'
free -m | grep Mem | awk '{printf("%.1f% ", $3 / $2 * 100)}'
free -m | grep Mem | awk -v last=$1 '{printf("%.1f%\n", 0.3 * last + 0.7 * $3 / $2 * 100)}'
