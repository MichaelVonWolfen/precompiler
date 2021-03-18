all:go save

go: ;gcc -o main.o main.c;
save:; scp main.o student@192.168.34.129:/home/student/so-assignments/1-multi/checker/multi/so-cpp
run: ;./main.o

clean: ;rm -f main.o;