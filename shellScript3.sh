#!/bin/sh

echo  "enter number enter Expression enter number "
read no1 exp no2

case $exp in
	+) echo "$no1 + $no2 = `expr $no1 + $no2`" ;;

	-) echo "$no1 - $no2 = `expr $no1 - $no2`" ;;

	/) echo "$no1 / $no2 = `expr $no1 / $no2`" ;;

	%) echo "$no1 % $no2 = `expr $no1 % $no2`" ;;	

	\*) echo "$no1 * $no2 = `expr $no1 \* $no2`";;

	*) echo please enter valid operator






