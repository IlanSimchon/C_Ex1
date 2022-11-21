loops:   basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

loopd: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

mains: recursives main.o
	gcc -Wall -o mains main.o libclassrec.a -lm

maindloop:  loopd main.o
	gcc -Wall -o maindloop main.o ./libclassloops.so -lm

maindrec: recursived main.o
	gcc -Wall -o maindrec main.o ./libclassrec.so -lm

all: loops recursives recursived loopd mains maindloop maindrec

clean:
	rm *.o *.so *.a mains maindloop maindrec

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -Wall -fPIC -c advancedClassificationLoop.c -o advancedClassificationLoop.o

basicClassification.o: basicClassification.c
	gcc -Wall -fPIC -c basicClassification.c -o basicClassification.o -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -Wall -fPIC -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o -lm

main.o: main.c
	gcc -Wall -c main.c -o main.o -lm