all:go test

remote: go save

go: ;gcc -o main main.c;
save:; scp main student@192.168.34.129:/home/student/so-assignments/1-multi/checker/multi/so-cpp
test: ;
		./main -D TESTARE=1
		./main -D PLA
		./main -D Testare=1 -D PULA=0

clean: ;rm -f main.o;