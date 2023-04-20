#include<stdio.h>
#include <stdlib.h>
#define SIZE 5

int myQueue[SIZE]; 
int front = -1, rear = -1, ele;

void enqueue()
{
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter the value to be inserted:  ");
        scanf("%d",&ele);
        if(rear == SIZE-1 && front != 0) 
        
        myQueue[++rear] = ele;
        printf("Inserted %d Successfully!\n", myQueue[rear]);
        
        if(front == -1)
        {
            front = 0;
        } 
    }  
}

void dequeue()
{
    if(front == -1 && rear == -1)
    printf("Circular Queue is Empty.\n");
    else
    {
        ele = myQueue[front++];
        printf("Deleted element is : %d\n",ele);
        if(front-1 == rear)
        {
            front = rear = -1;
        }
        
        if(front == SIZE)
        {
            front = 0;
        }    
    }
}

void display()
{
    if(front == -1)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        int i;
        printf("Circular Queue Elements are : \n");
        if(front <= rear)
        {
            for (i=front; i <= rear; i++)
            {
                printf("%d\t",myQueue[i]);
            }  
        }
        else
        {
            for (i = 0;i <= rear; i++) 
            printf("%d\t",myQueue[i]);
            
            for (i = front;i <= SIZE - 1; i++) 
            printf("%d\t", myQueue[i]);
            
        }
    }
}

int main()
{
    int choice, del;
    for(;;)
    {
        printf("Enter choice :\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                enqueue();
                break;
            
            case 2 :
                dequeue();
                break;
            
            case 3 :
                display();
                break;
            
            case 4 :
                exit(0);
            default :
                printf("Invalid choice\n");
        }
    }
}