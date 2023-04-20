//linear queue array of structure implementation

#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct myShop
{
    char name[15]; 
    float price;
    int quantity;
} shop;

int ele, front = -1, rear = -1;
shop del, myQueue[5];


void enqueue()
{
    shop ele;

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

        printf("Enter item name : ");
        scanf("%s", ele.name);
        printf("Enter item price : ");
        scanf("%f", &ele.price);
        printf("Enter item quantity : ");
        scanf("%d", &ele.quantity);

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
        del = myQueue[front++];
        printf("Element deleted from queue is %s, %f, %d\n", del.name, del.price, del.quantity);
        
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
            printf("%s ,%f, %d\n",myQueue[i].name, myQueue[i].price, myQueue[i].quantity);
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