#include <stdlib.h>		// for exit
#include "bool.h"
#include "errExit.h"
#include <setjmp.h> // for setjmp and longjmp
#include <stdio.h> // printf

static jmp_buf env; // this needs to be global so that it is always in scope. Contains the state for the jump.

void function(void) {
	switch (setjmp(env)) {
		case 0: // initial setjmp
			printf("Jump Set\n");
			break;
		default:
			printf("Jumped to the function\n");
	}

	// do some more stuff
	printf("hello world\n");
}

void function2(void) {
	// function to take up space on the stack
	int a, b, c, d, e, f, g, h, i;
	printf("In function2, got %li\n", (long)(a + b + c + d + e + f + g + h + i));
}

int main(int argc, char* argv[])
{
	function();
	printf("Function has run blah blah...\n");
	function2();

	longjmp(env, 1); // try a nonlocal goto the returned function

	exit(EXIT_SUCCESS);
}
