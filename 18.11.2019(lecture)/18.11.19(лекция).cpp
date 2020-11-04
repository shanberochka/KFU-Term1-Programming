#include<iostream>
using namespace std;
/////////////////////////////////
void create_set(int* x, int n)
{
	int i, m;
	for (i = 0; i < n; i++)
		x[i] = 0;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "enter element of set m=";
		cin >> m;
		x[m] = 1;
		cout << " continue enter element? - 'y'/'n' ch=";
		cin >> ch;
	}
}
////////////////////////////////
void show_set(int* x, int n)
{
	int i;
	cout << "{ ";
	for (i = 0; i < n - 1; i++)
		if (x[i]) cout << i << ", ";
	cout <<   "} " << endl;
}
////////////////////////////////////
void Union(int* x, int* y, int* z, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		z[i] = x[i] || y[i];
}
////////////////////////////////
void intersection(int* x, int* y, int* z, int n)
{
	int i;
	for (i = 0; i < n; i++)
		z[i] = x[i] && y[i];
}
////////////////////////////////
void substruction(int* x, int* y, int* z, int n)
{
	int i;
	for (i = 0; i < n; i++)
		z[i] = x[i] && !y[i];
}
////////////////////////////////
void complement(int* x, int* y, int n)
{
	int i;
	for (i = 0; i < n; i++)
		y[i] = !x[i];
}
////////////////////////////////
int main()
{
	int n;
	cout << " ALGEBRA OF SETS" << endl;
	cout << "enter size universal set n=";
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	cout << "enter elements of set a: " << endl;
	create_set(a, n);
	cout << "elements of set a: " << endl;
	show_set(a, n);
	cout << "enter elements of set b: " << endl;
	create_set(b, n);
	cout << " elements of set b: " << endl;
	show_set(b, n);
	Union(a, b, c, n);
	cout << " elements of set c=aUb: " << endl;
	show_set(c, n);
	intersection(a, b, c, n);
	cout << " elements of set c=a*b: " << endl;
	show_set(c, n);
	substruction(a, b, c, n);
	cout << " elements of set c=a-b: " << endl;
	show_set(c, n);
	complement(a, c, n);
	cout << " elements of set c=!a: " << endl;
	show_set(c, n);
	// Проверим правила де Моргана. Второй вариант: функции возвращают указатели на вычисленное множество
	
	system("pause");
	return 0;
}