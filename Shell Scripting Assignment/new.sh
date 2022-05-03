#!/bin/bash
awk ' BEGIN{FS=","; sum=0;i=0; geo= "'$1' '$2'" }           # First, we will find all those colleges which lie in given geographical zone
{if ($6 == geo) { sum+= $7; i+= 1; } }                      # then we will sum the admission rates
END{print "'$1' '$2': " sum/i }' $input_file >> $output_file   # and then we print the average 
