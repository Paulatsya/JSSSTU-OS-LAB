read -p "Number 1: " n1
read -p "Number 2: " n2
read -p "Number 3: " n3
if [ "$n1" -ge "$n2" ] && [ "$n1" -ge "$n3" ];
    then
        max=$n1
elif  [ "$n2" -ge "$n1" ] && [ "$n2" -ge "$n3" ];
    then
        max=$n2
else 
    max=$n3
fi
echo "max=$max"