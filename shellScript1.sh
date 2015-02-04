#!/bin/sh

echo  "Enter two numbers for Addition : "
echo -n "Number1: "
read no1

echo -n "Number2: "
read no2
echo 
echo
echo "$no1 + $no2 = `expr $no1 + $no2`"
echo "$no1 - $no2 = `expr $no1 - $no2`"
echo "$no1 * $no2 = `expr $no1 \* $no2`"
echo "$no1 / $no2 = `expr $no1 / $no2`"
