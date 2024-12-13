#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX_N 1005
#define MAX_M 105
int t,n,m,lps[MAX_M],dp[MAX_N][MAX_M][2],nextInd[MAX_M][30];
char str[MAX_M];

void calcLPS() {
  int len = 0; 
  lps[0] = 0; 
  int i = 1; 
  while (i < m) { 
    if (str[i] == str[len]) { 
      len++; 
      lps[i] = len; 
      i++; 
    } 
    else { 
      if (len != 0) { 
        len = lps[len-1]; 
      } 
      else {
        lps[i] = 0; 
        i++; 
      } 
    } 
  } 
}

void preCalc(){
  for(int i=0;i<m;i++){
    for(char c='A';c<='Z';c++){
      if(i>0 && str[i] != c)
        nextInd[i][c-'A'] = nextInd[lps[i-1]][c-'A'];
      else
        nextInd[i][c-'A'] = i + (str[i] == c);
    }
  }
}

int solve(int L,int prefixMatch,bool patternMatched){
  if(L == 0)
    return patternMatched;
  
  if(dp[L][prefixMatch][patternMatched] != -1)
    return dp[L][prefixMatch][patternMatched];
  
  int res = 0;
  for(char c= 'A';c<='Z';c++){
    int nextPrefixMatched = nextInd[prefixMatch][c-'A'];
    bool nextPatternMatched = patternMatched | (nextPrefixMatched == m);
    res = (res + solve(L-1,nextPrefixMatched,nextPatternMatched)) % MOD;
  }
  
  return dp[L][prefixMatch][patternMatched] = res;
}

int main() {
  cin >> n;
  cin >> str;
  m = strlen(str);
  calcLPS();
  preCalc();
  memset(dp,-1,sizeof(dp));
  long long res = 0;
  for(char c = 'A';c <= 'Z';c++){
    int nextPrefixMatched = nextInd[0][c-'A'];
    bool nextPatternMatched = (nextPrefixMatched == m);
    res = (res + solve(n-1,nextPrefixMatched,nextPatternMatched))%MOD;
  }
  cout<<res;
  return 0;
}