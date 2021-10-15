#include <stdio.h>
#include <stdlib.h>

int Rounding(double x) {
   // 5.6 will be 5
   int n = x;
   printf("n=%d\n",n);
   // x is btn 5 and 6
   int n_plus_1 = n + 1;
   printf("n+1 = %d\n",n_plus_1);
   // mid is 5.5
   double n_mid = (double)(n + n_plus_1)/2;
   printf("n_mid = %f\n",n_mid);

   //test if x<mid
   if (x < n_mid) {
      return n;
   }
   else {
      return n_plus_1;
   }  
}


void main() {
   double x;
   //=======================================
   printf("Enter a real number, x: ");
   scanf("%lf", &x);
   //====================================

   int result = Rounding(x);
   printf("%f is rounded to %d\n",x,result);

}