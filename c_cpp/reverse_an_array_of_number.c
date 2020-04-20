/* ****************************************************************** */
/* Reverse any array function                                         */
/*                                                                    */
/* reverse_an_array_of_number.c                                       */
/* Created 13.01.2020 by shennguyenrs                                 */
/*                                                                    */
/* ****************************************************************** */


#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *arr, int n) {
  printf("The reversal of the array is: ");
  for (int i=n-1; i>=0; i--) {
    printf("%d ", *(arr+i));
  }
}

int main(void) {
  int n, *arr;

  printf("Enter the amount of number in array: ");
  scanf("%d", &n);

  arr = (int*)malloc(n*sizeof(int));
  
  printf("Enter %d interger numbers seperated by space: ", n);
  for (int i=0; i<n; i++) {
    scanf("%d", arr+i);
  }
  
  reverse_array(arr, n);

  free(arr);

  return 0;
}
