#!/bin/bash

while [ 1 ]
do
echo "What is the capital of Gujarat?"
read capital

if [ "$capital" == "Gandhinagar" -o "$capital" == "gandhinagar" ]
then
break

else
echo not correct answer!!! 

fi
done
