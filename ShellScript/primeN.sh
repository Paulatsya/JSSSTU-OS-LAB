read -p "Upper limit: " n
echo "Prime numbers in the range 2 to $n are:"
for (( i=2; i<=n; i++ ))
do
    flag=1
    for (( j=2; j*j<=i; j++ )) 
    do
        if [ $((i%j)) -eq 0 ]; then
            flag=0
            break
        fi
    done
    if [ $flag -eq 1 ]; then
        echo -n "$i "
    fi
done
echo
