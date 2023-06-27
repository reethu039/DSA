#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *lchild;
    struct node *rchild;
}node;

node* create_node(int ele) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}
 
node* insert_recurse(node *parent, int ele) {
    if (parent==NULL) {
        parent = create_node(ele);
    } else if(ele < parent->val) {
        parent->lchild = insert_recurse(parent->lchild, ele);
    } else if(ele > parent->val) {
        parent->rchild = insert_recurse(parent->rchild, ele);
    } else {
        printf("Already in the tree\n");
    }
    return parent;
}

void preorder(node *n) {
    if(n==NULL) {
        return;
    }
    printf("%d\n",n->val);
    preorder(n->lchild);
    preorder(n->rchild);
}

void inorder(node *n) {
    if(n == NULL){ 
        return;
    }
    inorder(n->lchild);
    printf("%d\n", n->val);
    inorder(n->rchild);
}

void postorder(node *n) {
    if(n==NULL) {
        return;
    }
    postorder(n->lchild);
    postorder(n->rchild);
    printf("%d\n",n->val);
}

void search(node* root, int key)
{
    if(root == NULL) {
        printf("NOT FOUND");
        return;
    }
    if (root->val == key){
        printf("FOUND\n");
        return;
    }
    if (key > root->val) {
        printf("right\n");
        search(root->rchild, key);   
    }
    if(key < root->val) {
        printf("left\n");
        search(root->lchild, key);
    }
}

void min_element(node *p) {
    if(p->lchild == NULL) {
        printf("\nThe minimum element is %d\n", p->val);
        return;
    }
    min_element(p->lchild);
}

void max_element(node *p) {
    if(p->rchild == NULL) {
        printf("\nThe maximum element is %d\n", p->val);
        return;
    }
    max_element(p->rchild);
}

int main() {     
    node* root = NULL;
    int ch, ele, key;
    for(;;) {
        printf("\n\nMENU\n");
        printf("1. Add to the tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search for an element in the tree\n");
        printf("6. Minimum element in the tree\n");
        printf("7. Maximum element in the tree\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch) {
            case 1 : 
                printf("enter element to add to tree : ");
                scanf("%d",&ele);
                root = insert_recurse(root, ele);
                break;
            
            case 2 :
                if(root==NULL) {
                    printf("\nTree is empty! Enter elements to traverse\n");
                    break;
                }
                printf("preorder\n");
                preorder(root);
                break;

            case 3 :
                if(root==NULL) {
                    printf("\nTree is empty! Enter elements to traverse\n");
                    break;
                }
                printf("inorder\n");
                inorder(root);
                break;

            case 4 :
                if(root==NULL) {
                    printf("\nTree is empty! Enter elements to traverse\n");
                    break;
                }
                printf("postorder\n");
                postorder(root);
                break;

            case 5 :
                if(root==NULL) {
                    printf("\nTree is empty! Enter elements to search\n");
                    break;
                }
                printf("enter the element to search for : ");
                scanf("%d",&key);
                search(root, key);
                break;

            case 6 : 
                min_element(root);
                break;

            case 7 :
                max_element(root);
                break;

            case 8 :
                exit(0);
                 
            default :
                printf("Invalid choice\n");
        }
    }
}

/*
 void insert_iteration(node *root, int ele) {
    node *child, *parent;
    child = root;
    parent = NULL;
    while(child!=NULL) {
        parent = child;
        if(ele < child->val) {
            child = child->lchild;
        } 
        else if(ele > child->val) {
            child = child->rchild;
        }
        else {
            printf("Already in the tree\n");
            return;
        }
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = ele;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    if(parent == NULL) {
        root = new_node; 
    }
    else if(ele < child->val) {
            parent->lchild = new_node;
    } 
    else if(ele > child->val) {
            parent->rchild = new_node;
    }
}
 */

/*
node *search_iterative(struct node *p, int key) {
    while(p!=NULL) {
        if(key < p->val) {
            p = p->lchild;
        }
        else if (key > p->val) {
            p = p->rchild;
        }
        else {
            return p;
        }
    }
    return NULL;
}
*/

/*
node *search(node *p, int key) {
    if(p==NULL) {
        return NULL;
    }
    if(key < p->val) {
        return search(p->lchild, key);
    }
    if(key > p->val) {
        return search(p->rchild, key);
    }
    return p;
}
*/