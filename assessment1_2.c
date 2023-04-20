/* Stack implementation using arrays
Input needs to be your USN number. Each character of the USN should be an element in the stack. 
USN has both alphabets and numbers which is usually referred to as “alphanumeric”. This simply means you can treat those numbers also as characters. */

//Name - Reethu RG Thota
//USN - 1RVU22CSE128

#include <stdio.h>
#include <stdlib.h>
#define size 12

int choice, top=-1;
char del;
char usn[12] = {'1','R','V','U','2','2','C','S','E','1','2','8'};
char myStack[size];
static int i=0;

void display();

void push()
{
    char ele;
    if(top == size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        for(; i<12;)
        {
            ele = usn[i];
            i++;
            break;
        }
        top++;
        myStack[top]=ele;
        display();
    }
}

char pop()
{
    if (top==-1)
    {
        del = -1;
        return del;
    }
    else
    {
        char popped_element = myStack[top];
        top--;
        return popped_element;
    }
}

void display()
{
    if (top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("\nStack elements : \n");
        for(int i=top; i>=0; i--)
        {
            printf("%c\n",myStack[i]);
        }
    }
}

void peek()
{
    if (top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Top element is : %c\n", myStack[top]);
    }
}

int main(void)
{
    for(;;)
    {
        printf("\n\nEnter your choice :\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Peek\n");
        printf("5.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                push();
                break;
            
            case 2 :
                del = pop();
                if (del==-1)
                {
                    printf("Stack Underflow\n");
                }
                else
                {
                    printf("Popped element is %c\n", del);
                    display();
                }
                break;

            case 3 :
                display();
                break;

            case 4 :
                peek();
                break;

            case 5 :
                exit(0);

            default :
                printf("Invalid choice\n");
        }
    }
}