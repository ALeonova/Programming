#include "matrix.h"

cMatrix::cMatrix()
{
    width = 5;
    height = 5;
    values = new double*[height];
    for(int i = 0; i < height; i++)
        values[i] = new double[width];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            values[i][j] = i*width + j;
}

cMatrix::cMatrix(int h, int w)
{
    width = w;
    height = h;
    values = new double*[height];
    for(int i = 0; i < height; i++)
        values[i] = new double[width];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            values[i][j] = i*width + j;
}

cMatrix::cMatrix(int h, int w, double value)
{
    width = w;
    height = h;
    values = new double*[height];
    for(int i = 0; i < height; i++)
        values[i] = new double[width];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            values[i][j] = value;
}

cMatrix::cMatrix(const cMatrix &other)
{
    width = other.width;
    height = other.height;
    values = new double*[height];
    for(int i = 0; i < height; i++)
        values[i] = new double[width];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            values[i][j] = i*width + j;
}

cMatrix::~cMatrix()
{
    for(int i = 0; i < height; i++)
        delete []values[i];
    delete []values;
}

void cMatrix::print()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            cout<<values[i][j]<<" ";
        cout<<endl;
    }
}

cMatrix cMatrix::operator +(const cMatrix& other)
{
    if(width != other.width || height != other.height)
    {
        cout<<"Error! Sizes are different!\n";
        exit(1);
    }
    cMatrix tmp(height, width);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            tmp.values[i][j] = values[i][j] + other.values[i][j];
    return tmp;
}

void cMatrix::operator *=(double k)
{
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            values[i][j] = values[i][j]*k;
}

cMatrix cMatrix::operator *(double k)
{
    cMatrix tmp(height, width);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            tmp.values[i][j] = values[i][j]*k;
    return tmp;
}

void cMatrix::operator =(const cMatrix& other)
{
	if(	(height != other.height) || (width != other.width))
	{
	    for(int i = 0; i < height; i++)
    	    delete []values[i];
    	delete []values;
	    width = other.width;
	    height = other.height;
	    values = new double*[height];
	    for(int i = 0; i < height; i++)
	        values[i] = new double[width];
	}

    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            values[i][j] = other.values[i][j];
}

ostream &operator<<(ostream& out, const cMatrix& matrix)
{
    for(int i = 0; i < matrix.height; i++)
    {
        for(int j = 0; j < matrix.width; j++)
            cout<<matrix.values[i][j]<<" ";
        cout<<endl;
    }
    return out;
}

double cMatrix::getElement(int h, int w)
{
    if(h >= 0 && w >= 0 && h < height && w < width)
        return values[h][w];
    else
    {
        cout<<"Error! Out of range!\n";
        return -1;
    }
}

void cMatrix::setElement(int h, int w, double value)
{
    if(h >= 0 && w >= 0 && h < height && w < width)
        values[h][w] = value;
    else
    {
        cout<<"Error! Out of range!\n";
    }
}

void cMatrix::operator *=(const cMatrix& other)
{
	operator = ((*this) * other);
}

cMatrix cMatrix::operator*(const cMatrix &other)
{
    cMatrix tmp(height, other.width, 0);
	if(	(height != other.width) || (width != other.height))
    {
        cout<<"Error! Wrong sizes!\n";
        return tmp;
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < other.width; j++)
        {
        	for(int k = 0; k<width; k++)
        	{
        		tmp.values[i][j] += values[i][k]*other.values[k][j];
			}
		}
    }
	return tmp;
}

bool cMatrix::operator ==(const cMatrix& other)
{
	if(	(height != other.height) || (width != other.width))
		return false;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            if (values[i][j] != other.values[i][j])
            	return false;
    }
    return true;
}

cMatrix cMatrix::transpose()
{
    cMatrix tmp(width, height);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            tmp.values[i][j] = values[j][i];
    }
    return tmp;
}

double cMatrix::algdop(int i, int j)
{
	cMatrix tmp(height-1, width-1);
    for(int ii=0; ii<height-1; ii++)
	{
		int iii = ii;
		if(ii>=i)
			iii++;						
		for(int jj=0; jj<width-1; jj++)
		{
			int jjj = jj;
			if(jj>=j)
				jjj++;						
			tmp.values[ii][jj] = values[iii][jjj];
		}
	}
    if((i+j) % 2)
		return -tmp.determinant();
	else
		return tmp.determinant();
}

double cMatrix::determinant()
{
	double d = 0;	
	if(height != width)
    {
        cout<<"Error! Wrong sizes!\n";
        return d;
    }
    if(height == 1)
    	return values[0][0];
    if(height == 2)
    	return values[0][0]*values[1][1]-values[0][1]*values[1][0];
    
	cMatrix tmp(height-1, width-1);
	for(int j=0; j<width; j++)
	{
		d += values[0][j]*algdop(0, j);
	}
	
	return d;
}

cMatrix cMatrix::inverse()
{
    cMatrix tmp(width, height);
	if(height != width)
    {
        cout<<"Error! Wrong sizes!\n";
        return tmp;
    }	
    double d = determinant();
    if(d == 0)
    {
        cout<<"Error! Determinant = 0!\n";
        return tmp;
    }	

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        	tmp.values[i][j] = algdop(i, j);
    }    
    return tmp.transpose()*(1/d);
	
	return tmp;
}

cMatrix cMatrix::chetnie()
{
	int k=0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            if(j % 2 == 0)
            {
            	k=k+values[i][j];
				cout<<values[i][j]<<"	";
        	}
    }
    cout<<endl;
    cout<<k;
    }
