#!/bin/bash
Time=`date +"%Y-%m-%d__%H:%M:%S"`

Usertotal=`who | awk '{print $1}' | sort | uniq | wc -l`
eval $(`last | grep tty | sort` | awk '{printf("Username=%")}')
echo ${Time} ${Usertotal}

