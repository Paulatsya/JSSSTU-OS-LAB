#Program to Calculate sum of two matrices
#Question 4a
declare -a mat1
declare -a mat2
declare -a sumMat
read -p "Enter the no of rows>> " rows
read -p "Enter the no of cols>> " cols
for((i=0; i<rows; i++ ))
do
    for((j=0; j<cols; j++ ))
    do
        read -p "mat1[$i][$j]>> " mat1[$i,$j]
    done
done
for((i=0; i<rows; i++ ))
do
    for((j=0; j<cols; j++ ))
    do
        read -p "mat2[$i][$j]>> " mat2[$i,$j]
        sumMat[$i,$j]=$((mat1[$i,$j] + mat2[$i,$j])) 
        #calculating result while taking input for efficient code 
    done
done
echo "Resultant Matrix>> "
for((i=0; i<rows; i++ ))
do
    for((j=0; j<cols; j++ ))
    do
        echo -n "${sumMat[$i,$j]}  "
    done
    echo
done
