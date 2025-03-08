clean: 
	rm -rf *.o *.a *_test

fmt: 
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror


integral.o: integral.c integral.h
	gcc -g -c integral.c -o integral.o

func.o: func.c integral.h
	gcc -g -c func.c -o func.o

integral.a: integral.o func.o
	ar rc integral.a integral.o func.o

main.o: main.c
	gcc -g -c main.c -o main.o -lm



integral_test.o: integral_test.c
	gcc -g -c integral_test.c -o integral_test.o

integral_test: integral_test.o integral.a 
	gcc -g -static -o integral_test integral_test.o integral.a -lm

test: integral_test
	./integral_test
