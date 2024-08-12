read -p "Enter number of rows" row
read -p "Enter number of cols" col
declare -a matrixA
declare -a matrixB
declare -a matrixS

echo "Enter elements of first matrix"
for (( i=0; i<row; i++ )); do
    for (( j=0; j<col; j++ )); do
        read -p "Element matrixA[$i][$j]" matrixA[$(( i * col + j))]
    done
done
echo "Enter elements of second matrix"
for (( i=0; i<row; i++ )); do
    for (( j=0; j<col; j++ )); do
        read -p "Element matrixB[$i][$j]" matrixB[$(( i * col + j))]
    done
done
for (( i=0; i<row; i++ )); do
    for (( j=0; j<col; j++ )); do
        matrixS[$(( i * col + j ))]=$(( matrixA[$(( i * col + j ))] + matrixB[$(( i * col + j ))] ))
    done
done

echo "Matrix is"
for (( i=0; i<row; i++ )); do
    for (( j=0; j<col; j++ )); do
        echo -n "${matrixS[$(( i * col + j ))]}"

    done
    echo
done
matrixS[$(( i * col + j ))]
