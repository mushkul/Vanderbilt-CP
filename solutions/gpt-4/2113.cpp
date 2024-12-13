#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;
int N,M,A[maxN],B[maxN],C[maxN<<1];

void Convolution(int *a,int n,int *b,int m,int *c){
    for(int i=0;i<n+m-1;i++) c[i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) c[i+j]+=a[i]*b[j];
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    Convolution(A,N,B,M,C);
    for(int i=0;i<N+M-1;i++) cout<<C[i]<<" ";
    return 0;
}