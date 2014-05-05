#!/bin/bash

#
# 测试double_list
#

NAME=double_list.c
#echo ${NAME%*.c}
APP=${NAME/.c/.out} # 后缀名 .out

gcc $NAME -o $APP
./$APP <<!EOF!
3
1 2 3
!EOF!
