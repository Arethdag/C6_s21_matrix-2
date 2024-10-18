.PHONY: all rebuild test gcov_report clean clang clang_fix cppcheck valgrind add
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck -lpthread -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
MATRIX = s21_matrix.a 
TESTS_OBJECT = s21_matrix_test
FIND_C_H_FILES = $(wildcard *.c) \
	$(wildcard *.h)
FIND_TEST_FILES = $(wildcard tests/*.c) \
	$(wildcard tests/*.h)

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
 TEST_FLAGS += -lsubunit -lrt
endif

# -lrt -lsubunit
all: $(MATRIX)

s21_matrix.a:
	$(CC) $(CFLAGS) $(FIND_C_H_FILES) -c
	ar rcs $(MATRIX) *.o
	ranlib $(MATRIX)
	rm -rf *.o
	
rebuild: clean $(MATRIX)

test: $(MATRIX)
	gcc $(CFLAGS) *.c tests/*.c -o $(TESTS_OBJECT) $(TEST_FLAGS) $(GCOV_FLAGS) 
	./$(TESTS_OBJECT)

gcov_report: s21_matrix.a test 
	lcov -t "$(TESTS_OBJECT)" -o $(TESTS_OBJECT).info -c -d .
	genhtml -o report $(TESTS_OBJECT).info
	open report/index.html
	rm -rf *.gcda *.gcno

# gcov_report: s21_matrix.a $(FIND_C_H_FILES) $(FIND_TEST_FILES)
# 	gcc $(GCOV_FLAGS) $(FIND_TEST_FILES) $(FIND_C_H_FILES) -o report.out -lm -lcheck
# 	./report.out
# 	gcov -f $(FIND_C_H_FILES)
# 	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
# 	genhtml -o ./report Coverage_Report.info
# 	rm -f *.gcno *.gcda *.info report.out *.gcov
# 	open ./report/index-sort-f.html

clean:
	rm -rf *.gcda *.gcno *.info *.a *.o s21_matrix_test report

clang:
	clang-format -n -style=Google $(FIND_C_H_FILES)

clang_fix: 
	clang-format -i -style=Google $(FIND_C_H_FILES)

cppcheck:
	cppcheck *c tests/*c --enable=all --suppress=missingIncludeSystem

valgrind: clean
	$(CC) $(CFLAGS) -g tests/*.c s21_*.c  -o $(TESTS_OBJECT) $(TEST_FLAGS) $(GCOV_FLAGS)
	valgrind --leak-check=full --tool=memcheck --track-origins=yes --quiet --log-file=valgrind_fails.log ./$(TESTS_OBJECT)
	rm -rf *.gcda *.gcno

add:
	git add $(FIND_C_H_FILES) $(FIND_TEST_FILES)