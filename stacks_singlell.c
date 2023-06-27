#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}node;

typedef struct list {
    node *head;
    int top;
} list;

list* create_list() {
    list *lst = (list*)malloc(sizeof(list));
    lst->head = NULL;
    lst->top = -1;
    return lst;
}

void push(list *lst, int ele) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->next = lst->head;
    lst->head = new_node;
    lst->top++;
}
 
int pop(list *lst) {
    node *del = lst->head;
    if (lst->head == NULL) {
        return -1;
    }
    int ele = del->val;
    lst->head = del->next;
    free(del);
    lst->top--;
    return ele; 
}

void display(list *lst) {
    node *curr = lst->head;
    if(lst->head == NULL) {
        printf("No items in list to display.");
        return;
    }
    printf("Stack items : \n");
    while(curr != NULL){
        printf("%d\n",curr->val);
        curr = curr->next;
    }
}

int main(void)
{
    list *lst = create_list();
    int choice, del, ele; 
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
                printf("enter the element you want to push into the stack : ");
                scanf("%d",&ele);
                push(lst, ele);
                break;
            
            case 2 :
                del = pop(lst);
                if (del==-1)
                {
                    printf("Stack Underflow\n");
                }
                else
                {
                    printf("Popped element is %d\n", del);
                }
                break;

            case 3 :
                display(lst);
                break;

            case 4 :
                printf("top element is : %d", lst->head->val);
                break;

            case 5 :
                exit(0);

            default :
                printf("Invalid choice\n");
        }
    }
}
