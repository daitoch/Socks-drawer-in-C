output: main.o dresserLib.o drawerLib.o sockLib.o sortLib.o
	gcc main.o dresserLib.o drawerLib.o sockLib.o sortLib.o -o output
main.o: main.c
	gcc -c main.c
dresserLib.o: dresserLib.c dresserLib.h
	gcc -c dresserLib.c
drawerLib.o: drawerLib.c drawerLib.h
	gcc -c drawerLib.c
sockLib.o: sockLib.c sockLib.h
	gcc -c sockLib.c
sortLib.o: sortLib.c sortLib.h
	gcc -c sortLib.c

clean:
	rm *.o output
