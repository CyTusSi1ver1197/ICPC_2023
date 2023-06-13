#include <bits/stdc++.h>
using namespace std;
string Y = "Yunyun", M = "Megumin", D = "Draw";
int turtleLength = 10, roadLength = 100;
int Tm, Sm, Ty, Sy;

void tasks(){
    cin >> Tm >> Sm >> Ty >> Sy;
    double timeYuTCmp = double(roadLength)/ double(Ty);
    double timeMeTCmp = double(roadLength)/ double(Tm);
    double timeTCmp = min(timeYuTCmp, timeMeTCmp);

    double timeMeSCmp = double(turtleLength) / double(Sm);
    double timeYuSCmp = double(turtleLength) / double(Sy);

    if(timeMeSCmp <= timeMeTCmp && timeYuSCmp <= timeYuTCmp){
        if(Tm > Ty){
            cout<<M<<endl;
        }
        else if(Tm < Ty){
            cout<<Y<<endl;
        }
        else{
            cout<<D<<endl;
        }
        return;
    }
    else if(timeMeTCmp < timeMeSCmp && timeYuTCmp < timeYuSCmp){
        if(Tm+Sm > Ty+Sy){
            cout<<M<<endl;
        }
        else if(Tm+Sm < Ty+Sy){
            cout<<Y<<endl;
        }
        else{
            cout<<D<<endl;
        }
        return;
    }

    else if(timeMeSCmp <= timeMeTCmp || timeYuSCmp <= timeYuTCmp){
        if(timeMeSCmp <= timeMeTCmp && timeYuSCmp > timeYuTCmp){
            if(Tm > Ty+Sy){
                cout<<M<<endl;
            }
            else if(Tm < Ty+Sy){
                cout<<Y<<endl;
            }
            else{
                cout<<D<<endl;
            }
            return;
        }
        else if(timeYuSCmp <= timeYuTCmp && timeMeSCmp > timeMeTCmp){
            if(Tm+Sm > Ty){
                cout<<M<<endl;
            }
            else if(Tm+Sm < Ty){
                cout<<Y<<endl;
            }
            else{
                cout<<D<<endl;
            }
            return;
        }
    }

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
