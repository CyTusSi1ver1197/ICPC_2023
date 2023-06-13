#include <bits/stdc++.h>
using namespace std;
const int maxN = 20000;

long long unsigned int n,m;
bool visited[maxN], hasCycle;
vector<vector<int>> graph;
vector<int> path;

void findHamiltonPath(int u){
    if(path.size() == n || hasCycle){
        hasCycle = true;
        return;
    }
    for(int v:graph[u]){
        if(!visited[v]){
            path.push_back(v);
            visited[v]=true;
            findHamiltonPath(v);
            visited[v]=false;
            path.pop_back();
        }
    }

}

void solve(){
    memset(visited,0,sizeof(visited));
    path.clear();
    hasCycle = false;
    cin >> n >> m;
    graph.assign(n+1,vector<int>());
    for(long long unsigned int u,v,i=0;i<m;++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(long long unsigned int i = 1;i<=n;++i){
        visited[i] = true;
        path.push_back(i);
        findHamiltonPath(i);
        path.pop_back();
        visited[i] = false;
    }
    if(hasCycle){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
