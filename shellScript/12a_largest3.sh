#Program to find the Largest of 3 numbers
#Question 12a
read -p "Enter number 1>> " n1
read -p "Enter number 2>> " n2
read -p "Enter number 3>> " n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ];
    then echo "$n1 is the greatest"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ];
    then echo "$n2 is the greatest"
else 
    echo "$n3 is the greatest"
fi