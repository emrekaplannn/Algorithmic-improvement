#include "the1.h"

//You can add your own helper functions

int sillySort(int* arr, long &comparison, long & swap, int size) 
{

    int num_of_calls=1, q=size/4;
    int i=0, j=0, z1=0 , z2=0;
    
	if(size<=1) return num_of_calls;
	if(size==2){
	    int* gg=&arr[0];
	    int* gg2=&arr[1];
	    
	    int x=(*gg);
	    comparison++;
	    if ((*gg)>(*(gg2))) {
	        (*gg)=(*gg2);
	        (*gg2)=x;
	        swap++;
	    }
	    return num_of_calls;
	}
	
	int* q1=&arr[0];
    int* q2=&arr[0];
    int* q3=&arr[0];
    int* q4=&arr[0];
    
    for(i=0;i<q;i++){
        q2++;
    }
    for(i=0;i<2*q;i++){
        q3++;
    }
    for(i=0;i<3*q;i++){
        q4++;
    }
    
    num_of_calls += sillySort(q1, comparison, swap, 2*q);
    num_of_calls += sillySort(q2, comparison, swap, 2*q);
    num_of_calls += sillySort(q3, comparison, swap, 2*q);
    num_of_calls += sillySort(q1, comparison, swap, 2*q);
    num_of_calls += sillySort(q2, comparison, swap, 2*q);
    num_of_calls += sillySort(q1, comparison, swap, 2*q);

	//Your code here
	
	return num_of_calls;
}


void merg(int *ar, int *h11, int size1 , int *h22, int size2, long &comparison){
    
    int x=0, y=0, z=0;
    while(size1!=0 && size2!=0){
        if (h11[x]<=h22[y]){
            ar[z]=h11[x];
            x++;
            size1--;
        }
        else{
            ar[z]=h22[y];
            y++;
            size2--;
        }
        z++;
        
        
        comparison++;
    }
    while(size1!=0){
        ar[z]=h11[x];
        x++;
        z++;
        size1--;
    }
    while(size2!=0){
        ar[z]=h22[y];
        y++;
        z++;
        size2--;
    }
}


int crossMergeSort(int *arr, long &comparison, int size)
{
	
    int num_of_calls=1, q=size/4;
    int i=0, j=0, z1=0 , z2=0;
    int *h1 = new int[2*q];   
    int *h2 = new int[2*q];   

    
	if(size<=1) return num_of_calls;
	if(size==2){
	    int* gg=&arr[0];
	    int* gg2=&arr[1];
	    
	    int x=(*gg);
	    comparison++;
	    if ((*gg)>(*(gg2))) {
	        (*gg)=(*gg2);
	        (*gg2)=x;
	    }
	    return num_of_calls;
	}
	
	
	int* q1=&arr[0];
    int* q2=&arr[0];
    int* q3=&arr[0];
    int* q4=&arr[0];
    
    for(i=0;i<q;i++){
        q2++;
    }
    for(i=0;i<2*q;i++){
        q3++;
    }
    for(i=0;i<3*q;i++){
        q4++;
    }
    
    num_of_calls += crossMergeSort(q1, comparison, q);
    num_of_calls += crossMergeSort(q2, comparison, q);
    num_of_calls += crossMergeSort(q3, comparison, q);
    num_of_calls += crossMergeSort(q4, comparison, q);
    merg(h1,q1,q,q3,q,comparison);
    merg(h2,q2,q,q4,q,comparison);
    merg(arr,h1,2*q,h2,2*q,comparison);

	
	// Your code here
	
	return num_of_calls;
	
}













