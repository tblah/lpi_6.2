OUTPUT_NAME=longjump
COMPILE_OPTS= -g -Wall

all: bool.h errExit.o errExit.h main.c
	cc $(COMPILE_OPTS) -o $(OUTPUT_NAME) bool.h errExit.o main.c

# an alias to make me happy (keep the line below with the tab intact)
errExit: errExit.o


errExit.o: errExit.c errExit.h
	cc $(COMPILE_OPTS) -c -o errExit.o errExit.c

clean:
	rm $(OUTPUT_NAME) *.o
