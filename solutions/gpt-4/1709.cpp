#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
        cin>>grid[i];
    vector<pair<int,int>> ans;
    while(true){
        vector<int> row(n),column(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='o')
                    row[i]++,column[j]++;
            }
        }
        int max=0,mr=-1,mc=-1;
        for(int i=0;i<n;i++){
            if(row[i]>max)
                max=row[i],mr=i;
            if(column[i]>max)
                max=column[i],mc=i;
        }
        if(max==0)
            break;
        if(mr!=-1){
            ans.push_back({1,mr+1});
            for(int i=0;i<n;i++)
                if(grid[mr][i]=='o')
                    grid[mr][i]='.';
        } else {
            ans.push_back({2,mc+1});
            for(int i=0;i<n;i++)
                if(grid[i][mc]=='o')
                    grid[i][mc]='.';
        }
    }
    cout<<ans.size()<<"\n";
    for(auto& x:ans)
        cout<<x.first<<" "<<x.second<<"\n";
    return 0;
}