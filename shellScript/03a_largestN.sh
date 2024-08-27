#Program to find largest number in an given array
#Question 3a
declare -a numbers
read -p "Enter the number of elements>> " n
echo "Enter the $n elements>> "
for((i=0; i<$n; i++))
do 
    read numbers[$i]
done
largest=${numbers[0]}
for num in ${numbers[@]}
do 
    if [ $num -gt $largest ]
    then
        largest=$num
    fi
done
echo "The largest number is>> $largest"