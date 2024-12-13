#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3003;
#define getcx getchar_unlocked
int t[N][N],temp[3003],n;
bool b[N][N];

int read_int() {
   char c = getcx();
   while(c<'0' || c>'9') c = getcx();
   int ret = 0;
   while(c>='0' && c<='9') {
      ret = 10 * ret + c - 48;
      c = getcx();
   }
   return ret;
}

int main(){
   n=read_int();
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      	b[i][j] = read_int()==1;
    
   for(int i=1;i<=n;i++)
      for(int j=n;j>=1;j--)
         	if(b[j][i])
            	t[j][i]=t[j+1][i]+1;
    
   ll ret=0;
   for(int i=1;i<=n;i++) {
      for(int j=n-1;j>=1;j--){
         temp[t[j+1][i+1]]--;
         temp[t[j][i]]++;
      }
      for(int j=i;j<=n;j++){
         int d;
         if(j==i)
            d=t[j][i];
         else d=min(t[j][i],t[j][i-1]-1); 
         ret += accumulate(temp+1, temp+d+1, 0);
         if(j<n){
            if(t[j+1][i+1]<t[j][i])
               temp[t[j][i]]--;
            temp[t[j+1][i+1]]++;
         }
      }
      fill(temp, temp+N, 0);
   }
   cout<<ret;
   return 0;
}