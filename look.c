#include<stdio.h>
#include<stdlib.h>

#define SIZE 200
#define LOW 0

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void asc_sort(int arr[200],int n){
   int i,j;
    for(i=0;i<n-1;i++){
        for( j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

void des_sort(int arr[200],int n){
    int i,j;
    for(i= 0;i<n ;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
}

int main(){
int q1[SIZE];int q2[SIZE];int n1=0,n2=0,i,j,temp,seek;
int no_tracks,start_track;
printf("Enter number of tracks to visit: ");
scanf("%d",&no_tracks);
printf("Eter the starting track: ");
scanf("%d",&start_track);
printf("Please enter the track numbers:");

for(i=1;i<=no_tracks;i++){
    printf("\nEnter track %d :",i);
    scanf("%d",&temp);
    if(temp < start_track){
    q2[n2++] = temp;
     }
    else {
        q1[n1++] = temp;
    }
}

des_sort(q2,n2);
asc_sort(q1,n1);
seek = start_track;

if(n1!=0){
    printf("\nDisk head moves from %d to %d with seek %d.",seek,q1[0],q1[0]-seek);
}
for(i=0;i<n1-1;i++){
    seek = q1[i];
    printf("\nDisk head moves from %d to %d with seek %d",q1[i],q1[i+1],q1[i+1]-q1[i]);
}

if(n2!=0){
    printf("\nDisk head moves from %d to %d with seek %d.",seek,q2[0],seek-q2[0]);
    seek = q2[0];
}
for(i=0;i<n2-1;i++){
    printf("\nDisk head moves from %d to %d with seek %d",q2[i],q2[i+1],q2[i]-q2[i+1]);

}
return 0;
}














