#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include <iostream>
using namespace std;




class human
{
protected:
    string name;
    string surname;
    string second_name;
    bool gender;
public:
    human()
    {
        name="";
        surname="";
        second_name="";
        gender=true;
    }
    human(string name, string surname, string second_name, bool gender)
    {
        cout<<" Constructor H ";
        this->name = name;
        this->second_name = second_name;
        this->surname = surname;
        this->gender = gender;
    }
    human(const human& other)
    {
        name = other.name;
        second_name = other.second_name;
        surname = other.surname;
        gender = other.gender;
    }
    void print()
    {
        cout<<"Human: "<<name<<" "<<second_name<<" "<<surname<<" "<<gender<<"\n";
    }
};




class student : public human
{
    int studentID;
public:
    student():human()
    {
        studentID=-1;
    }
    student(string name, string surname, string second_name,
            bool gender, int studentID):human(name, surname, second_name, gender)
    {
        cout<<" Constructor S ";
        this->studentID = studentID;
    }
    student(const student &other)
    {
        name = other.name;
        surname = other.surname;
        second_name = other.second_name;
        gender = other.gender;
        studentID = other.studentID;
    }
    void print()
    {
        cout<<"Student: "<<name<<" "<<second_name<<" "<<surname<<" "<<gender<<" "<<studentID<<"\n";
    }
};




class teacher: protected human
{
protected:
    double payment;
public:
    teacher():human()
    {
        payment = 0;
    }

    teacher(string name, string surname, string second_name,
            bool gender, double payment):human(name, surname, second_name, gender)
    {
        cout<<" Constructor T ";
        this->payment = payment;
    }
    void print()
    {
        cout<<"Teacher: "<<name<<" "<<second_name<<" "<<surname<<" "<<gender<<" "<<payment<<"\n";
    }
};




class professor: public teacher
{
    bool degree;
public:
    professor():teacher()
    {
        degree = true;
    }
    professor(string name, string surname, string second_name,
              bool gender, double payment, bool degree): teacher(name, surname, second_name, gender, payment)
    {
        cout<<" Constructor P ";
        this->degree = degree;
    }
    void print()
    {
        cout<<"Professor: "<<name<<" "<<second_name<<" "<<surname<<" "<<gender<<" "<<payment<<" "<<degree<<"\n";
    }
};

#endif // PEOPLE_H
