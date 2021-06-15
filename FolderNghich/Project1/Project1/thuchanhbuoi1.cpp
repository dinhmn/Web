#include <iostream>

using namespace std;

class tamgiac
{
public:
	tamgiac();
	~tamgiac();
	void Nhap();
	void Xuat();
	int Tinh();

private:
	int a, b, c;
};

void tamgiac::Nhap()
{
	cout << "Nhap canh a: ";
	cin >> a;
	cout << "Nhap canh b: ";
	cin >> b;
	cout << "Nhap chieu cao c: ";
	cin >> c;
}


void tamgiac::Xuat()
{
	cout << "a= " << a << "b= " << b << "c= " << c;
}


int tamgiac::Tinh()
{
	int s = 0;
	s = (a + b) / 2;
	cout << "Dien tich: " << s;
}
tamgiac::tamgiac()
{
}

tamgiac::~tamgiac()
{
}

int main()
{
	tamgiac tg;
	tg.Nhap();
	tg.Xuat();
	tg.Tinh();
	return 0;
}