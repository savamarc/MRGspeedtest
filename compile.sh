gcc -fno-move-loop-invariants -fno-unroll-loops -O2 $1.c -o $1
i=1
while [ "$i" -le "$3" ]
do
  ./$1 $2
  ((i++))
done
