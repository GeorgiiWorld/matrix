CC= g++
CFLAGS= -Wall -Werror -Wextra -std=c++17
LDFLAGS= -lgtest
UNAME= $(shell uname -s)
ifeq ($(UNAME), Linux)
	LDFLAGS += -lm -lsubunit -lpthread -lrt
	CFLAGS += -lm
endif
MY_LIB_NAME= matrix_oop.a

source_files= Model/*.cc
source_files_test= Tests/*.cc
object_files= Objects/*.o

all: clean $(MY_LIB_NAME) test style

$(MY_LIB_NAME): to_objects
	ar rcs $(MY_LIB_NAME) $(object_files)
	ranlib $(MY_LIB_NAME)

test: to_objects to_objects_test
	$(CC) $(object_files) $(LDFLAGS) -o test
	./test

style:
#	cppcheck --enable=all --suppress=missingIncludeSystem --std=c++17 $(source_files) *.h
	clang-format --style=Google -n $(source_files) $(source_files_test) *.h Tests/*.h

leak: test
ifeq ($(UNAME), Linux)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --track-origins=yes ./test
else
	CK_FORK=no leaks -atExit -- ./test
endif

to_objects:
	mkdir -p Objects
	cd Objects && $(CC) -c $(CFLAGS) ../$(source_files)

to_objects_test:
	mkdir -p Objects
	cd Objects && $(CC) -c $(CFLAGS) ../$(source_files_test)

clean:
	rm -rf Objects *.a test

.PHONY: all clean test style leak to_objects to_objects_test
