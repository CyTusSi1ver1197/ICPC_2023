#include <bits/stdc++.h>
using namespace std;
const int maxN = 1500;
int deg[maxN][maxN], n, m, line;
vector<int> Result;

void fluerAlgor(int u){
    for(int v = 1; v<=n;++v){
        if(deg[u][v]>0){
            deg[u][v]--;
            fluerAlgor(v);
        }
    }
    Result.push_back(u);
}


void solve(){
    cin>>line;
    for(int i = 0; i<maxN; ++i){
        memset(deg[i],0,sizeof(deg[i]));
    }
    for(int i = 0; i<line;++i){
        cin >> m;
        int u, v;
        cin >> u;
        while(m--){
            cin >> v;
            deg[u][v]++;
            n = max(n,v);
            u = v;
        }
    }
    fluerAlgor(1);
    cout<<Result.size()-1<<" ";
    reverse(Result.begin(), Result.end());
    for(int u : Result){
        cout << u << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
