#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
int arr[maxN], n, path, maxPath;
bool visited[maxN];
//1 2 3 8 5

void backtracking(int i){
    ++path;
    visited[i]=true;
    int temp;
    for(int j = i+1; j<n;++j){
        if(arr[j] == arr[i]){continue;}
        if(arr[j] > 2*arr[i]){break;}
        temp = arr[j] - arr[i];
        if(binary_search(arr, arr+j,temp)){
            backtracking(j);
        }

    }

    maxPath = max(path, maxPath);
    --path;
}

void solve(){
    path = maxPath = 0;
    memset(visited,0,sizeof(visited));
    cin>>n;
    for(int i = 0; i<n;++i){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i = 1;i<n;++i){
        if(!visited[i]){
            backtracking(i);
        }
    }
    cout<<maxPath<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
