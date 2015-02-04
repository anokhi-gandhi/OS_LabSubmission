
while [ 1 ]
do
echo  "Enter a number to get its square (number below 50): "
echo -n "Number: "
read num
echo
if [ $no -lt 50 ]
then
echo "$no^2 = `expr $no \* $no`"

else
echo Number should be less than 50

fi
done
