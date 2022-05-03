#!/bin/bash
if [ "$#" == "2" ]   # (1) Checking whether there are 2 arguments or not
then
    input_file=$1
    output_file=$2
    if [[ -f "$input_file" ]]  # (2) Checking whether input file exists or not
        then
            awk -F ',' '{print $1" "$2" "$3" "$5" "$6" "$7" "$10" "$11}' $input_file > $output_file  # (3) Printing given fields  

            echo >> $output_file
            echo "Here is the list of colleges with highest degree as Bachelor" >> $output_file      # (4)
            echo >> $output_file
            awk -F ',' '$3 ~ /Bachelor/ { print $1 }' $input_file >> $output_file                    # Checking which company have bachelor's s their highest degree   

            echo >> $output_file
            echo "Data of average admission rate by grouping the colleges with respect to Geography" >> $output_file
            echo >> $output_file
            echo Geography: Average Admission Rate >> $output_file                                   # (5)
            export input_file
            export output_file
            awk -F ',' '{if (NR!=1) print $6}' $input_file |sort |uniq > geo.txt                     # First, we will extract all the geographical zones and save it 
            awk '{system("./new.sh " $0)}' geo.txt                                                   # in a file named geo.txt, Then we will call another file 
                                                                                                     # where we have written the script to solve the remaining part of this ques
            echo >> $output_file
            echo "List of Top five colleges who have maximum MedianEarnings" >> $output_file         # (6)
            echo >> $output_file
            sort -t, -nk16 $input_file > sorted.txt                                                  # First we will sort the file on basis of median earnings
            sed -e :a -e '$q;N;6,$D;ba' sorted.txt > sorted5.txt                                     # then we will save the top five colleges but here the order will be opposite
            awk '{a[i++]=$0} END {for (j=i-1; j>=0;) print a[j--] }' sorted5.txt > rev_sorted5.txt   # then we will reverse the list 
            awk -F ',' '{print $1}' rev_sorted5.txt >> $output_file                                  # then we print the name of those colleges
      
    else 
        echo "Input file does not exits"
    fi
else
    echo "Please give 2 filenames as argument like \"./lab.sh file1.csv file2.txt\" "
fi