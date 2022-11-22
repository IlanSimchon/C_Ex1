Math = -lm
AR = ar -rcs
CFLAG = -Wall -g -fPIC -c

all: loops loopd recursives recursived  mains maindloop maindrec


# creating Libraries

loops:   libclassloops.a

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) libclassloops.a basicClassification.o advancedClassificationLoop.o


recursives: libclassrec.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) libclassrec.a basicClassification.o advancedClassificationRecursion.o


recursived: libclassrec.so

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o


loopd: libclassloops.so

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o


# creating main programs

mains: libclassrec.a main.o
	gcc -Wall -o mains main.o libclassrec.a $(Math)

maindloop:  libclassloops.so main.o
	gcc -Wall -o maindloop main.o ./libclassloops.so $(Math)

maindrec: libclassrec.so main.o
	gcc -Wall -o maindrec main.o ./libclassrec.so $(Math)


# creating object files

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc $(CFLAG) advancedClassificationLoop.c -o advancedClassificationLoop.o

basicClassification.o: basicClassification.c NumClass.h
	gcc $(CFLAG) basicClassification.c -o basicClassification.o $(Math)

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc $(CFLAG) advancedClassificationRecursion.c -o advancedClassificationRecursion.o $(Math)

main.o: main.c NumClass.h
	gcc -Wall -c main.c -o main.o $(Math)



.PHONY: clean all loops loopd recursives recursived

clean:
	rm -f *.o *.so *.a mains maindloop maindrec
