/* Declaration of a function pointer
============================================================================
<return type> (*pointer)(<input>); --> declares a pointer to a function with input parameter and return type.
 */

// Elementary example
#include <stdio.h>

void output1 (char* string){
    printf("*%s*\n", string);
}

void output2 (char* string){
    printf("#%s#\n", string);
}

void main(){
    char string[] = "Hello World";
    void (*output) (char* string);
    output = output1;
    output(string);

    output = output2;
    output(string);
}