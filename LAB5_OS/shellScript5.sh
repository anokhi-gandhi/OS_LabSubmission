echo "Input 1st File"
read n
echo "Input 2nd file"
read m
if [ -e $n ]
then
if [ -e $m ]
then
cat $n>>$m
else
cat $n>$m
fi
fi
