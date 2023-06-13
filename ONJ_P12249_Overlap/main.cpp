/*
2
3
ABCD
DEFGH
CDEF
2
AAAAA
AAAAAAA

 */


#include <bits/stdc++.h>
using namespace std;

string s;
int n, strLength[6], tempLength, maxLength;
char arrChar[6][10];
bool visited[6];

void backtracking(int x, int y){
    if(y==strLength[x]){
        return;
    }
    visited[x]=true;
    ++tempLength;
    backtracking(x,y+1);
    for(int j = 0;j<n;++j){
        if(visited[x] == 0){
            bool nextLineisAvailable = true;
            int jLineIndex = 0;
            for(int k = y;k<strLength[x] && jLineIndex < strLength[j];++k){
                if(arrChar[x][k]!=arrChar[j][jLineIndex] || jLineIndex == strLength[j]-1){
                    nextLineisAvailable = false;
                    break;
                }
                ++jLineIndex;
            }
            if(nextLineisAvailable){
                backtracking(j,0);
            }

        }
    }
    if(y==0){
        visited[x] = false;
    }
    max(tempLength, maxLength);
    --tempLength;
}

void solve(){
    memset(visited,0,sizeof(visited));
    memset(strLength,0,sizeof(strLength));
    tempLength = maxLength = 0;
    cin>>n;
    for(int i = 0; i<n;++i){
        cin>>s;
        strLength[i]=s.size();
        for(int j = 0;j<strLength[i];++j){
            arrChar[i][j]=s[j];
            sort(arrChar[i], arrChar[i]+strLength[i]);
        }
    }
    for(int i = 0;i<n;++i){
        backtracking(i,0);
    }
    cout<<maxLength<<endl;
}

int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 1;i<=t;++i){
        solve();
    }

    return 0;
}
