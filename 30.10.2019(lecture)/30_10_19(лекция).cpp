
#include <iostream>
#include <iomanip>
using namespace std;
int** mult(int**, int**, int );
int** add(int**, int**, int );
int** create(int);
void show(int** z, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(6) << z[i][j];
		cout << endl;
	}
}
void del(int** x, int** y, int n)
{
	int i;
	for (i = 0; i < n; i++)
		delete[] x[i];
	delete x;
}

int main()
{
	int n;
	cout << "enter size of array: n=";
	cin >> n;
	cout << "enter array a:" << endl;
	int** a = create(n);
	cout << "enter array b:" << endl;
	int** b = create(n);
	cout << "array a:" << endl;
	show(a, n);
	cout << "array b:" << endl;
	show(b, n);

	int** c = add(mult(a, b, n), a, n);
	cout << "Array c:" << endl;
	show(c, n);
}

int** mult(int** x, int** y, int n)
{
	int i, j, k;
	int** z = new int*[n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			z[i][j] = 0;
			for (k = 0; k < n; k++)
				z[i][j] = z[i][j] + x[i][k] * y[k][j];
		}
	return z;
}
int** add(int** x, int** y, int n)
{
	int i, j;
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			z[i][j] = x[i][j] + y[i][j];
	return z;
}
int** create(int n)
{	
	int i,j;
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++)
		{
			cout << "x["<<i<<"]["<<j<<"]=" ;
			cin >> z[i][j];
		}
	return z;
}

