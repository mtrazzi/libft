if [ ! -f $(dirname "$0")/libft.a ]; then
	make;
	make clean;
fi
gcc -Wall -Wextra -Werror main.c -L. -lft
