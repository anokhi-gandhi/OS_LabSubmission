echo Enter any initials for January month:
read mon
case $mon in
Jan) echo month=January ;;
Janu) echo month=January ;;
Janua) echo month=January ;;
January) echo month=January ;;
jan) echo month=January ;;
*)   echo enter valid month;;   #Case where entry is not valid
esac



#OR other way is:
#case $mon in
#Ja*) echo month=January ;;
#esac
