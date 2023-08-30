#include<stdio.h>
int insert(int size,int capacity,int place,int element,int arr[]){
 if(size>=capacity){
    return -1;
 }
    for(int i=size-1;i>=place-1;i--){
        arr[i+1]=arr[i];
    }
    arr[place-1]=element;
    printf("\n");
}
void printarr(int size,int arr[]){
    for(int i=0;i<size;i++){
        printf(" %d",arr[i]);
    }
}
int main(){
    int arr[10]={1,2,3,4,5,6};
    printarr(10,arr);
    insert(6,10,2,9,arr);
    printarr(10,arr);
}
