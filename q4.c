#include<stdio.h>
#include<string.h>

void show_arr(int arr[],int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d ",arr[i]); 
    }
    printf("\n");
}

void push(int stack[],int *top,int max){
    int num;

    if(*top < max){
        printf("enter element to enter in the stack: ");
        scanf("%d",&num);
        stack[*top] = num;
        (*top)++;
        printf("Element %d pushed onto the stack.\n", num);
    }
    else{
        printf("max limit reached, no space left in the stack.\n");
    }
}

void pop(int stack[],int *top){
    if(*top > 0){
        (*top)--; 
        printf("element %d popped.\n", stack[*top]); 
    }
    else{
        printf("no data present in the stack (stack is empty)!\n");
    }
}

void peek(int stack[],int *top){
    if(*top > 0){
        printf("%d is the top element entered in the stack\n",stack[*top-1]);
    }
    else{
        printf("no data found to display (stack is empty)\n");
    }
}

int main(){

    int size = 10; 
    int arr[size];
    int count = 0; 
    int opt; 

    do
    { 
        printf("\n==== Stack Menu ====\n");
        printf("1. Push\n");
        printf("2. Pop \n");
        printf("3. Peek\n");
        printf("4. Display (partial)\n"); 
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &opt) != 1) { 
            while (getchar() != '\n'); 
            opt = -1; 
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch(opt){
            case 1:
            push(arr, &count, size); 
            break;
            case 2:
            pop(arr, &count);
            break;
            case 3:
            peek(arr, &count);
            break;
            case 4:
            printf("Stack elements (Top to Bottom):\n");
            show_arr(arr, count); 
            break;
            case 5:
            printf("Exiting ....\n");
            break;
            default:
            printf("Invalid option. Please choose between 1 and 5.\n");
            break;
        }
    } while (opt != 5);

    return 0;
}