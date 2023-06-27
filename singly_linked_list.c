//singly linked lists all functions

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}node;

typedef struct list {
    node *head;
    int num_elements;
} list;

list* create_list() {
    list *lst = (list*)malloc(sizeof(list));
    lst->head = NULL;
    lst->num_elements = 0;
    return lst;
}

void add_front(list *lst, int ele) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->next = lst->head;
    lst->head = new_node;
    lst->num_elements++;
}

void add_back(list *lst, int ele) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->next = NULL;
    node *current = lst->head;
    if (lst->head == NULL) {
       lst->head = new_node;
    }  
    else {
        while (current->next != NULL) {
        current = current->next;
        }
        current->next = new_node;
    }
    lst->num_elements++;
}

void insert_after(list *lst, int ele, int key) {
    node *prev = lst->head;
    if(prev==NULL) {
        printf("List is empty.");
        return;
    }
    while(prev!=NULL) {
        if(prev->val == key) {
            node *new_node = (node*)malloc(sizeof(node));
            new_node->val = ele;
            new_node->next = prev->next;
            prev->next = new_node;
            lst->num_elements++;
            return;
        }
        prev = prev->next;
    }
    printf("%d not in the list\n", key);
}

void insert_before(list *lst, int ele, int key) {
    node *prev = lst->head;
    if(prev==NULL) {
        printf("List is empty.");
        return;
    }
    if(key==lst->head->val) {  //same as prev->val. checking if the key is first node
        node *new_node = (node*)malloc(sizeof(node));
        new_node->val = ele;
        new_node->next = lst->head;
        lst->head = new_node;
        lst->num_elements++;
        return;
    }
    while(prev->next != NULL) {
        if(prev->next->val == key) {
            node *new_node = (node*)malloc(sizeof(node));
            new_node->val = ele;
            new_node->next = prev->next;
            prev->next = new_node;
            lst->num_elements++;
            return;
        }
        prev = prev->next;
    }
    printf("%d not in the list\n", key);
}

void insert_at(list *lst, int ele, int pos) {
    node *p = lst->head;
    if(p==NULL) {
        printf("List is empty.");
        return;
    }
    if(pos==1) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->val = ele;
        new_node->next = lst->head;
        lst->head = new_node;
        lst->num_elements++;
        return;
    }
    for(int i=1; i<pos-1 && p!=NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Less than %d elements present in the list\n", pos);
        return;
    } 
    else {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->val = ele;
        new_node->next = p->next;
        p->next = new_node;
        return;
    }
}

int delete_front(list *lst) {
    node *del = lst->head;
    if (lst->head == NULL) {
        printf("There are no elements to delete.");
        return -1;
    }
    int ele = del->val;
    lst->head = del->next;
    free(del);
    lst->num_elements--;
    return ele; 
}

int delete_back(list *lst) {
    node *current = lst->head;
    if (lst->head == NULL) {
        printf("There are no elements to delete.");
        return -1;
    }
    while(current->next->next != NULL) {
        current = current->next;
    }
    node *del = current->next;
    int ele = del->val;
    free(del);
    current->next = NULL;
    lst->num_elements--;
    return ele;
}

void delete_between(list *lst, int key) {
    node *current = lst->head;
    if (lst->head == NULL) {
        printf("There are no elements to delete.");
        return;
    }
    while(current->next != NULL) {
        if(current->next->val == key) {
            node *del = current->next;
            current->next = del->next; //or current->next->next
            free(del);
            lst->num_elements--;
            return;
        }
        current = current->next;
    }
    printf("%d not in the list\n", key);
}

void traversing(list *lst) {
    node *curr = lst->head;
    if(lst->head == NULL) {
        printf("No items in list to display.");
    }
    while(curr != NULL){
        printf("%d  ",curr->val);
        curr = curr->next;
    }
}

int main() {
    list *lst = create_list();
    int ch, ele, del, key;
    for(;;) {
        printf("\n\nMENU\n");
        printf("1. Add to the front of the list\n");
        printf("2. Add to the back of the list\n");
        printf("3. Insert after a given element\n");
        printf("4. Insert before a given element\n");
        printf("5. Insert at a given point\n");
        printf("6. Delete at the front of the list\n");
        printf("7. Delete at the back of the list\n");
        printf("8. Delete a given element\n");
        printf("9. Display the list\n");
        printf("10. View the no.of elements in list\n");
        printf("11. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch) {
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
                printf("enter the element you want to insert to the list : ");
                scanf("%d",&ele);
                printf("enter the key after which you want to insert element : ");
                scanf("%d",&key);
                insert_after(lst, ele, key);
                break;

            case 4:
                printf("enter the element you want to insert to the list : ");
                scanf("%d",&ele);
                printf("enter the key before which you want to insert element : ");
                scanf("%d",&key);
                insert_before(lst, ele, key);
                break;

            case 5:
                printf("enter the element you want to insert to the list : ");
                scanf("%d",&ele);
                printf("enter the position at which you want to insert element : ");
                scanf("%d",&key);
                insert_at(lst, ele, key);
                break;
            
            case 6:
                del = delete_front(lst);
                break;

            case 7:
                del = delete_back(lst);
                break;
                
            case 8:
                printf("enter the element you want to delete : ");
                scanf("%d",&key);
                delete_between(lst, key);
                break;

            case 9:
                traversing(lst);
                break;

            case 10: 
                printf("The no.of elements is : %d",lst->num_elements);
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice.");
        } 
    }
}