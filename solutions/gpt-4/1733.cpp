#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1000005
int z[MAX_N],n;
string s;
void computeZ(){
    int l=0,r=0;
    z[0]=n;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n&&s[r-l]==s[r])
                r++;
            z[i]=r-l--;
        }else{
            int k=i-l;
            if(z[k]<r-i+1)
                z[i] = z[k];
            else{
                l=i;
                while(r<n&&s[r-l]==s[r])
                    r++;
                z[i]=r-l--;
            }
        }
    }
}
int main(){
    cin>>s;
    n=s.size();
    computeZ();
    vector<int> p;
    for(int i=n-1;i>=0;i--)
        if(i+z[i]==n)
            p.push_back(z[i]);
    for(int i=p.size()-1;i>=0;i--)
        cout<<p[i]<<" ";
}