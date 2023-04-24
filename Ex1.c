#include <stdio.h>
#include <stdlib.h>
void sum(){
    int a, b, *p, *q, sum;

   printf("Enter two integers to add\n");
   scanf("%d%d", &a, &b);

   p = &a;
   q = &b;

   sum = *p + *q;

   printf("Sum of the numbers = %d\n", sum);
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int size){
    for (int *p = arr; p < arr + size; p++){
        printf("%d\n", *p);
    }
}

void dynamicArray(){
    int arrSize,temp;
    printf("type in array size: ");
    scanf("%d", &arrSize);
    int *p = (int*) malloc(arrSize*sizeof(int));
    for (int i = 0; i<arrSize; i++){
        scanf("%d",&temp);
        p[i] = temp;
        printf("arr[%d] is %d\n",i, p[i]);
    }
    free(p);
}

void hello(int times){
    for (int i=1; i<=times; i++){   
        printf("%d hello from a pointer!\n",i);
    }
}

int main (){
    // sum();

    // int first = 20, second = 10;
    // int *a = &first, *b = &second;
    // swap(a,b);
    // printf("first = %d, second = %d", *a,*b);

    // int array[] = {1,2,3,4,5,6,7,8};
    // display(array, 8);

    void (*helloPointer)(int) = &hello;
    (*helloPointer)(10);

    // dynamicArray();
    return 0;
}