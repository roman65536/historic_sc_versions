#!/bin/bash

echo "query \"Please type in a value\""

read a
echo "let a0=$a"
echo "down"

b=1
IFS=$'\n'
for a in `mysql -u root -p65536 -D test -e "select sensor,count(*) from sensors group by 1" -B -N`
do
	c=`echo $a | cut -d'	' -f 1`
	d=`echo $a | cut -d'	' -f 2`

 

echo "leftstring b$b=\"$c\""
echo "let c$b=$d"
b=$(( $b + 1))


done
