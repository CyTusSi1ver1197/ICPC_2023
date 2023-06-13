#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VanDongVien{
private:
    string hoTen;
    string monThiDau;
    int tuoi;
    double chieuCao, canNang;
public:
    VanDongVien(string hoten, string monthidau, int tuoi, double chieucao, double cannang){
        this->hoTen = hoten;
        this->monThiDau = monthidau;
        this->tuoi = tuoi;
        this->chieuCao = chieucao;
        this->canNang = canNang;
    }
    VanDongVien():VanDongVien("","",0,0,0){};
    ~VanDongVien(){
        this->hoTen = this->monThiDau = " ";
        this->tuoi = this->canNang = this->chieuCao = 0;
    }
    bool operator>(VanDongVien A){
        return (this->chieuCao>A.chieuCao) && (this->canNang>A.canNang);
    }
    friend istream &operator>>(istream &is, VanDongVien &obj)
    {
        cin.ignore();
        cout << "Nhap Ho Ten: "; fflush(stdin); getline(is, obj.hoTen);
        cout << "Nhap Mon Thi Dau: "; fflush(stdin); getline(is, obj.monThiDau);
        cout << "Nhap Tuoi: "; is >> obj.tuoi;
        cout << "Nhap Can Nang: "; is >> obj.canNang;
        cout << "Nhap Chieu Cao: "; is >> obj.chieuCao;
        return is;
    }

    friend ostream &operator<<(ostream &os, VanDongVien obj)
    {
        cout << "Ho Ten: " << obj.hoTen << endl;
        cout << "Mon Thi Dau: " << obj.monThiDau << endl;
        cout << "Tuoi: " << obj.tuoi << endl;
        cout << "Can Nang: " << obj.canNang << endl;
        cout << "Chieu cao: " << obj.chieuCao << endl;
        return os;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
