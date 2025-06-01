clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

fmt_mac:
	find . -type f \( -name "*.c" -o -name "*.h" \) -print0 | xargs -0 clang-format -style=LLVM -i

#--- stack
stack.o: stack.c stack.h
	gcc -g -c stack.c -o stack.o

stack.a: stack.o
	ar rc stack.a stack.o

stack_test.o: stack_test.c
	gcc -g -c stack_test.c -o stack_test.o

stack_test: stack_test.o stack.a
	gcc -g -o stack_test stack_test.o stack.a -lm
#---

#--- singly linked list
singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	gcc -g -c singly_linked_list.c -o singly_linked_list.o

singly_linked_list.a: singly_linked_list.o
	ar rc singly_linked_list.a singly_linked_list.o

singly_linked_list_test.o: singly_linked_list_test.c
	gcc -g -c singly_linked_list_test.c -o singly_linked_list_test.o

singly_linked_list_test: singly_linked_list_test.o singly_linked_list.a
	gcc -g -o singly_linked_list_test singly_linked_list_test.o singly_linked_list.a -lm
#---

#--- integral
integral_solver.o: integral_solver.c integral_solver.h
	gcc -g -c integral_solver.c -o integral_solver.o

integral_solver.a: integral_solver.o
	ar rc integral_solver.a integral_solver.o

integral_solver_test.o: integral_solver_test.c
	gcc -g -c integral_solver_test.c -o integral_solver_test.o

integral_solver_test: integral_solver_test.o integral_solver.a
	gcc -g -o integral_solver_test integral_solver_test.o integral_solver.a -lm
#---

#---# quadratic
quadratic_solver.o: quadratic_solver.c quadratic_solver.h
	gcc -g -c quadratic_solver.c -o quadratic_solver.o

quadratic_solver.a: quadratic_solver.o
	ar rc quadratic_solver.a quadratic_solver.o

quadratic_solver_test.o: quadratic_solver_test.c quadratic_solver.h
	gcc -g -c quadratic_solver_test.c -o quadratic_solver_test.o

quadratic_solver_test: quadratic_solver_test.o quadratic_solver.a
	gcc -g -o quadratic_solver_test quadratic_solver_test.o quadratic_solver.a -lm
#---#

#--- pool_allocator
pool_allocator.o: pool_allocator.c pool_allocator.h
	gcc -g -c pool_allocator.c -o pool_allocator.o

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

pool_allocator_test.o: pool_allocator_test.c pool_allocator.h
	gcc -g -c pool_allocator_test.c -o pool_allocator_test.o

pool_allocator_test: pool_allocator_test.o pool_allocator.a
	gcc -g -o pool_allocator_test pool_allocator_test.o pool_allocator.a -lm
#---

#--- linear_allocator
linear_allocator.o: linear_allocator.c linear_allocator.h
	gcc -g -c linear_allocator.c -o linear_allocator.o

linear_allocator.a: linear_allocator.o
	ar rc linear_allocator.a linear_allocator.o

linear_allocator_test.o: linear_allocator_test.c linear_allocator.h
	gcc -g -c linear_allocator_test.c -o linear_allocator_test.o

linear_allocator_test: linear_allocator_test.o linear_allocator.a
	gcc -g -o linear_allocator_test linear_allocator_test.o linear_allocator.a -lm
#---

test: quadratic_solver_test integral_solver_test singly_linked_list_test stack_test pool_allocator_test linear_allocator_test
	@for test in $(shell find . -maxdepth 1 -type f -regex '.*_test$$'); do \
		echo "Running $$test"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./$$test || exit 1; \
		echo ""; \
	done
