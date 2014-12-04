CC=gcc
CFLAGS=-Wall
objs=$(patsubst %.c, %.o, $(wildcard *.c))
staticlib=libreadpasswd.a

all : staticlib test

staticlib: readpasswd.o
	ar r $(staticlib) $^

test: $(objs)
	$(CC) $(CFLAGS) $^ -o test

%.o : %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) $(staticlib) $(objs) test tags

.PHONY: all clean
