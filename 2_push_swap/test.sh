ARG=$(seq 10 | sort -R | tr '\n' ' ');
echo $ARG > work
# ./push_swap $ARG | wc -l
# ./push_swap $ARG | ./checker $ARG

./test $ARG
./test $ARG | ./checker $ARG
./test $ARG | wc -l

