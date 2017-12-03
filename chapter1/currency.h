// currency class using  a single data member
// (amount) represent an instance

#ifndef currency_
#define currency_

#include <iostream>
#include <exception>

using namespace std;

enum signType { pos, neg };

class currency
{
public:
	// constructor
	currency(signType theSign = pos,
		unsigned long theDollars = 0,
		unsigned int theCents = 0);
	// destructor
	~currency() {}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	currency& input() ;
	signType getSign() const
	{
		if (amount < 0) return neg;
		else return pos;
	}
	unsigned long getDollars() const
	{
		if (amount < 0) return (-amount) / 100;
		else return amount / 100;
	}
	unsigned int getCents() const
	{
		if (amount < 0) return -amount - getDollars() * 100;
		else return amount - getDollars() * 100;
	}
	currency add(const currency&) const;
	currency subtract(const currency&) const;
	currency& increment(const currency& x)
	{
		amount += x.amount; return *this;
	}
	currency percent(double x);
	currency multiply(double x)
	{
		currency y;
		y.amount = amount * x;
		return y;
	}
	currency divide(double x)
	{
		currency y;
		y.amount = amount / x;
		return y;
	}

	void output() const;
private:
	long amount;
};

currency::currency(signType theSign, unsigned long theDollars,
	unsigned int theCents)
{// Create a currency object.
	setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,
	unsigned int theCents)
{// Set currency value.
	if (theCents > 99)
		// too many cents
		throw invalid_argument("Cents should be < 100");

	amount = theDollars * 100 + theCents;
	if (theSign == neg) amount = -amount;
}

void currency::setValue(double theAmount)
{// Set currency value.
	if (theAmount < 0)
		amount = (long)((theAmount - 0.001) * 100);
	else
		amount = (long)((theAmount + 0.001) * 100);
	// 2 decimal digits only
}

currency currency::add(const currency& x) const
{// Add x and *this.
	currency y;
	y.amount = amount + x.amount;
	return y;
}

currency currency::subtract(const currency& x) const
{
	currency y;
	y.amount = amount -x.amount;
	return y;
}

void currency::output() const
{// Output currency value.
	long theAmount = amount;
	if (theAmount < 0) {
		cout << '-';
		theAmount = -theAmount;
	}
	long dollars = theAmount / 100; // dollars
	cout << '$' << dollars << '.';
	int cents = theAmount - dollars * 100; // cents
	if (cents < 10) cout << '0';
	cout << cents;
}

currency& currency::input()
{
	double amount;
	cout << "请输入金额:" << endl;
	cin >> amount;
	this->setValue(amount);
	return *this;
}

currency currency::percent(double x)	//注意是返回对象而非返回引用,这里是局部对象,返回引用会导致错误
{
	if (x > 100 && x < 0)
	{
		throw invalid_argument("argument range error!");
	}
	currency y;
	y.amount = amount * x / 100;
	return y;
}

#endif

