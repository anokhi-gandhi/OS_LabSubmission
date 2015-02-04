echo input 1st number:
read num1
echo input 2nd number:
read num2
if [ $num1 -gt $num2 ]
then 
echo larger number is : $num1
elif [ $num1 -lt $num2 ]
then 
echo larger number is : $num2
else
echo Both are equal

fi
