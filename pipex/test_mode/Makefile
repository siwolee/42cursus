all : re
	./a.out
	ls -l | grep 00

re :
	gcc -Wall -Werror -Wextra -g3 test_mode.c
	rm -rf 00*