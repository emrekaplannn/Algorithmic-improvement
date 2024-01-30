#include "the3.h"

// do not add extra libraries here


/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
    
    you can use ceil function from cmath
    
*/
void countsort(std::string arr[] , int ind, int n, int* pp){
    int a,m;
    
    int* c = new int[26];
    std::string* b = new std::string[n];
    for (int j=0; j<n ; j++){
        a=arr[j][ind];
        a=a-65;
        c[a]++; 
        (*pp)++;
    }
    for(int i=1; i<26; i++){
        c[i] = c[i] + c[i-1];
        (*pp)++;
    }
    //b[1]= arr[0][2];
    for(int k=n-1; k>=0; k--){
        
        a=arr[k][ind];
        a=a-65;
        
        b[c[a]-1] = arr[k];
        c[a]= c[a] -1;
        (*pp)++;
            
    }
    for (m = 0; m<n; ++m){
        arr[m] = b[m];
        (*pp)++;
    }

    
}




int radixSort(std::string arr[], bool ascending, int n, int l){
    int len=arr[0].length();
    int len2=len-1;
    int x=0;
    int zz=0;
    int* po=&x;
    if(ascending){
        for(len2; len2>=0; len2--)
            countsort(arr, len2, n, po);
    }
    else{
        std::string* temp = new std::string[n];
        for(len2; len2>=0; len2--)
            countsort(arr, len2, n, po);
            
        for(;zz<n;zz++){
            temp[zz]=arr[zz];
        }
        for(zz=0;zz<n;zz++){
            arr[zz]=temp[n-zz-1];
        }
    }
    return len*(3*n + pow(26,l))/l;    
    
}









void countsort2(std::string arr[] , int ind, int n, int* pp, int l){
    int a1,a2,a,m, d=pow(26,2);
    
    int* c = new int[d+10];
    std::string* b = new std::string[n];
    /*for (int j=0; j<n ; j++){
        
        a1=arr[j][ind-1];
        a1=a1-65;
        a2=arr[j][ind];
        a2=a2-65;
        a=a1*26 + a2 ;
        c[a]++; 
        (*pp)++;
    }*/
    for(int i=1; i<26^2; i++){
        c[i] = c[i] + c[i-1];
        (*pp)++;
    }
    //b[1]= arr[0][2];
    for(int k=n-1; k>=0; k--){
        
        a1=arr[k][ind-1];
        a1=a1-65;
        a2=arr[k][ind];
        a2=a2-65;
        a=a1*26 + a2 ;
        
        b[c[a]-1] = arr[k];
        c[a]= c[a] -1;
        (*pp)++;
            
    }
    for (m = 0; m<n; ++m){
        arr[m] = b[m];
        (*pp)++;
    }

    
}


/*void countsort2(std::string arr[] , int ind, int n, int* pp){
    int a,m;
    
    int* c = new int[26];
    std::string* b = new std::string[n];
    for (int j=0; j<n ; j++){
        a=arr[j][ind];
        a=a-65;
        c[a]++; 
        (*pp)++;
    }
    for(int i=25; i>=1; --i){
        c[i-1] = c[i] + c[i-1] ;
        (*pp)++;
    }
    //b[1]= arr[0][2];
    for(int k=0; k<n; k++){
        
        a=arr[k][ind];
        a=a-65;
        
        b[c[a]-1] = arr[k];
        c[a]= c[a] -1;
        (*pp)++;
            
    }
    for (m = 0; m<n; ++m){
        arr[m] = b[m];
        (*pp)++;
    }

    
}
*/
















