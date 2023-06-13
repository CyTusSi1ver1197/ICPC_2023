#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5;
int arr1[maxN], arr2[maxN], n;
long long int Result;
void tasks(){
    Result = 0;
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    cin >> n;
    for(int i = 0; i<n;++i){
        cin >> arr1[i];
    }
    sort(arr1, arr1+n);
    for(int i = 0; i<n;++i){
        cin>> arr2[i];
    }
    sort(arr2, arr2+n, greater<int>());
    for(int i = 0 ; i<n;++i){
        Result += max(arr1[i],arr2[i]);
    }
    cout<<Result<<endl;
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
