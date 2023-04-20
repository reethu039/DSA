#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int num_elements;
    printf("\nHow many elements do you want to enter? ");
    scanf("%d", &num_elements);

    int *iarray = (int *)calloc(num_elements, sizeof(int));
    printf("\nBytes allocated is %d", sizeof(iarray) ); 
    printf("\nCALLOC initializes elements to ZERO");

    for (int i=0; i<num_elements; i++) 
    {
        printf("%p\n",iarray);
    }

    printf("\nEnter the array elements: ");
    for (int i = 0; i < num_elements; i++) 
    {
        printf("\nEnter the %dth element: ", i);
        scanf("%d", &iarray[i]);
    } 
    printf("\n ");
    
    printf("\nDisplay the array elements");
    for (int i = 0; i < num_elements; i++) 
    {
        printf("\nElement at %d is %d", i, iarray[i]);
        printf("\nAddress of %dth element is %p", i, &iarray[i]);
    }
}