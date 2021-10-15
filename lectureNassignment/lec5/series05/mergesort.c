#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int len);

int* slice(int *arr, int start, int end);

void merge(int *result, int *left, int *right, int leftLen, int rightLen);

void printArray(int* arr, int len);

int main()
{
    int i = 0, x[] = {-2,10,8,3,5,-1,4,0,1,15};
    int n = sizeof(x)/sizeof(x[0]);

    mergeSort(x, n);
    printArray(x,n);
    
}

void mergeSort(int *x, int n)
{
    if (n <= 1)
    {
        return;
    }
    
    int *left = slice(x, 0, n / 2 + 1);
    int *right = slice(x, n / 2, n);

    printf("left: ");
    printArray(left, n / 2);
    printf("right: ");
    printArray(right, n - (n / 2));
 
    mergeSort(left, n / 2);
    mergeSort(right, n - (n / 2));

    merge(x, left, right, n / 2, n - (n / 2));
}

int* slice(int *arr, int start, int end)
{
    int *result = (int *) malloc((end - start) * sizeof(int));
    int i;
    for (i = start; i < end; i++)
    {
        result[i - start] = arr[i];
    }
    return result;
}

void merge(int *result, int *left, int *right, int leftLen, int rightLen)
{
    int i = 0, j = 0;

    while(i < leftLen && j < rightLen)
    {
        
        if (left[i] < right[j])
        {
            result[i + j] = left[i];
            i++;
        }
        else
        {
            result[i + j] = right[j];
            j++;
        }
    }

    for(; i < leftLen; i++)
    {
        result[i + j] = left[i];
    }
    for(; j < rightLen; j++)
    {
        result[i + j] = right[j];
    }

    free(left);
    free(right);
}

void printArray(int* arr, int len)
{
    int i = 0;
    printf("[");
    for(; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

// time complixity nlog(n)