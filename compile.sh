gcc -fno-move-loop-invariants -fno-unroll-loops -O2 $1.c -o $1
for i in 1 2 3 4 5 6 7 8 9 10
do
  ./$1 1000000000
done
