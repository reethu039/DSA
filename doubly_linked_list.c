#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
}node;

typedef struct list {
    node *head;
    node *tail;
    int num_elements;
}list;

list* create_list() {
    list *lst = (list*)malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;
    lst->num_elements = 0;
    return lst;
}

void add_front(list *lst, int ele) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->next = lst->head;
    new_node->prev = NULL;
    if(lst->head==NULL) {
        lst->tail = new_node;
    }
    else {
        lst->head->prev = new_node;
    }
    lst->head = new_node;
    lst->num_elements++;
    return;
}

void add_back(list *lst, int ele) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->next = NULL;
    new_node->prev = lst->tail;
    if(lst->head == NULL) {
        lst->head = new_node;
        lst->tail = new_node;
    }
    else {
        lst->tail->next = new_node;
        lst->tail = new_node;
    }
    lst->num_elements++;
    return;
}

int delete_front(list *lst) {
    if (lst->num_elements == 0) {
        printf("List is empty.");
        return -1;
    }
    int ele = lst->head->val;
    node *del = lst->head;
    if(lst->num_elements==1) {
        lst->head = NULL;
        lst->tail = NULL;
    }
    else {
        lst->head = lst->head->next;
        lst->head->prev = NULL;
    }
    free(del);
    lst->num_elements--;
    return ele;
}

int delete_back(list *lst) {
    if (lst->num_elements == 0) {
        printf("List is empty.");
        return -1;
    }
    int ele = lst->tail->val;
    node *del = lst->tail;
    if(lst->num_elements==1) {
        lst->head = NULL;
        lst->tail = NULL;
    }
    else {
        lst->tail = lst->tail->prev;
        lst->tail->next = NULL;
    }
    free(del);
    lst->num_elements--;
    return ele;
}

void traversing_front(list *lst) {
    printf("List from the front:\n");
    if (lst->num_elements==0) {
        printf("List is empty.");
        return;
    }
    node *new_node = lst->head;
    printf("%d  ", new_node->val);
    while(new_node!=NULL && new_node->next!=NULL) { 
        new_node = new_node->next;
        printf("%d  ", new_node->val);
    }
}

void traversing_back(list *lst) {
    printf("List from the back:\n");
    if (lst->num_elements==0) {
    printf("List is empty.");
    return;
    }
    node *new_node = lst->tail;
    printf("%d  ", new_node->val);
    while (new_node!=NULL && new_node->prev!=NULL) {
        new_node = new_node->prev;
        printf("%d  ", new_node->val);
    }
}

int main() {
    list *lst = create_list();
    int ch, ele, del, key;
    for(;;) {
        printf("\n\nMENU\n");
        printf("1. Add to the front of the list\n");
        printf("2. Add to the back of the list\n");
        printf("3. Delete at the front of the list\n");
        printf("4. Delete at the back of the list\n");
        printf("5. Display the list front - back\n");
        printf("6. Display the list back - front\n");
        printf("7. View the no.of elements in list\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("enter the element you want to add to the list : ");
                scanf("%d",&ele);
                add_front(lst, ele);
                break;

            case 2:
                printf("enter the element you want to add to the list : ");
                scanf("%d",&ele);
                add_back(lst, ele);
                break;
            
            case 3:
                del = delete_front(lst);
                break;

            case 4:
                del = delete_back(lst);
                break;
            
            case 5:
                traversing_front(lst);
                break;
            
            case 6:
                traversing_back(lst);
                break;
            
            case 7: 
                printf("The no.of elements is : %d",lst->num_elements);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice.");
        }
    }
} 
