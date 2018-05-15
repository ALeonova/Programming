class Base
{
};

class Derived: public Base
{
	
};


Derived *pD1 = new Derived;
Base* pB1 = new Base;

Derived d2;
Base b2;

pB1 = pD1;
pD1 = (Derived*)pB1;
b2 = (Base)d2;
//d2 = b2;

