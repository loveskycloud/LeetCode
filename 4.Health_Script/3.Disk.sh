#!/bin/bash
Time=`date +"%Y-%m-%d__%H:%M:%S"`
eval $(df -T -m -x tmpfs -x devtmpfs | tail -n +2 | awk '{printf("Disktotal=%d Diskfree=%d", $3,$4)}')



echo 0 disk ${Disktotal} ${Diskfree} | awk '{printf("%d %s %d %d\t%.2f%\n", $1,$2, $3, $4, $4/$3*100)}':
