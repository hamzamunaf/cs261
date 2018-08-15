#include "worksheet14.h"

int main() { 
  struct DynArr arr; 
  initDynArr(&arr, 50);
  addDynArr(&arr,1);
  addDynArr(&arr,3);
  addDynArr(&arr,6);
  addDynArr(&arr,4);
  addDynArr(&arr,1);
  putDynArr(&arr,1,21);
  removeAtDynArr(&arr,3);
  for (int i=0;i<arr.size;i++){
    printf("%d \n",arr.data[i]);
  }
  
}