#include<bits/stdc++.h>
using namespace std;
string line;
int t;

struct point{
    int x, y;
};
point start;
double dist(point u, point v){
    u.x -= v.x;
    u.y -= v.y;
    return sqrt(1ll*u.x*u.x + 1ll*u.y*u.y) / 1000;
}
int toInt(string s){
    int i = 0, sign = 1;
    if(s[0] == '-'){
        sign = -1;
        i++;
    }
    int ans = 0;
    for(;i < s.size(); i++){
        ans = ans*10 + s[i] - '0';
    }
    return sign * ans;
}

void solve(){
    cin >> start.x >> start.y;
    cin.ignore();
    double sum = 0;
    while(getline(cin, line)){
        if(line.empty()){
            break;
        }
        stringstream ss(line);
        string tmp;
        vector<int> a;
        while(ss >> tmp){
            a.push_back(toInt(tmp));
        }
        sum += dist({a[0], a[1]}, {a[2], a[3]})*2;
    }
    sum *= 3.0;
    if (sum - (int)sum >= 0.5) sum++;
    int hour = (int)sum / 60, min = (int)sum % 60;
    cout << hour << ':';
    if(min < 10) cout << 0;
    cout << min << endl;
    if(t > 0)cout << endl;
}

int main(){
//    freopen("solution.inp","r",stdin);
//    freopen("solution.out","w",stdout);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
