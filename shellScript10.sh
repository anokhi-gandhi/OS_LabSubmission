list=(1 2 3 4 5 6 7 8 9 10)
echo Numbers in the list are : $list
read -p "Search for a num:" NO
for i in {0..9}
do
if [ "$NO" == "${list[$i]}" ]  
then
echo "The number is in the list "
echo  "Position of the number" `expr $i + 1`
k=0
exit 1
else 
k=1
fi
done
if [ "$k" == 1 ]
then
echo value not found
echo 
fi


