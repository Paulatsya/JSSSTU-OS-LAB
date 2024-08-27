#Program to generate PRIME Numbers between a given range
#Question 2a
read -p "Enter start value>> " start
read -p "Enter end value>> " end
echo "Prime Numbers : "
for((i=start; i<=end; i++))
do 
    isPrime=1
    for((j=2; j*j<=i; j++)) # j=sqrt(i) (or) j*j=i
    do
        if [ $((i%j)) -eq 0 ]
        then
            isPrime=0
            break
        fi
    done
    if [ $isPrime -eq 1 ]
    then echo "$i " 
    fi
done
