#!/bin/bash

if [ -e config ];
then
	rm config
fi
numLines=$1
for i in `seq 1 $numLines`;
do
	x=$((1 + RANDOM % 9))
	y=$((1 + RANDOM % 9))
	name=$(pwgen 10 1)
	line="$x $y $name"
	echo "$line" | tee -a config
done
