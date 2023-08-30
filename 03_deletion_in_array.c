#include<stdio.h>
void delete(int size,int place,int arr[]){
    for(int i=place-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
}
void printarr(int size,int arr[]){
    for(int i=0;i<size;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[10]={1,2,3,4,5,6,7};
    printarr(10,arr);
    delete(10,2,arr);
    printarr(10,arr);
}
