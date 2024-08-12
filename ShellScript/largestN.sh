read -p "Enter number of elements" n
echo "Enter numbers"
for (( i=0; i<n; i++ )); do
    read arr[i]
done

max=${arr[0]}
for (( i=1; i<n; i++ )); do
    if [ ${arr[i]} -gt $max ]; then
        max=${arr[i]}
    fi
done
echo "max=$max"