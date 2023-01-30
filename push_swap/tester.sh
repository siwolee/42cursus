ARG=$(seq 6 | sort -R | tr '\n' ' ')

./push_swap $ARG | wc -l
./push_swap $ARG | ./Checker_Mac $ARG