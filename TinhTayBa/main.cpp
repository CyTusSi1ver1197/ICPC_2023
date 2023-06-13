#include <bits/stdc++.h>
using namespace std;


const int maxN = 2e5+20;
vector <int> graph[maxN];
vector <int> low, num;
vector <bool> found;
stack<int> st;
bool visited[maxN];
bool isTayBa = false;
int n, m, counter, numTracking;

void dfs(int i){
    ++counter;
    num[i] = low[i] = counter;
    st.push(i);
    for(int v:graph[i]){
        if(!found[v]){
            if(num[v]>0){
                low[i] = min(low[i], low[v]);
            }
            else{
                dfs(v);
                low[i] = min(low[i], low[v]);
            }
        }
    }
    if(num[i] == low[i]){
        int v, counter = 0;
        do{
            v = st.top();
            st.pop();
            found[v] = true;
            ++counter;
        }while(v!=i);
        if(counter == 3){
            isTayBa = true;
            return;
        }
    }
}
//void dfsTwo(int i){
//    visited[i]=true;
//    numTracking++;
//    for(int v : graph[i]){
//        if(!visited[v]){
//            dfs(v);
//        }
//    }
//    numTracking--;
//    visited[i] = false;
//}


void tarjan(){
    counter = 0;
    low.assign(n+1,0);
    num.assign(n+1,0);
    found.assign(n+1, false);

    for(int i = 1; i<=n;++i){
        if(!num[i]){
            dfs(i);
        }
        if(isTayBa){
            return;
        }
    }
}

void tasks(){
    cin>>n;
    isTayBa = false;
    for (auto& v : graph) {
        v.clear();
    }
    memset(visited,false,sizeof(visited));
    for(int v, i=1; i<=n;++i){
        cin >> v;
        graph[i].push_back(v);
    }
    tarjan();
    if(isTayBa){
        cout<<"<3"<<endl;
    }
    else{
        cout<<"</3"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        tasks();
    }

    return 0;
}
