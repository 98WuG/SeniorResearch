#!/bin/bash

echo -n "Number of boxes (0=manual): "
read boxes
if [ $boxes -eq 0 ];
then
	echo "Using user-generated config ($(cat ./config | wc -l) rectangles detected)..."
else
	./generate.sh $boxes
fi
echo -en "\nAspect ratio for enclosing rectangle: "
read ratio
echo $ratio | ./main

file=rectangles.txt
length=$(($(sed -n '1p' $file)*10))
width=$(($(sed -n '2p' $file)*10))
rectangles="$(tail -n +3 $file | tr '\n' ' ')"

convert -size "$length"x"$width" xc:skyblue -fill white -stroke black -draw "$rectangles" 1.jpg

feh 1.jpg --auto-zoom &
