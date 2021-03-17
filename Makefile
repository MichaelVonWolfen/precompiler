all:
    build
build:
    gcc main.c -o main.o
clean:
    rm -r *.o
