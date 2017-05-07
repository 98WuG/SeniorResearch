#!/bin/bash

echo -n "Number of boxes: "
read boxes
./generate.sh $boxes
echo -n "Aspect ratio for enclosing rectangle: "
read ratio
echo $ratio | ./main

file=rectangles.txt
length=$(($(sed -n '1p' $file)*10))
width=$(($(sed -n '2p' $file)*10))
rectangles="$(tail -n +3 $file | tr '\n' ' ')"

convert -size "$length"x"$width" xc:skyblue -fill white -stroke black -draw "$rectangles" 1.jpg

feh 1.jpg --auto-zoom
