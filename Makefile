clean: 
	rm -rf *.o *.a *_test

fmt: 
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror


nodes.o: nodes.c nodes.h
	gcc -g -c nodes.c -o nodes.o

nodes.a: nodes.o
	ar rc nodes.a nodes.o

main.o: main.c
	gcc -g -c main.c -o main.o -lm


nodes_test.o: nodes_test.c nodes.h
	gcc -g -c nodes_test.c -o nodes_test.o

nodes_test: nodes_test.o nodes.a
	gcc -g -static -o nodes_test nodes_test.o nodes.a -lm

	
test: nodes_test
	./nodes_test
