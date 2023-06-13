#include <bits/stdc++.h>
using namespace std;

//class HocSinh;
//class SaoDo;
//class BiThu;
//class LopHoc;
//class Kho;
//class ToaNha;

class HocSinh{
private:
    string studentID;
    string studentName;
    string studentClass;
public:

};

class Phong{
private:
    double length;
    double width;
    string namePhong;
    string nameToaNha;
public:
    void setLength(double length) { this->length = length; }
    double getLength() { return this->length; }
    void setWidth(double width) { this->width = width;; }
    double getWidth() { return this->width; }
    void setNamePhong(string namePhong) { this->namePhong = namePhong; }
    string getNamePhong() { return this->namePhong; }
    void setNameToaNha(string nameToaNha) { this->nameToaNha = nameToaNha; }
    string getNameToaNha() { return this->nameToaNha; }
    virtual void displayPhong() = 0;
    virtual ~Phong();
};
class LopHoc : public Phong{
private:
    int soHocSinh;
    string tenLop;
public:
    void displayPhong(){
        cout<<getNamePhong()<<endl;
        cout<<getNameToaNha()<<endl;
        cout<<getLength()<<endl;
        cout<<getWidth()<<endl;
        cout<<this->tenLop<<endl;
    }
};


void solve(){

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
