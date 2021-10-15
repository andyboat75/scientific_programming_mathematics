#include <stdio.h>

int ScalarProduct(double u[], double v[],int size){
    double results;
    int i=0;
    while (i<size) {
        results += u[i] *v[i];
        ++i;
    }
    return results;
}



void main() {
    int i;
    int size;
    printf("Enter the dimension of u and v: ");
    scanf("%d",&size);;

    double u[size];
    double v[size];

    for (i=0; i<size; ++i){
        printf("Enter the %d value of u: ", i+1);
        scanf("%lf",&u[i]);

        printf("Enter the %d value of v: ", i+1);
        scanf("%lf",&v[i]);
    }

    int ans = ScalarProduct(u,v,size);
    printf("The scalar product of the vector is %d\n",ans);

}