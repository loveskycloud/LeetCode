#!/bin/bash
echo -n $(date "+%Y-%m-%d__%H:%M:%S")
cat /proc/loadavg | awk '{printf("  %.2f  %.2f  %.2f  ", $1, $2, $3)}'
#awk -v temp=`cat /sys/class/thermal/thermal_zone0/temp /sys/class/thermal/thermal_zone1/temp /sys/class/thermal/thermal_zone2/temp /sys/class/thermal/thermal_zone3/temp /sys/class/thermal/thermal_zone4/temp` {
#    printf("%s", temp[1]);
#}
temp=`cat /sys/class/thermal/thermal_zone0/temp`
temp=$((${temp} / 1000))
if [[ $temp < 50 ]]; then
    echo $temp | awk '{printf("%.2f℃ normal\n", $1)}'
elif [[ ${temp} -lt 70 ]]; then
    echo $temp | awk '{printf("%.2f  note\n", $1)}'
else 
    echo $temp | awk '{printf("%.2f  warning\n", $1)}'
fi

