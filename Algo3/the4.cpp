#include "the4.h"
#include <math.h>



int recursive_sln(int i, int*& arr, int &number_of_calls){
    int a,b;
    number_of_calls= number_of_calls + 1;
    if(i==0 || (i==1 && arr[1]<=arr[0])){
        return arr[0];
    }
    
    else if(i==1 && arr[1]>arr[0]){
        return arr[1];
    }
    else if(i<3){
        if(arr[2]>=arr[1] && arr[2]>=arr[0]){
            return arr[2];
        }
        else if(arr[1]>=arr[0] && arr[1]>=arr[2]){
            return arr[1];
        }
        else if(arr[0]>=arr[1] && arr[0]>=arr[2]){
            return arr[0];
        }
        
    }
    a=b=0;
    
    a = recursive_sln(i-3, arr, number_of_calls) + arr[i];
    b = recursive_sln(i-1, arr, number_of_calls);
    if(a>b){
        
        return a;
    }
    else{
        return b;
    }
         // this is a dummy return value. YOU SHOULD CHANGE THIS!
         
}

int memoization_sln(int i, int*& arr, int*& mem){ //memoization
    
    int m,n ;
    

    mem[0]=mem[1]=arr[0];
    if(arr[1]>arr[0]){
        mem[1]=arr[1];
    }
    if(arr[1]>=arr[0] && arr[1]>=arr[2]){
        
        mem[2]=arr[1];
    }
    else if(arr[0]>=arr[1] && arr[0]>=arr[2]){
        mem[2] =arr[0];
    }
    else if(arr[2]>=arr[1] && arr[2]>=arr[0]){
        mem[2]=arr[2];
    }
    m =  arr[i];
    if(i>=3 && mem[i-3]==-1){
        m+= memoization_sln(i-3,arr,mem);
    }
    else{
        m+=mem[i-3];
    }
    n = mem[i-1];
    if(i>=3 && mem[i-1]==-1){
        n= memoization_sln(i-1,arr,mem);
    }
    mem[i]=n;
    if(m>n){
        mem[i]=m;
    }
    return mem[i];
}
int dp_sln(int size, int*& arr, int*& mem){ //dynamic programmi
    mem[0] = std::max(0, arr[0]);
    if (size == 2) {
        mem[1] = std::max(arr[1], mem[0]);
    }
    else if (size >= 3) {
        mem[1] = std::max(arr[1], std::max(0, arr[0]));
        mem[2] = std::max(arr[2], std::max(arr[1], std::max(0, arr[0])));
 
        for(int index =3 ; index<size ; index++){
            mem[index] = std::max(mem[index - 1], arr[index] + mem[index - 3]);
        }
    }
    return mem[size - 1];
}

//mranewliz













