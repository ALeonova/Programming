#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
using namespace std;
class cMatrix
{
    friend ostream &operator<<(ostream & out, const cMatrix & matrix);
private:
    int width;
    int height;
    double **values;
public:
    cMatrix();
    cMatrix(int h, int w);
    cMatrix(int h, int w, double value);
    cMatrix(const cMatrix& other);
    ~cMatrix();
    void print();
    cMatrix operator +(const cMatrix& other);
    void operator *=(double k);
    cMatrix operator*(double k);
    void operator =(const cMatrix& other);
    inline int getHeight(){return height;}
    inline int getWidth(){return width;}
    double getElement(int h, int w);
    //TODO: методы, которые необходимо реализовать
    void setElement(int h, int w, double value);
    void operator *=(const cMatrix& other);
    cMatrix operator*(const cMatrix &other);
    bool operator ==(const cMatrix& other);
    cMatrix transpose();//транспонирование матрицы
    //методы, которые необходимо реализовать дл€ получени€ + сразу за две лабы
    double determinant();//определитель матрицы
    cMatrix inverse();//обратна€ матрица
    double algdop(int i, int j);
    
    cMatrix chetnie();
};

#endif // CMATRIX_H

