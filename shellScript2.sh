#!/bin/bash


case $2 in
+)
echo "Addition: $1 $2 $3 = `expr $1 $2 $3`";;
-)
echo "Subtraction: $1 $2 $3 = `expr $1 $2 $3`";;
/)
echo "Division: $1 $2 $3 = `expr $1 $2 $3`";;
\*) 
echo "Multiplication: $1 $2 $3 = `expr $1 \* $3`";;
%)
echo "$1 $2 $3 = `expr $1 $2 $3`";;
esac

