p=0
q=1
echo $p
m=0
while [ $m -le 20 ]
do
	echo `expr $q`
	k=$p
	i=$q
	q=`expr $q + $k`
	m=`expr $m + 1`

done
