all : merge

merge : merge.o main.o merge_improve.o
	gcc -o merge  merge.o merge_improve.o main.o

merge.o : merge.c merge.h
	gcc -c -o merge.o merge.c

merge_improve.o : merge_improve.c merge.h
	gcc -c -o merge_improve.o merge_improve.c

main.o : main.c merge.h
	gcc -c -o main.o main.c

clean :
	rm *.o merge