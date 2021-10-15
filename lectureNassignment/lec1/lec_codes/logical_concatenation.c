#include <stdio.h>
/* True = 1 and False = 0*/

int main() {
    /*Declaration*/
    int result=0, a = 3, b=2, c=1;
    /*(a>b)=true=1 > c = false*/
    result = (a>b>c);
    printf("a) result=%d\n",result);

    /*(a>b=true=1) && (b>c=true=1) = true*/
    int result2 = (a>b) && (b>c);
    printf("b) result2=%d\n",result2);
    
}