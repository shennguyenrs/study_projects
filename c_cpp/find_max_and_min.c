/* ****************************************************************** */
/* Find the maxium and minium number in the array                     */
/*                                                                    */
/* find_max_and_min.c                                                 */
/* Created 13.01.2020 by shennguyenrs                                 */
/*                                                                    */
/* ****************************************************************** */


#include <stdio.h>
#include <stdlib.h>

void max(int *arr, int n) {
  int flag = *(arr+0);
  for (int i=1; i<n; i++) {
    if (flag < *(arr+i)) {
      flag = *(arr+i);
    }
  }
  printf("The maxium number of the array is: %d\n", flag);
}

void min(int *arr, int n) {
  int flag = *(arr+0);
  for (int i=1; i<n; i++) {
    if (flag > *(arr+i)) {
      flag = *(arr+i);
    }
  }
  printf("The minium number of the array is: %d\n", flag);
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

  printf("\n");
  max(arr, n);
  min(arr, n);

  free(arr);

  return 0;
}
