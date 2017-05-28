if [ ! -f $(dirname "$0")/libft.a ]; then
	make;
	make clean;
fi
gcc -Wall -Wextra -Werror main.c -L. -lft
echo "./a.out \"Salut j'ai beaucoup d'imagination\" \"N'est-ce pas\" 8"
./a.out "Salut j'ai beaucoup d'imagination" "N'est-ce pas" 8
