/*
Address has been used so many times in our code. 
scanf("%d",&var);
The &var points to the address of var in memory
------------------------------------------------------------------*/

// #include <stdio.h>
// int main()
// {
//   int var = 5;
//   printf("var: %d\n", var);

//   // Notice the use of & before var
//   printf("address of var: %p\n", &var);  
//   return 0;
// }

//=========================================================================================

/*
C pointers

Pointers are special variables that stores the address of a variable rather than the value of the variable.

pointer declaration --> <type>* <name>;
Example int* p;
int* p,p2; --> means p is a pointer but p2 is a normal int variable.

note that we use '&' to assign address of a variable to a pointer.
----------------------------------------------------------
*/




 #include <stdio.h>

// void main() {
  // to get the value of the variable stored in the address pointed by pc we used *(dereference operator)
  //to precede the pointer variable pc.

  //   int* pc, c;
  //   c = 5;
  //   pc = &c;
  //   printf("%d\n", *pc);
// }

// void main() {
//   int* pc, c;
//   c = 5;
//   pc = &c;
//   printf("c = %d\n",c);
//   *pc =1;
//   printf("After assigning 1 to *pc\n");
//   printf("c = %d\n",c);
  
// }



// void main() {
//   int * pc, c, d;
//   c = 5;
//   d = -15;
//   pc = &c;
//   printf("*pc = %d\n", *pc);
//   pc = &d;
//   printf("*pc = %d\n", *pc);
// }


int main()
{
   int* pc, c;
   
   c = 22;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);  // 22
   
   pc = &c;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); // 22
   
   c = 11;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); // 11
   
   *pc = 2;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c); // 2
   return 0;
}




















