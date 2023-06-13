#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5;
long long int Result;
int n, arr[maxN];
bool TurnToZero = false;

void backtracking(int index){
    if(index == n){
        if(Result%360 == 0){
            TurnToZero = true;
        }
        return;
    }
    for(int j = 0;j<=1;++j){
        if(j==0){
            Result += arr[index];
            backtracking(index+1);
            Result -= arr[index];

        }
        else{
            Result -= arr[index];
            backtracking(index+1);
            Result += arr[index];
        }
        if(TurnToZero){return;}
    }
}

void solve(){
    cin>> n;
    for(int v, i = 0; i<n ;++i){
        cin >> v;
        arr[i] = v;
    }
    backtracking(0);

    if(TurnToZero){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();

    return 0;
}
