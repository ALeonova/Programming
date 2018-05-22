#include <iostream>
#include <string>

//to file
#include <fstream>

using namespace std;

class shape
{
public:
	shape(){}
	virtual void draw(ostream& out) = 0;
	virtual void input() = 0;
	virtual int getsize() = 0;
	virtual ~shape(){}
};

class line : public shape
{
protected:
	int len;
	bool hor;
public:
	line(int l, bool h)
		:len(l), hor(h)
	{}
	line(){}
	virtual int getsize()
	{
		return len;
	}
	virtual void draw(ostream& out)
	{
		if(hor)
		{
			for(int i = 0; i<len; i++)
			{
				out << "*";
			}
		}
		else
		{
			for(int i = 0; i<len; i++)
			{
				out << "*" << endl;
			}	
		}
		out<<endl;
	}
	virtual void input()
	{
		cout << "Length:" << endl;
		cin >> len;
		cout << "bHor:" << endl;
		cin >> hor;
	}
	virtual ~line(){}
};

class rect : public shape
{
protected:
	int w;
	int h;
public:
	rect(int W, int H)
		:w(W), h(H)
	{}
	rect(){}
	virtual int getsize()
	{
		return w;
	}
	virtual void draw(ostream& out)
	{
		for(int i = 0; i<w; i++)
		{
			out << "*";
		}
		out<<endl;
		for(int j = 0; j<h-2; j++)
		{
			out <<"*";
			for(int k=0;k<w-2; k++)
			{
				out <<" ";
			}
			out <<"*"<< endl;
		}
		for(int i = 0; i<w; i++)
		{
			out << "*";
		} 
		out<<endl;
	}
	virtual void input()
	{
		cout << "W:" << endl;
		cin >> w;
		cout << "H:" << endl;
		cin >> h;
	}
	virtual ~rect(){}
};

class triangle : public shape
{
protected:
	int w;
	int h;
public:
	triangle(int W, int H)
		:w(W), h(H)
	{}
	triangle(){}
	virtual int getsize()
	{
		return w;
	}
	virtual void draw(ostream& out)
	{
		for(int i = 0; i<w; i++)
		{
			out << "*";
		} 
		out << endl;
		for(int j = 0; j<h-2; j++)
		{
			for(int k=0; k<j+1; k++)
			{
				out<< " ";
			}
			out <<"*";
			for(int k=0;k<w-2*j-4; k++)
			{
				out <<" ";
			}
			out << "*" << endl;
		}
	}
	virtual void input()
	{
		cout << "W:" << endl;
		cin >> w;
		cout << "H:" << endl;
		cin >> h;
	}
	virtual ~triangle(){}
};

class square : public rect
{
public:
	square(int W)
		:rect(W, W)
	{}
	square(){}
	virtual void input()
	{
		cout << "W:" << endl;
		cin >> w;
	}
	virtual ~square(){}
};

int main()
{
	line l(10, true);
	rect r(5, 6);
	triangle t (8,5);
	square s(4);
	l.draw(cout);
	r.draw(cout);
	t.draw(cout);
	s.draw(cout);

	shape* sh[10];
	sh[0]=new line(10,true);
	sh[1]=new line(2,true);
	sh[2]=new line(20,false);
	sh[3]=new line(10,true);
	sh[4]=new square(10);
	sh[5]=new rect(10,7);
	sh[6]=new triangle(10,17);
	sh[7]=new triangle(10,7);
	sh[8]=new square(23);
	sh[9]=new triangle(20,13);
	
	line* l1 = new line(10,true);
	shape* l2 = &l;
	line* l3 = l1;
	
	shape& ss = l;
	ss.draw(cout);
	
	for(int i=0; i<10; i++)
	{
		for(int j=i+1; j<10; j++)
		{
			if(sh[j]->getsize()< sh[i]->getsize())
			{
				shape* tmp = sh[i];
				sh[i] = sh[j];
				sh[j] = tmp;
			}
		}
	}
	
	
	for(int i=0; i<10; i++)
	{
		cout << sh[i]->getsize()<<endl;
		sh[i]->draw(cout);
	}
	ofstream out("file.txt");
	out << "fils\koaakflsdldldldldld;s;s;p "<<endl;
	//ifstream in("input.txt");
	{
		//app добавляет в конец файла
		ofstream o("fd.txt", ios::app);
		o<<"что-то"<< endl; 
	}
	
	{
		ifstream i("fd.txt");
		string s;
		i >> s;
		cout << s;
	}
		
	for(int i=0; i<10; i++)
	{
		out << sh[i]->getsize()<<endl;
		sh[i]->draw(out);
	}
	for(int i=0; i<10; i++)
	{
		delete sh[i];
	}
	return 0;
}
