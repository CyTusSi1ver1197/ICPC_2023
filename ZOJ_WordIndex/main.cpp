#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5;
int n = 9, s = 390, best_len = -1;
vector<int> cur, best;
int arr[maxN] = {200, 20, 20, 50, 50, 10, 50, 100, 100};


void backtracking(int i, int sum){
    if(sum>s){
        return;
    }
    if(best_len ==cur.size()){
        return;
    }
    if(sum==s){
        best = cur;
        best_len = best.size();
        return;
    }
    for(int j = i;j<n;++j){
        cur.push_back(arr[j]);
        backtracking(j+1,sum+arr[j]);
        cur.pop_back();
    }
}

void solve(){


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
