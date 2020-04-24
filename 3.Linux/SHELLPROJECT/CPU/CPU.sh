#!/bin/bash
echo -n $(date "+%Y-%m-%d__%H:%M:%S")
cat /proc/loadavg | awk '{printf("  %.2f  %.2f  %.2f  ", $1, $2, $3)}'
#awk -v temp=`cat /sys/class/thermal/thermal_zone0/temp /sys/class/thermal/thermal_zone1/temp /sys/class/thermal/thermal_zone2/temp /sys/class/thermal/thermal_zone3/temp /sys/class/thermal/thermal_zone4/temp` {
#    printf("%s", temp[1]);
#}
temp=`cat /sys/class/thermal/thermal_zone0/temp`

if [[ `expr $temp / 1000` lt  50  ]]; then
    echo $temp
fi

