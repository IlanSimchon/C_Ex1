Math = -lm
AR = ar -rcs
CFLAG = -Wall -fPIC -c

all: loops loopd recursives recursived  mains maindloop maindrec

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

mains: recursives main.o
	gcc -Wall -o mains main.o libclassrec.a $(Math)

maindloop:  loopd main.o
	gcc -Wall -o maindloop main.o ./libclassloops.so $(Math)

maindrec: recursived main.o
	gcc -Wall -o maindrec main.o ./libclassrec.so $(Math)

all: loops loopd recursives recursived  mains maindloop maindrec


advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc $(CFLAG) advancedClassificationLoop.c -o advancedClassificationLoop.o

basicClassification.o: basicClassification.c
	gcc $(CFLAG) basicClassification.c -o basicClassification.o $(Math)

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc $(CFLAG) advancedClassificationRecursion.c -o advancedClassificationRecursion.o $(Math)

main.o: main.c
	gcc -Wall -c main.c -o main.o $(Math)

clean:
	rm *.o *.so *.a mains maindloop maindrec
