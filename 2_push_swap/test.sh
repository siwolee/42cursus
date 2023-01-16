ARG=$(seq 200 | sort -R | tr '\n' ' ');
echo $ARG > work
# ./push_swap $ARG | wc -l
# ./push_swap $ARG | ./checker $ARG

./test $ARG > res
./test $ARG | ./checker $ARG
./test $ARG | wc -l

