#include<bits/stdc++.h>
using namespace std;
int n,m,si,sj,ei,ej;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int,int>>> prev_step;

bool isValid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m && grid[i][j]!='#';
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push(make_pair(si,sj));
    visited[si][sj] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        string dir="UDLR";
        for(int option=0;option<4;option++){
            int nx=x+dx[option],ny=y+dy[option];
            if(isValid(nx,ny) && !visited[nx][ny]){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                prev_step[nx][ny] = make_pair(x,y);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    grid=vector<string>(n);
    visited=vector<vector<bool>>(n,vector<bool>(m,false));
    prev_step=vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m,{-1,-1}));
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){si=i;sj=j;}
            if(grid[i][j]=='B'){ei=i;ej=j;}
        }
    }
    bfs(si,sj);
    if(!visited[ei][ej]){
        cout<<"NO";
        return 0;
    }
    vector<char> path;
    for(pair<int,int> p={ei,ej}; p != make_pair(si,sj); p = prev_step[p.first][p.second]){
        if(p.first > prev_step[p.first][p.second].first) path.push_back('D');
        else if(p.first < prev_step[p.first][p.second].first) path.push_back('U');
        else if(p.second > prev_step[p.first][p.second].second) path.push_back('R');
        else path.push_back('L');
    }
    reverse(path.begin(),path.end());
    cout<<"YES\n"<<path.size()<<"\n";
    for(char p : path) cout<<p;
}