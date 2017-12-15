#include <iostream>
using namespace std;

class Matrix
{
	private:
		int m, n;
		int **p;
	public:
		Matrix();
		Matrix(int x);
		Matrix(int m, int n);
		void setVal(int m, int n); //Method to set the val of [i,j]th-entry
		void printMatrix(); //Method to display the matrix
		~Matrix(); //Destructor

		//allocate the array
		void allocArray()
		{
			p = new int*[m];
			for(int i = 0; i < m; i++)
			{
				p[i] = new int[n];
			}
		}	
};

//Default constructor
Matrix :: Matrix() { }

Matrix :: Matrix(int x)
{
	m = x;
	n = x;
}

//Main construcor
Matrix::Matrix(int m, int n)
{
	allocArray();
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			p[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	for(int i = 0; i < m; i++)
	{
		delete [] p[i];
	}
	delete [] p;
}

//SetVal function
void Matrix :: setVal(int m, int n)
{
	int newVal = 0;
	p[m][n] = newVal;
}

//printMatrix function
void Matrix::printMatrix()
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << p[m][n] << "  " << endl;
		}
	}
}


int main()
{
	int d1 = 4;
	int d2 = 3;

	Matrix object;

	//create 4x3 dynamic 2d array
	int ** matrix = new int*[d1];
	for(int j = 0; j < d1; j++)
	{
		matrix[j] = new int[d2];
	}

	//fill array
	cout << "Enter values " << endl;
	for(int i = 0; i < d1; ++i)
	{
		for(int j = 0; j < d2; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	object.printMatrix();

	return 0;
}
