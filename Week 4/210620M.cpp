#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r){
    int nl = m - l +1;
    int nr = r - m;
    int L[nl];
    int R[nr];

    for(int x = 0; x<nl;x++){
        L[x] = arr[l+x];
    }
    for(int y = 0; y<nr;y++){
        R[y] = arr[m+1+y];
    }    
    int i1 = 0;
    int i2 = 0;
    int k = l;

    while(i1<nl && i2<nr){
        if (L[i1]<=R[i2]){
            arr[k] = L[i1];
            i1++;  
        }
        else{
            arr[k] = R[i2];
            i2++;
        }
        k++;
    }

    if(i1<nl){
        for(int z=i1;z<nl;z++){
            arr[k] = L[z];
            k++;
        }
    }

    if(i2<nr){
        for(int z=i2;z<nr;z++){
            arr[k] = R[z];
            k++;
        }
    }
}

void mergesortIter(int arr[], int n){
    

    int len = 1;
    while(len<n){
        int i = 0;
        while(i<n){
            int L1 = i;
            int R1 = i+len-1;
            int L2 = i + len;
            int R2 = i + 2*len-1;
            if (L2>=n){
                break;
            }
            if (R2>=n){
                R2 = n-1;
            }
            merge(arr,L1,(R1+L2)/2,R2);
            i = i+2*len;
        }
        len = 2*len;
    }
}

void mergesortRecur(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;

        mergesortRecur(arr, l, m);
        
        mergesortRecur(arr,m+1,r);

        merge(arr,l,m,r);
    }
    
}



int main(){
    for(int x = 5000; x<40000; x=x+5000){
        int a[x];
        int b[x];
        for(int y = 0; y<x; y++){
            a[y] = (rand() % 40000);
            b[y] = a[y];
        }

        cout<<"======================================"<<endl<<"Considering an array with "<<x<<" elements"<<endl;
        auto start = high_resolution_clock::now();
        mergesortIter(a,x);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"Time taken by iterative algorithm "<<(duration.count())<<endl;

        auto start2 = high_resolution_clock::now();
        mergesortRecur(b,0,x-1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout<<"Time taken by recursive algorithm "<<(duration2.count())<<endl<<endl;
        
    }
}