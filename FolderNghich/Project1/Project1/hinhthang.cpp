#include <iostream>
#include <math.h>

using namespace std;

class HinhThang 
{
private:
	int a, b, h;
public:
	void Nhap();
	void Xuat();
	float Tinh();

};

void HinhThang::Nhap()
{
	cout << "Nhap cac canh: " << endl;
	cin >> a >> b >> h;

}
void HinhThang::Xuat()
{
	cout << "Cac canh la " << a << " " << b << " " << h << endl;
}

float HinhThang::Tinh()
{
	int s = 0;
	s = ((a + b) / 2) * h;
	cout << "Dien tich la: " << s << endl;
}
int main()
{
	HinhThang x;
	x.Nhap();
	x.Xuat();
	x.Tinh();
	return 0;
}