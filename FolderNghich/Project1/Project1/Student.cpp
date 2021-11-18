#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
private:
	string masv;
	string hoten;
	int tuoi;
	float diem;
public:
	void Nhap()
	{
		cout << "Nhap ma sv" << end1;
		getline(cin, masv);
		cout << "Nhap ho ten: " << endl;
		getline(cin, hoten);
		cout << "Nhap tuoi	" << endl;
	}
	void Xuat();

};


int main()
{

	return 0;
}