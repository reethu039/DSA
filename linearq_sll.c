#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}node;

typedef struct list {
    node *head;
    int front;
    int rear;
} list;

list* create_list() {
    list *lst = (list*)malloc(sizeof(list));
    lst->head = NULL;
    lst->front = -1;
    lst->rear = -1;
    return lst;
}

void enqueue(list *lst, int ele) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->next = lst->head;
    lst->head = new_node;
    lst->rear++;
    if(lst->front == 0) {
        lst->front++;
    }
}

int dequeue(list *lst) {
    if((lst->front == -1) || (lst->front > lst->rear)) {
        printf("Queue empty! canot dequeue\n");
        return -1;
    }
    node *del = lst->head;
    if (lst->head == NULL) {
        return -1;
    }
    int ele = del->val;
    lst->head = del->next;
    free(del);
    lst->front++;
    if(lst->front == lst->rear+1)
    {
        lst->front = -1;
        lst->rear =-1;
    }
    return ele;     
}

void display(list *lst) {
    node *curr = lst->head;
    if(lst->head == NULL) {
        printf("No items in list to display.");
        return;
    }
    printf("Queue items : \n");
    while(curr != NULL){
        printf("%d\n",curr->val);
        curr = curr->next;
    }
}

int main()
{
    list *lst = create_list();
    int choice, del, ele;
    for(;;)
    {
        printf("\n\nEnter choice :\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                printf("Enter element to be enqueued : ");
                scanf("%d",&ele);
                enqueue(lst, ele);
                break;
            
            case 2 :
                dequeue(lst);
                break;
            
            case 3 :
                display(lst);
                break;
            
            case 4 :
                exit(0);
            default :
                printf("Invalid choice\n");
        }
    }
}