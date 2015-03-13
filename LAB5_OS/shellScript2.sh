echo Input string
read word
revword=` expr $word | rev `

if [ $word -eq $revword ] 
then
echo "The input word is a Palindrome";
else
echo The input word is not a palindrome 
fi
