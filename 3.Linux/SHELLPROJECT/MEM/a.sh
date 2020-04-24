#!/bin/bash
free -m | grep "^Mem" | awk -v last_per=$1 -v nowdate=$(date +"%Y-%m-%d_%H:%M:%S") '
{
    printf("%s %sM %sM %.1f%% %.1f%%\n", nowdate, $2, $7, $3 / $2 * 100, 0.3 * last_per + 0.7 * ($3 / $2 * 100));
}'

last=$3
cat /proc/meminfo | grep MemTotal | awk '{printf("%sM  ", $2 / 1024)}'
cat /proc/meminfo | grep MemFree | awk '{printf("%sM  ", $2 / 1024)}'
free -m | grep Mem | awk '{printf("%.1f% ", $3 / $2 * 100)}'
free -m | grep Mem | awk '{printf("%.1f%\n", 0.3 * last + 0.7 * $3 / $2 * 100)}'

