clean: 
	rm -rf *.o *.a *_test

fmt: 
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror


find_roots.o: find_roots.c find_roots.h
	gcc -g -c find_roots.c -o find_roots.o -lm

roots.a: find_roots.o
	ar rc roots.a find_roots.o -lm

main.o: main.c
	gcc -g -c main.c -o main.o -lm



roots_test.o: roots_test.c find_roots.h
	gcc -g -c roots_test.c -o roots_test.o

roots_test: roots_test.o roots.a 
	gcc -g -static -o roots_test roots_test.o roots.a -lm

test: roots_test
	./roots_test
