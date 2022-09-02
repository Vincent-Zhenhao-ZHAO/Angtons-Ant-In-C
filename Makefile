CC=gcc
DEPS = langton.h visualiser.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

all: library langton.o visualiser.o main.o $(DEPS)
	$(CC) -o ant main.o visualiser.o -L. -lant -lncurses -Wl,-rpath,.

test: library test.o $(DEPS) 
	$(CC) -o test tests/test.o -L. -lant -lncurses -Wl,-rpath,.
	./test

library: 

	$(CC) -c langton.c -Wall -Werror -fPIC -o langton.o

	$(CC) -shared -o libant.so langton.o -lncurses

clean:
	-rm -f test ant *.o *.so tests/*.o


