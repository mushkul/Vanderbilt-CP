#include<bits/stdc++.h>
using namespace std;
int board[10][10]={0};
int move_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int move){
    if(x+move_x[move]<1 || x+move_x[move]>8 || y+move_y[move]<1 || y+move_y[move]>8){
        return false;
    }
    if(board[x+move_x[move]][y+move_y[move]] != 0){
        return false;
    }
    return true;
}

int solve(int x, int y, int moveNum){
    int new_x, new_y;
    if(moveNum == 65){
        return true;
    }
    for(int i=0; i<8; i++){
        if(isValid(x, y, i)){
            new_x = x+move_x[i];
            new_y = y+move_y[i];
            board[new_x][new_y] = moveNum;

            if(solve(new_x, new_y, moveNum+1)){
                return true;
            }
            else{
                board[new_x][new_y] = 0; // backtrack
            }
        }
    }
    return false;
}

int main(){
    int x, y;
    cin >> x >> y;
  
    board[x][y] = 1;
    if(!solve(x, y, 2)){
        cout<<"No solution found!\n";
    }
    else{
        for(int i=1; i<=8; i++){
            for(int j=1; j<=8; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}