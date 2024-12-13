#include<bits/stdc++.h>
#define mod 1000000007
#define matrix vector<vector<long long> >
using namespace std;

matrix multiply(matrix A, matrix B){
    matrix C(2,vector<long long>(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }
    return C;
}

matrix power(matrix A, long long p){
    if(p==1)
    return A;
    if(p%2)
    return multiply(A, power(A,p-1));
    matrix X = power(A,p/2);
    return multiply(X,X);
}

long long fib(long long n){
    matrix T(2,vector<long long>(2));
    T[0][0] = 0, T[0][1] = 1;
    T[1][0] = 1, T[1][1] = 1;
    if(n==0)
    return 0;
    T = power(T, n-1);
    return T[1][0];
}


int main(){
    long long n;
    cin>>n;
    cout<<fib(n);
    return 0;
}