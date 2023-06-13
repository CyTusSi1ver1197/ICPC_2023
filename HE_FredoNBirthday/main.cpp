#include <bits/stdc++.h>
using namespace std;
const int maxN = 20000;

long long unsigned int n, m, curr;
bool visited[maxN];
int maxSize[maxN];
vector<vector<int>> graph;
vector<int> path;

void findHamiltonPath(int u){
    bool isPath = false;
    for(int v:graph[u]){
        if(!visited[v]){
            path.push_back(v);
            visited[v]=true;
            findHamiltonPath(v);
            visited[v]=false;
            path.pop_back();
        }
    }
    if(!isPath){
        maxSize[curr]= max(maxSize[curr], (int)path.size()-1);
    }
}

void solve(){
    memset(visited,0,sizeof(visited));
    memset(maxSize,0,sizeof(maxSize));
    path.clear();
    cin >> n >> m;
    graph.assign(n+1,vector<int>());
    for(long long unsigned int u,v,i=0;i<m;++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(curr = 1; curr<=n; ++curr){
        visited[curr] = true;
        path.push_back(curr);
        findHamiltonPath(curr);
        path.pop_back();
        visited[curr] = false;
    }
    for(long long unsigned int i = 1;i<=n;++i){
        cout<<maxSize[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
