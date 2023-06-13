/*
4
2 10
0 20
1 5
1 3

3
0 1
0 10
0 100

*/


#include <bits/stdc++.h>
using namespace std;

const long long int maxLong = 1e18;
const int maxN = 2005;
int n, c[maxN], t[maxN];
long long int optimized[maxN][maxN];

long long int backtrack(int items, int currTime){
    if(currTime >= n){
        return 0;
    }
    if(items > n){
        return maxLong;
    }
    if(optimized[items][currTime] >= 0){
        return optimized[items][currTime];
    }
    optimized[items][currTime] = min(backtrack(items+1, currTime), c[items] + backtrack(items+1, currTime+t[items]+1));
    return optimized[items][currTime];

}


void solve(){
    for(int i = 0;i<maxN;++i){
        for(int j = 0;j<maxN;++j){
            optimized[i][j] = -1;
        }
    }
    cin>>n;
    for(int i = 1; i<=n;++i){
        cin >> t[i] >> c[i];
    }
    cout<<backtrack(1,0)<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
