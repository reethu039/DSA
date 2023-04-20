//linear queue implementation or arrays

#include <stdio.h>
#include <stdlib.h>
#define size 5

int ele, front = -1, rear = -1;
int myQueue[5];

void enqueue()
{
    if(rear == size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }

        printf("Enter element to be enqueued : ");
        scanf("%d",&ele);
        myQueue[++rear] = ele;
    }
}

void dequeue()
{
   if((front == -1) || (front > rear))
    {
        printf("Queue empty! canot dequeue\n");
    }
    else
    {
        ele = myQueue[front++];
        printf("Element %d in %d position(front) of queue deleted\n", ele ,front-1);

        if(front == rear+1)
        {
            front = -1;
            rear =-1;
        }
    }
}

void display()
{
    if((front == -1) || (front > rear))
    {
        printf("Queue empty! canot display\n");
    }
    else
    {
        printf("Displaying Queue Elements : \n");
        for(int i = front; i<=rear; i++)
        {
            printf("%d\n", myQueue[i]);
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