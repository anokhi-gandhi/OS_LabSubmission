no=$#
s=50
if [ $no -eq 0 ]
then
n=` expr 50 + 1 `
k=` expr $n \* $s `
ans=` expr $k / 2 `
else
n=` expr $1 + 1 `
k=` expr $1 \* $n `
ans=` expr $k / 2 `
fi
echo $ans

