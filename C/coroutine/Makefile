all : main count

count: count.c coroutine.c
	gcc -g -Wall -o $@ $^

main : main.c coroutine.c
	gcc -g -Wall -o $@ $^

clean :
	rm -rf main count
