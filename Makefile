all:go test clean

remote: go save clean

go:
	gcc -o main main.c;
save:
	scp main student@192.168.34.129:/home/student/so-assignments/1-multi/checker/multi/so-cpp
test:
#	./main -D TESTARE=1
#	./main -D PLA
#	./main -D Testare=1 -D PULA=0
#	./main -Dtest=3
#	./main -Dtest4=0 -I ./incl1 -Iincl2 -Iincl3 -I incl4 -Dtest41=2
#	./main -I ./incl1 -Iincl2 -Iincl3 -I incl4
	./main -o test.o -I in -Ii -Dt=0 -D o
	./main -X Bad param

clean:
	rm -f main;