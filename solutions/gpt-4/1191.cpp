#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(long long i=0;i<n;i++)
        cin>>v[i];
    long long sum=0, cnt=0;
    for(long long i=0;i<n;i++){
        if(sum+v[i]>k){
            cnt++;
            sum=v[i];
        }
        else
        sum+=v[i];
    }
    cout<<cnt+1<<endl;
    return 0;
}