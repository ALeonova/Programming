#include <iostream>
#include <string>

using namespace std;

class video
{
protected:
	string m_name;
	int m_year;

public:
	video(string name, int year)
		:m_name(name), m_year(year)
	{}
	video():
		m_year(0)
	{}

	virtual void print() = 0;
	virtual void input() = 0;
	virtual ~video(){}
};

class serial
{
protected:
	int m_seasons;
public:
	serial(int seasons)
		:m_seasons(seasons)
	{}
	serial()
		:m_seasons(0)
	{}
	virtual ~serial(){}
};

class film : public video
{
protected:
	string 	m_director;
public:
	film(string name, int year, string director)
		:video(name, year), m_director(director)
	{}
	film(){}
	virtual void print()
	{
		cout << "Film:  " << m_name << "\n" << "\tYear:\t" << m_year << "\n" << "\tDirector: " << m_director << "\n" << endl;
	}
	virtual void input()
	{
		cout << "Name:" << endl;
		cin >> m_name;
		cout << "Year:" << endl;
		cin >> m_year;
		cout << "Director:" << endl;
		cin >> m_director;
	}
	virtual ~film(){}
};

class cartoon : public video
{
protected:
	string 	m_artist;
public:
	cartoon(string name, int year, string artist)
		:video(name, year), m_artist(artist)
	{}
	cartoon(){}
	virtual void print()
	{
		cout << "Cartoon: " << m_name << "\n" << "\tYear:\t" << m_year << "\n" << "\tArtist:\t" << m_artist << "\n" << endl;
	}
	virtual void input()
	{
		cout << "Name:" << endl;
		cin >> m_name;
		cout << "Year:" << endl;
		cin >> m_year;
		cout << "Artist:" << endl;
		cin >> m_artist;
	}
	virtual ~cartoon(){}
};

class anime : public cartoon, public serial
{
public:
	anime(string name, int year, string artist, int seasons)
		:cartoon(name, year, artist), serial (seasons) 
	{}
	anime(){}
	virtual void print()
	{
		cout << "Anime:   " << m_name << "\n" << "\tYear:\t" << m_year << "\n" << "\tArtist:\t" << m_artist << "\n" << "\tSeasons:  " << m_seasons << "\n" << endl;
	}
	virtual void input()
	{
		cartoon::input();
		cout << "Seasons:" << endl;
		cin >> m_seasons;
	}
	virtual ~anime(){}
};

const int MAX_VIDEO=100;
class videoteka
{

	int m_number;
	video* m_videos[MAX_VIDEO];
public:
	videoteka()
		:m_number(0)
	{
	}
	~videoteka()
	{
		for(int i = 0; i<m_number; i++)
		{
			delete m_videos[i];
		}
	}
	void input_and_add(video* v)
	{
		v->input();
		add(v);
	}
	void add(video* v)
	{
		if(m_number < MAX_VIDEO)
		{
			m_videos[m_number++] = v;
		}
		else
		{
			delete v;
		}
	}
	void print()
	{
		cout << "Videoteka:" << endl;
		for(int i = 0; i<m_number; i++)
		{
			cout << i << ":\t";
			m_videos[i]->print();
		}
	}
	void edit(int n)
	{
		if(n>=0 && n<m_number)
			m_videos[n]->input();
	}
};

int menu()
{
	cout << "\n0: Print all\n1: Add film\n2: Add cartoon\n3: Add anime\n4: Edit\n5: Exit" << endl;
	int n;
	cin >> n;
	return n;
}

int main()
{
	videoteka v;
	v.add(new film("Pulp Fiction ", 1994, "Quentin Tarantino"));
	v.add(new film("Avengers: Infinity War", 2018, " Anthony Russo, Joe Russo"));
	v.add(new cartoon("Finding Nemo", 2003, "Ralph Eggleston"));
	v.add(new cartoon("WALL-E", 2008, "Ralph Eggleston, Bert Berry"));
	v.add(new anime("Death Note", 2006, "Takeshi Obata", 2));
	v.add(new anime("Attack on Titan", 2013, "Shunichiro Yoshihara", 3));

	v.print();		

	int n = 0;
	while(true)
	{
		switch(menu())
		{
			case 0:
				v.print();
				break;

			case 1:
				v.input_and_add(new film());
				break;

			case 2:
				v.input_and_add(new cartoon());
				break;

			case 3:
				v.input_and_add(new anime());
				break;
				
			case 4:
				cout << "Number:" << endl;
				cin >> n;
				v.edit(n);
				break;
						
			case 5:
				return 0;
		}
	}

}

