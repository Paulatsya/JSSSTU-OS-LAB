read -p "Enter number : " num
temp=$num
check=0
while [ $temp -ne 0 ]
do
    remainder=$((temp % 10))
    check=$(( check * 10 + remainder ))
    temp=$(( temp / 10 ))
done
if [ $check -eq $num ];then
    echo "it is palindrome"
else
    echo "not"
fi