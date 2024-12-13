#include<bits/stdc++.h>
using namespace std;
int a[60],b[60],c[60],ans[60][60];
pair<int,int> p[60];
int main(){
    int n,i,j,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        p[i]=make_pair(b[i],i);
    }
    sort(p+1,p+n+1);
    for(i=1;i<=n;i++){
        while(a[i]){
            int num=p[n].first,pku=p[n].second;
            if(!num){
                printf("-1\n");
                return 0;
            }
            ans[i][pku]=1;
            --a[i];
            --p[n].first;
            if(num-1<p[n-1].first) --n;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(ans[j][i]&&c[j]){--c[j];continue;}
            if(b[i]&&!c[j]) {ans[j][i]=1;--b[i];}
        }
    }
    for(i=1;i<=n;i++) if(c[i]) {printf("-1\n");return 0;}
    for(i=1;i<=n;i++){
        if(b[i]){printf("-1\n");return 0;}
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%c",ans[i][j]?'X':'.');
        }
        printf("\n");
    }
    return 0;
}