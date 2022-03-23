#include <iostream>

using namespace std;
class CFract
{
    private:
        int a, b;
        
        int Nod(int, int) const;
    public:

        CFract();
        CFract(int a, int b);
        CFract operator -();
        CFract operator +(const CFract op1) const;
        CFract operator -(const CFract op1) const;
        CFract operator *(const CFract op1) const;
        CFract operator /(const CFract op1) const;
        CFract& operator =(const CFract& op1);
        int GetA() const {return a;}
        int GetB() const {return b;}
};
CFract::CFract()
{
    a = 0;
    b = 1;
}
CFract::CFract( int a, int b)
{
    this -> a = a;
    this -> b = b;
}
int
CFract::Nod(int a, int b) const
{
    int tmp;
    if(b == 0) return a;
    if(a < b)
    {
       tmp = a;
       a = b;
       b = tmp;
    }
    return Nod(a - b, b);
}

CFract
CFract::operator +(const CFract op1) const
{
    CFract result;
    int nd;
    result.b = b*op1.b / Nod(b, op1.b);
    
    result.a = a * op1.b / Nod(b, op1.b) + op1.a * b / Nod(b, op1.b);
    
    nd = Nod(abs(a), b);
    result.a /= nd;
    result.b /= nd;
    
    return result;
}
CFract
CFract::operator -(const CFract op1) const
{
    CFract result;
    int nd;
    result.b = b*op1.b / Nod(b, op1.b);
    result.a = a * op1.b / Nod(b, op1.b) - op1.a * b / Nod(b, op1.b);
    nd = Nod(abs(a), b);
    result.a /= nd;
    result.b /= nd;
    return result;
}
CFract
CFract::operator *(const CFract op1) const
{
    CFract result;
    int nd;
    result.b = b * op1.b;
    result.a = a * op1.a;
    nd = Nod(abs(a), b);
    result.a /= nd;
    result.b /= nd;
    return result;
}
CFract
CFract::operator /(const CFract op1) const
{
    CFract result;
    int nd;
    result.b = a * op1.b;
    result.a = b * op1.a;
    nd = Nod(abs(a), b);
    result.a /= nd;
    result.b /= nd;
    return result;
}
CFract&
CFract:: operator =(const CFract& op1)
{
	if(this == &op1) return *this;
	a = op1.a;
	b = op1.b;
	return *this;
}

ostream& operator <<(ostream &os, const CFract &myos)
        {
			return os << myos.GetA() << '/' <<myos.GetB();
		}


int main()
{
    CFract op1(1, 2), op2(1, 3), res;
    res = op1 + op2;
    cout << "суммма:" << endl;
    cout << res << endl;
    res = op1 - op2;
    cout << "разность:" << endl;
    cout << res << endl;
    res = op1 * op2;
    cout << "произведение:" << endl;
    cout << res << endl;
    res = op1 / op2;
    cout << "частное:" << endl;
    cout << res << endl;
    return 0;
}
