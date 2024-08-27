#Program to check whether given number is Palindrome or NOT
#Question 1a & 9a

read -p "Enter a Number>> " n
temp=$n
rev=0
while(($temp > 0 ))
do
    r=$((temp%10))
    rev=$((rev*10+r))
    temp=$((temp/10))
done
if [ $rev -eq $n ];
    then echo "Your number is a Palindrome!!!"
else echo "Your number is NOT a Palindrome!!!"
fi