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
		friend istream& operator>>(istream& is, Complex& c);		//输入 
		friend ostream& operator<<(ostream& os, const Complex& c);	//输出 
		
		Complex():a(0.0),b(0.0) {}	//无参构造函数 
		Complex(double _a, double _b):a(_a),b(_b) {}	//有参构造函数 
		
		Complex operator+(const Complex &ano) const;	//加 
		Complex operator-(const Complex &ano) const;	//减	
		Complex operator*(const Complex &ano) const;	//乘	
		Complex operator/(const Complex &ano) const;	//除 
		Complex pow(int n) const;					//幂次方 
		Complex& operator+=(const Complex &ano);	//自加 
		Complex& operator-=(const Complex &ano);	//自减			
		
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
	
	cout << "c1+c2：" << c1+c2;
	cout << "c1-c2：" << c1-c2;
	cout << "c1*c2：" << c1*c2;
	cout << "c1/c2：" << c1/c2;
	cout << "c1的立方：" << c1.pow(3); 
	
	return 0;
}

istream& operator>>(istream& is, Complex& c)
{
	double a, b;
	cout << "请输入复数的实部：";
	is >> a;
	cout << "请输入复数的虚部：";
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
	/* 输出实部 */
	if( fabs(a) > 1e-6 ){
		os << a;
		if( b > 1e-6){
			os << "+";		//	虚部为正数 
		}	
	}
	/* 输出虚部 */
	if( b<1e-6 && fabs(b)>1e-6){
		os << "-";			//	虚部为负数 
	}
	b = fabs(b);
	if( b > 1e-6 ){			//	虚部不为0	
		if( b-1 > 1e-6 ){	//	虚部不为-1或1才输出 
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
		cerr << "dividend can't be zero!" << endl;	//被除数的模不能为0 
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
