#!/bin/bash
# W. H. Bell
# A simple bash script to plot a histogram with gnuplot
if [[ $# != 1 ]]; then
  echo " Usage $0 <filename>"
  exit 1
fi

echo "plot \"$1\" tit \"$1\" with boxes" | gnuplot -persist
