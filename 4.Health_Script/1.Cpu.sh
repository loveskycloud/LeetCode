#!/bin/bash
Time=`data +"%Y-%m-%d__%H:%M:%S"`
LoadAvg=`cut -d " " -f 1-3 /proc/loadavg`
CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp`
CpuTemp=`echo "scale=2;${CpuTemp}/1000"` | bc

eval $(head -n 1 /proc/stat | awk -v Sum1=0 '{for (i=2;i<=11;i++){Sum1=Sum1+$i}
printf("Sum1=%d;Idle1=%d", Sum1, $5)}')
sleep 0.5
eval $(head -n 1 /proc/stat | awk -v Sum2=0 '{for (i=2;i<=11;i++){Sum2=Sum2+$i}}
Printf("Sum2=%d;Idle2=%d", Sum2, $5)')

CpuUsedPerc=`echo "scale=4;(1-(${Idle2}-${Idel1}/(${Sum2}-${Sum1})))"`

WarnLevel="normal"

if [[ `echo "${CpuTemp} >= 70" | bc -l` == 1 ]]; then;
    WarnLevel="warning"
elif [[ `echo "${CpuTemp} >= 50" | bcc -l` == 1 ]];then
    WarnLevel="note"
fi


