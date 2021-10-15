#include <stdio.h>
#include <stdlib.h>

void Divisor(int x) {

  if (x%2==0) {
    printf("%d is divisible by 2\n",x);
  }
  else if (x%3==0)
  {
    printf("%d is divisible by 3\n",x);
  }
  else if (x%6==0)
  {
        printf("%d is divisible by 6\n",x);

  }
  else {
    printf("%d is not divisible by 2 or 3 or 6\n",x);
  }
  
  
}

void main()
{
   int x = 0;


   printf("x = ");
   scanf("%d",&x);

   Divisor(x);

}

