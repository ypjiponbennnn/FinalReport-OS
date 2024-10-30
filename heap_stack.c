#include <stdio.h>
#include <stdlib.h>

int global1 = 1;
int global2 = 2;
int global3 = 3;

// Local variable in function on stack
void func3(int x) {
    int local3 = x; 
    printf("[Function3] local3 address : %p\n", (void*)&local3);
}

void func2(int x) {
    int local2 = x; 
    printf("[Function2] local2 address : %p\n", (void*)&local2);
    func3(x + 1);
}

void func1(int x) {
    int local1 = x; 
    printf("[Function1] local1 address : %p\n", (void*)&local1);
    func2(x + 1);
}

int main() {
    // Call function
    func1(1);
    printf("\n");

    // Allocating memory on heap 
    int *heap1 = (int *)malloc(sizeof(int));
    int *heap2 = (int *)malloc(sizeof(int));
    int *heap3 = (int *)malloc(sizeof(int));
    printf("heap1 address : %p\n", (void*)heap1);
    printf("heap2 address : %p\n", (void*)heap2);
    printf("heap3 address : %p\n", (void*)heap3);
    printf("\n");
    // Don't forget to free allocated memory
    free(heap1);
    free(heap2);
    free(heap3);

    // Print address of global variables
    printf("global1 address : %p\n", (void*)&global1);
    printf("global2 address : %p\n", (void*)&global2);
    printf("global3 address : %p\n", (void*)&global3);
    
    return 0;
}
