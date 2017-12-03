#include <iostream>
#include "currency.h"
using namespace std;

int main()
{


	//1-17 1
	/*
	currency c1;
	c1.input();
	c1.output();*/

	//2
	/*currency c1, c2;
	c1.setValue(233.33);
	c2.setValue(233);
	c1.subtract(c2).output();*/

	//3
	//currency c1, c2;
	//c1.setValue(100);
	//c2 = c1.percent(12);
	//c2.output();

	//4,5
	currency c1, c2;
	c1.setValue(100);
	c2 = c1.multiply(12);
	c2.output();
	c2 = c1.divide(10);
	c2.output();
	return 0;
}