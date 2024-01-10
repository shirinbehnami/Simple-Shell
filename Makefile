all: parser.o execFunc.o builtInCmd.o shell.o
	gcc parser.o execFunc.o builtInCmd.o shell.o -I./include/ -lreadline -o shell

shell.o:
	gcc -I./include/ -c -lreadline ./src/shell.c 

parser.o:
	gcc -I./include/ -c -lreadline ./src/parser.c

execFunc.o:
	gcc -I./include/ -c -lreadline ./src/execFunc.c

builtInCmd.o:
	gcc -I./include/ -c -lreadline ./src/builtInCmd.c

clean:
	rm *.o