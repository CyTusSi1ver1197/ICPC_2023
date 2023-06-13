/* Ý TƯỞNG LÀ TỪ CHUỖI BAN ĐẦU, TÌM 10 CHUỖI CÓ THỨ TỰ TỪ ĐIỂN TĂNG DẦN,
    10 CHUỖI KÍ TỰ CÓ THỨ TỰ TỪ ĐIỂN GIẢM DẦN, TÌM CHUỖI CÓ KHOẢNG CÁCH
    GIỮA HAI KÍ TỰ CÓ GIÁ TRỊ NHỎ NHẤT TRONG CHUỖI THEO TỪ ĐIỂN, NHƯNG LỚN
    NHẤT TRÊN 21 CHUỖI ĐƯỢC TẠO RA.
*/

/*
WORDFISH

*/
#include <bits/stdc++.h>
using namespace std;
vector <char> strChar, result, strCharTwo;
string s;
int n, cnt, maxMinDistance, minDistance, counter;
stack <vector<char>> st;

int chartoIndex(char temp){
    return int(temp)-97;
}
bool prePermutation(int n, vector<char>& c){
    int i = n-2;
    while(i>=0 && c[i]<c[i+1]) {
        --i;
    }
    if(i<0){
        return false;
    }
    int k = n-1;
    while(c[k]>c[i]){
        --k;
    }
    swap(c[i], c[k]);
    ++i; k = n-1;
    while(i<k){
        swap(c[i],c[k]);
        ++i;
        --k;
    }
    vector<char>temp = c;
    st.push(temp);
    return true;
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
    while(c[k]<c[i]){
        --k;
    }
    swap(c[i], c[k]);
    ++i; k = n-1;
    while(i<k){
        swap(c[i],c[k]);
        ++i;
        --k;
    }
//    for(int i = 0;i<n;++i){
//            cout<<strChar[i];
//    }
//    cout<<endl;
    minDistance = 1e9;
    for(int j = 0;j<n-1;++j){
        minDistance = min(abs(c[j]-c[j+1]), minDistance);
    }
    if(minDistance > maxMinDistance){
        result = c;
        maxMinDistance = minDistance;
    }
    return true;
}

void reset() {
    n=0;
    cnt=0;
    maxMinDistance = 0;
    minDistance = 1e9;
    counter = 0;
    while (!st.empty()) st.pop();
    strChar.clear();
    result.clear();
    strCharTwo.clear();
}


void solve(){
        reset();
        minDistance = 1e9;
        maxMinDistance = 0;
        counter = 0;
        n = s.size();
        strChar.clear();
        for(char c : s){
            strChar.push_back(c);
            strCharTwo.push_back(c);
        }
        st.push(strChar);
        do{
            ++counter;
        }while(prePermutation(n, strChar) && counter <10);

        while(!st.empty()){
            minDistance = 1e9;
            vector <char> temp;
            temp = st.top();
//            for(int i = 0;i<n;++i){
//                    cout<<temp[i];
//                }
//            cout<<endl;
            for(int j = 0;j<n-1;++j){
                    minDistance = min(abs(temp[j]-temp[j+1]), minDistance);
            }
            if(minDistance > maxMinDistance){
                result = temp;
                maxMinDistance = minDistance;
            }
            st.pop();
        }
        counter = 0;
        strChar = strCharTwo;
        do{
            ++counter;
        }while(nextPermutation(n, strChar) && counter <10);

        for(int i = 0;i<n;++i){
                cout<<result[i];
        }
        cout<<maxMinDistance<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    while(cin>>s){
        solve();
    }
    return 0;
}

