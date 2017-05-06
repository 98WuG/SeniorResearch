#!/bin/bash

convert -size 200x60 xc:skyblue -fill white -stroke black -draw "@rectangles" 1.jpg

feh 1.jpg --auto-zoom
