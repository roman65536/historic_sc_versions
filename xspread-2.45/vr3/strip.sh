#!/bin/sh

N=`(ls -l "$1" | awk '{print $5;}') 2>/dev/null`
echo -n "stripping: $1 $N -> "

echo "$1" | grep lib > /dev/null
if [ $? -eq 1 ]; then
	mipsel-linux-strip "$1" > /dev/null 2>&1
fi

mipsel-linux-strip --remove-section .compact_rel "$1" > /dev/null 2>&1
mipsel-linux-strip --remove-section .note "$1" > /dev/null 2>&1
mipsel-linux-strip --remove-section .comment "$1" > /dev/null 2>&1
(mipsel-linux-objdump --headers "$1" | grep gnu.warning) > /tmp/warninky 2> /dev/null
awk '{print $2}' < /tmp/warninky | xargs -n 1 mipsel-linux-strip "$1" --remove-section > /dev/null 2>&1
N=`(ls -l "$1" | awk '{print $5;}') 2>/dev/null`
echo "$N"
