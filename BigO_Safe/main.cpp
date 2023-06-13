#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;


int a[15][50];
int m;
int c[15];
int numRight[15];
map <vector <int>, int> M;
ll res = 0;n

void Find(int limit, int pos, string cur, bool isCheck){
    //int maxnumRight = 0;
    for(int i = 1; i <= m; i++)
        if(numRight[i] > c[i])
            return;
    if(pos == limit){
        vector <int> cur;
        for(int i = 1; i <= m; i++)
            if(isCheck)
                cur.pb(c[i] - numRight[i]);
            else
                cur.pb(numRight[i]);
        if(isCheck){
            res += M[cur];
        }else{
            M[cur]++;
        }
        return;
    }
    for(int val = 0; val <= 1; val++){
        for(int i = 1; i <= m; i++){
            if(a[i][pos] == val)
                numRight[i]++;
        }
        Find(limit, pos+1, cur + (char)(val + '0'), isCheck);
        for(int i = 1; i <= m; i++){
            if(a[i][pos] == val)
                numRight[i]--;
        }
    //Find(limit, pos+1, cur + '0');
    }

}
void solve(){
    int n;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;
        for(ull j = 0; j < s.size(); j++){
            a[i][j] = (int)(s[j] - '0');
        }
        cin >> c[i];
    }
    int mid = n/2;
    Find(mid, 0, "", false);
    memset(numRight,0,sizeof(numRight));
    Find(n, mid, "", true);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
