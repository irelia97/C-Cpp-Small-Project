#include <iostream>
#include <cmath>
using namespace std;

//	a+bi
class Complex
{
	private:
		double a;
		double b;
	public:
		friend istream& operator>>(istream& is, Complex& c);		//���� 
		friend ostream& operator<<(ostream& os, const Complex& c);	//��� 
		
		Complex():a(0.0),b(0.0) {}	//�޲ι��캯�� 
		Complex(double _a, double _b):a(_a),b(_b) {}	//�вι��캯�� 
		
		Complex operator+(const Complex &ano) const;	//�� 
		Complex operator-(const Complex &ano) const;	//��	
		Complex operator*(const Complex &ano) const;	//��	
		Complex operator/(const Complex &ano) const;	//�� 
		Complex pow(int n) const;					//�ݴη� 
		Complex& operator+=(const Complex &ano);	//�Լ� 
		Complex& operator-=(const Complex &ano);	//�Լ�			
		
		void Setab (double _a, double _b) {a = _a; b = _b; }
		double Geta() const { return a; }
		double Getb() const { return b; }
		double GetMod() const { return sqrt(a*a + b*b); } 
};
		
int main()
{
	Complex c1, c2;
	cin  >> c1 >> c2;
	cout << c1 << c2;
	
	cout << "c1+c2��" << c1+c2;
	cout << "c1-c2��" << c1-c2;
	cout << "c1*c2��" << c1*c2;
	cout << "c1/c2��" << c1/c2;
	cout << "c1��������" << c1.pow(3); 
	
	return 0;
}

istream& operator>>(istream& is, Complex& c)
{
	double a, b;
	cout << "�����븴����ʵ����";
	is >> a;
	cout << "�����븴�����鲿��";
	is >> b;
	c.Setab(a,b);
	cout << endl;
	return is;
}

ostream& operator<<(ostream& os, const Complex& c)
{
	double a = c.Geta();
	double b = c.Getb();
	if( fabs(a)<1e-6 && fabs(b)<1e-6){
		os << 0 << endl;
		return os;
	}
	/* ���ʵ�� */
	if( fabs(a) > 1e-6 ){
		os << a;
		if( b > 1e-6){
			os << "+";		//	�鲿Ϊ���� 
		}	
	}
	/* ����鲿 */
	if( b<1e-6 && fabs(b)>1e-6){
		os << "-";			//	�鲿Ϊ���� 
	}
	b = fabs(b);
	if( b > 1e-6 ){			//	�鲿��Ϊ0	
		if( b-1 > 1e-6 ){	//	�鲿��Ϊ-1��1����� 
			cout << b;
		}
		cout << "i";
	}
	os << endl;
	return os;
}


Complex Complex::operator+(const Complex &ano) const
{
	double a = this->a + ano.a;
	double b = this->b + ano.b;
	return Complex(a,b);
}

Complex Complex::operator-(const Complex &ano) const
{
	double a = this->a - ano.a;
	double b = this->b - ano.b;
	return Complex(a,b);		
}

Complex Complex::operator*(const Complex &ano) const
{
	double a = this->a*ano.a - this->b*ano.b;
	double b = this->a*ano.b + this->b*ano.a;
	return Complex(a,b);
}
	
Complex Complex::operator/(const Complex &ano) const
{
	if( ano.GetMod() < 1e-6 ){
		cerr << "dividend can't be zero!" << endl;	//��������ģ����Ϊ0 
		return Complex();
	}
	double div = ano.a*ano.a + ano.b*ano.b;
	double a = (this->a*ano.a + this->b*ano.b) / div;
	double b = (this->b*ano.a - this->a*ano.b) / div;
	return Complex(a,b);
}

Complex& Complex::operator+=(const Complex &ano)
{
	this->a += ano.a;
	this->b += ano.b;
	return *this;
}

Complex& Complex::operator-=(const Complex &ano)
{
	this->a -= ano.a;
	this->b -= ano.b;
	return *this;
}

Complex Complex::pow(int n) const
{
	Complex res = *this;
	while(--n)
		res = (*this) * res;	
	return res;
}			
