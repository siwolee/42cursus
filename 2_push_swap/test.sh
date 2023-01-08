ARG=$(seq 500 | sort -R | tr '\n' ' ');
echo $ARG > work
./push_swap $ARG
./push_swap $ARG | ./checker $ARG

# ./test $ARG

