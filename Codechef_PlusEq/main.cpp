/*
4
15112 28
120012 33
123 123
15489001 10549

*/


#include <bits/stdc++.h>
using namespace std;

const int maxS = 22;
long long int temp, n, sLen;
bool isFound = false;
string s;
vector<string> Result;
int toInt(string s){
    long long unsigned int i = 0, sign = 1;
    if(s[0] == '-'){
        sign = -1;
        i++;
    }
    long long unsigned int ans = 0;
    for(;i < s.size(); i++){
        ans = ans*10 + s[i] - '0';
    }
    return sign * ans;
}


void backtracking(int index){
    if(index == sLen){
        if(temp == n){
            for(long long unsigned int i = 0; i<Result.size();++i){
                cout<<Result[i];
                if(i != Result.size()-1){
                    cout<<"+";
                }
            }
            isFound = true;
            cout<<"\n";
        }
        return;
    }
    for(int u = index; u < sLen;++u){
        string subStr = s.substr(index, u-index+1);
        Result.push_back(subStr);
        temp+=toInt(subStr);
        backtracking(u+1);
        temp-=toInt(subStr);
        Result.pop_back();
        if(isFound){
            break;
        }
    }

}
void solve(){
    isFound = false;
    Result.clear();
    cin >> s  >> n;
    sLen = s.size();
    backtracking(0);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        solve();

    }
    return 0;
}
