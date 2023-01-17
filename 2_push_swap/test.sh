ARG=$(seq 500 | sort -R | tr '\n' ' ');
echo $ARG > work
# ./push_swap $ARG | wc -l
# ./push_swap $ARG | ./checker $ARG

./test $ARG > res
./push_swap $ARG > res_2
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l

