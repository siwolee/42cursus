#!/bin/bash

CHK=./checker_Mac
MY_CHK=./checker


# ARG=$(seq 5 | sort -R | tr '\n' ' ')
# ARG=$(seq 100 | sort -R | tr '\n' ' ')
# ARG=$(seq 500 | sort -R | tr '\n' ' ')
# ARG=$(seq 2000 | sort -R | tr '\n' ' ')

for i in {1..10}
do
	ARG=$(seq $i | tr '\n' ' ')
	echo "$ARG"
	printf "result :"
	./push_swap $ARG | $CHK $ARG | tr "\n" " "
	./push_swap $ARG | $MY_CHK $ARG | tr "\n" " "
	echo ""
done

# for cnt in 5 100 500 2000
# do
# 	TOTAL=0
# 	ARG=$(seq $cnt | sort -R | tr '\n' ' ')
# 	for i in {1..10}
# 	do
# 		TOTAL=$(expr $TOTAL + $(./push_swap $ARG | wc -l | bc))
# 		./push_swap $ARG | $CHK $ARG | tr "\n" "/"
# 		./push_swap $ARG | $MY_CHK $ARG | tr "\n" " "
# 	done
# 	echo ""
# 	TOTAL=$(expr $TOTAL / 10)
# 	echo "Average Value for arg $cnt is $TOTAL"	
# 	echo ""
# done
