make -s re
make -s clean
gcc -Wall -Wextra -Werror main.c -L. -lft
echo "./a.out \"\xff\xaa\xde\xffMACOSX\xff\" \"\xff\xaa\xde\x02\" 8 e"
./a.out "\xff\xaa\xde\xffMACOSX\xff" "\xff\xaa\xde\x02" 8 e
