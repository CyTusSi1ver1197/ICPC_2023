/* Cách xử lý bài: giả sử chuôi kí tự là số 0 - 25, chuỗi có độ dài n;
    nếu trong chuôi tại vị trí k có arr[k] < arr[k+1] với k+1 < n
    thì tiến hành tìm kí tự bé nhât từ k+1 -> n && arr[minIndex] > arr[k];
*/
#include <bits/stdc++.h>
using namespace std;
vector <char> strChar;
string s;
int n;
int chartoIndex(char temp){
    return int(temp)-97;
}
bool nextPermutation(int n, vector<char>& c){
    int i = n-2;
    while(i>=0 && c[i]>=c[i+1]) {
        --i;
    }
    if(i<0){
        return false;
    }
    int k = n-1;
    while(c[k]<=c[i]){
        --k;
    }
    swap(c[i], c[k]);
    ++i; k = n-1;
    while(i<k){
        swap(c[i],c[k]);
        ++i;
        --k;
    }    return true;
}

void solve(){
    while(true){
        cin >> s;
        if(s == "#"){return;}
        strChar.clear();
        n = s.size();
        for(char c : s){
            strChar.push_back(c);
        }

        bool haveSuccess = nextPermutation(n, strChar);

        if(haveSuccess){
            for(int i = 0; i<n;++i){
                cout<<strChar[i];
            }
            cout<<endl;
        }
        else{
            cout<<"No Successor"<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
