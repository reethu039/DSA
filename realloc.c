#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int num_elems;

  printf("\nHow many elements do you want to enter? ");
  scanf("%d", &num_elems); 
  printf("\n\n******************First Malloc **************************************"); 
  // If malloc is not able to allot - you will get a segmentation fault
  int *imallocarray1 = (int *)malloc(num_elems * sizeof(int) );

  if (imallocarray1 == NULL) 
  {
    printf("\n%d bytes could not be allotted by the first malloc", num_elems * sizeof(int) );
  } 
  else 
  {
    printf("\n%d bytes allotted", num_elems * sizeof(int) );
  }
  
  //for (int i = 0; i < num_elems; i++) imallocarray1[i] = 2*i; 
  for (int i = 0; i < num_elems; i++) 
  {
    printf("\n%d is the %dth element at address %p", imallocarray1[i], i, &imallocarray1[i]);
  }
  
  
  printf("\n\n********************Second Malloc************************************"); 
  
  int *imallocarray2 = (int *)malloc(num_elems * sizeof(int) );
  if (imallocarray2 == NULL) 
  {
    printf("\n%d bytes could not be allotted by the second malloc", num_elems);
  } 
  else 
  {
    printf("\n%d bytes allotted", num_elems * sizeof(int) );
  }
  
  //for (int i = 0; i < num_elems; i++) imallocarray2[i] = 3*i; 
  for (int i = 0; i < num_elems; i++) 
  {
    printf("\n%d is the %dth element at address %p", imallocarray2[i], i, &imallocarray2[i]);
  }
  
  printf("\n\n*************************Realloc Usage*******************************"); 
  printf("\nReallocating using the first malloc pointer"); 
  
  int *ireallocarray2 = (int *)realloc(imallocarray1, sizeof(int) * 2*num_elems);

  if (ireallocarray2 == NULL) 
  {
    printf( "\n\n%d bytes could not be allotted by realloc", sizeof(int) * 2*num_elems);
  } 
  else 
  {
    printf("\n%d bytes allotted", 2*num_elems * sizeof(int));
  }
  
  for (int i = 0; i < 2*num_elems; i++) 
  {
    printf("\n%d is the %dth element at address %p", ireallocarray2[i], i, &ireallocarray2[i]);
  }
  
  printf("\n\n****Reallocating using compile time array pointer- FAIL Case - ABORTED CORE DUMP RunTime Error***"); 
  printf("\n\n****REALLOC - FAIL Case - *********************\n"); 
  int arr[10];
  int *iarray = (int *)realloc(arr, 25);
  
}