#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max_size 20
void push(int element, int *head, int stack[]){
    *head = *head + 1;
    stack[*head] = element;
}
int pop(int *head, int stack[]){
    int element;
    element = stack[*head];
    *head = *head - 1;
    return element;
}
void control_the_stack(int *head, int stack[]){
    if (*head>0) {
        if (stack[*head] != stack[ *head -1]) {
            pop(head, stack);
            pop(head, stack);
        }
    }
}
int main(int argc, const char * argv[]) {
    int stack[max_size];
    int i,n,size,head;
    char *arr;
    float m;
    head = -1;
    printf("Bir sayi giriniz.\n");
    scanf(" %d", &n);
    m = n;
    size = logf(m)/logf(2.0);
    size = size/8 + 1;
    arr = (char*)calloc(size*8, sizeof(char));
    for(i=0;n>0;i++){
        arr[size*8-i-1]=n%2;
        n=n/2;
    }
    
    for (i=0; i<size*8; i++) {
        printf("%d", arr[i]);
        push(arr[i], &head, stack);
        control_the_stack(&head, stack);
    }
    printf("\n");
    if (head == -1) {
        printf("0 ve 1'ler esit sayidadir.\n");
    }else {
        if (stack[head] == 1) {
            i = 0;
        }else{
            i = 1;
        }
        printf("%d'ler fazladir. Ek %d adet %d gereklidir.\n", stack[head], head+1, i);
    }
    
    
    return 0;
}

