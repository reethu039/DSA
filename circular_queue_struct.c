//circular queue array of structure implementation


#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

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

    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
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

        if(rear == SIZE-1 && front != 0) 
        {
            myQueue[++rear] = ele;
            printf("Inserted %d Successfully!\n", myQueue[rear]);
        }
    }  
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Circular Queue is Empty.\n");
    }
    else
    {
        del = myQueue[front++];
        printf("Deleted element is : %d\n",del);
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
            printf("%s ,%f, %d\n",myQueue[i].name, myQueue[i].price, myQueue[i].quantity);
            }  
        }
        else
        {
            for (i = 0;i <= rear; i++) 
            printf("%s ,%f, %d\n",myQueue[i].name, myQueue[i].price, myQueue[i].quantity);
            
            for (i = front;i <= SIZE - 1; i++) 
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