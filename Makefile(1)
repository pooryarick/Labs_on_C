clean: 
	rm -rf *.o *.a *_test

fmt: 
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

test: quadratic_equation_test
	@for test in $(shell find . -maxdepth 2 -type f -regex '.*_test'); do \
		echo "$$test is running"; \
		./$$test || exit 1; \
	done

quadratic_equation.o: quadratic_equation.c quadratic_equation.h
	gcc -g -c quadratic_equation.c -o quadratic_equation.o -lm

quadratic_equation.a: quadratic_equation.o
	ar rc quadratic_equation.a quadratic_equation.o -lm

main.o: main.c
	gcc -g -c main.c -o main.o -lm

quadratic_equation_test.o: quadratic_equation_test.c quadratic_equation.h
	gcc -g -c quadratic_equation_test.c -o quadratic_equation_test.o

quadratic_equation_test: quadratic_equation_test.o quadratic_equation.a 
	gcc -g -static -o quadratic_equation_test quadratic_equation_test.o quadratic_equation.a -lm
