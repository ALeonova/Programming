#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    cMatrix A;
    cMatrix B(5,5);
    cout<<"Matrix A:\n";
    A.print();
    cout<<"Matrix B:\n";
    B.print();
    cout<<"Matrix C = A+B:\n";
    cMatrix C;
    C = A+B;
    C.print();
    cout<<"Multiple matrix C x3:\n";
    C*=3;
    C.print();
    cout<<"Matrix A = C*2:\n";
    A = C*2;
    A.print();
    cout<<A.getWidth()<<"\n";
    cout<<"Print matrix A through ostream:\n";
    cout<<A<<"\n\n"<<B;
    cout<<"\nGet element 7,7 from matrix A:\n";
    cout<<A.getElement(7,7) << endl;
    
    cMatrix D;
    D = A*B;
    cout << D << endl;
    A *= B;
    cout << A << endl;
    if (A == D)
    {
    	cout << "A = D" << endl;
	}
	
	
	cMatrix E(4, 4);
	E.setElement(0, 0, 1);
	E.setElement(1, 3, 7);
	E.setElement(2, 0, 111);
	E.setElement(3, 2, 2);
	cout << A.transpose() << endl;
	cout << E << endl;
	cout << E.determinant() << endl;
	cout << E.inverse() << endl;
	
	E.chetnie(); 
	return 0;
}


