all:
		clang -I. -c -g unity.c check_libft.c 
		clang unity.o check_libft.o libft.a -g -lbsd
		rm -f *.o

bonus:	
		gcc -I. -c -g unity.c check_bonus.c 
		gcc unity.o check_bonus.o libft.a -g -lbsd -o b.out
		rm -f *.o

clean:
		rm -f *.o a.out b.out libft.a libft.h

.PHONY: clean all bonus