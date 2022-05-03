# Assignment 2 - Shell Scripting


## Prereq

Make sure you have 2 scripts namely ` lab.sh` and ` new.sh`


You can run the scripts using ` ./lab.sh college.csv output.txt `

## Part 1

If number of arguments will not be 2, you will get message 

` Please give 2 filenames as argument like "./lab.sh file1.csv file2.txt" `

## Part 2

If input file does not exists then you will get an error saying ` Input file does not exists`

## Part 3 & 4

I have used awk command for these questions

## Part 5

First I have extracted all the geographical zones and then run another script file `new.sh` which takes as parameter the geographical zones and averages the admission rate

## Part 6

First using sort, I have sorted the data on basis of median earnings

Then using sed, i extracted the bottom 5 data 

Then printed it in reverse order

## Note

Three extra files will be generated during the process namely

 `geo.txt` contains the list of different geographical zones

 `sorted.txt` contains the sorted version of input file 

 `sorted5.txt` contains the list of 5 top colleges on basis of median earnings but in reverse order


