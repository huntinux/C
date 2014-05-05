#!/bin/bash

#
# 测试reverse_single_list
#

NAME=reverse_single_list.c
#echo ${NAME%*.c}
APP=${NAME/.c/.out}
echo $APP

#gcc $NAME -o ${NAME#.c}
