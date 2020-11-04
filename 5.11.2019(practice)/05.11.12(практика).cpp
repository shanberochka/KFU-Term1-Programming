#include <iostream>
#include <iomanip>
using namespace std;

int* Create_mas(int n)
{
	cout << "Creating the massive" << endl;
	int i;
	int* z = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "x[" << i << "]=";
		cin >> z[i];
	}
	return z;
}

bool Is_prime(int x)
{
	bool isPrime = true;
	for (int i = 2; i <= (sqrt(abs(x))); i++)
	{
		if (x % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

bool E_prime(int *a,int n)
{
	cout << "Checking is massive contain prime element" << endl;
	bool Res = false;
	for (int i = 0; i < n; i++)
	{
		Res = Res || Is_prime(a[i]);
	}
	if (Res){ return true; }
	else { return false; }
}
bool Even_number(int x)
{
	if (x % 2==0) { return true; }
	else { return false; }
}
bool A_even(int* a, int n)
{
	cout << "Cheking are all elements are prime" << endl;
	bool Res = true;
	for (int i = 0; i < n; i++)
	{
		Res = Res && Even_number(a[i]);
	}
	if (Res) { return true; }
	else { return false; }
}
int Even_sum(int* a, int n)
{
	cout << "Calculate sum of even elements" << endl;
	int evenSum = 0;
	for(int i=0;i<n;i++)
		if (Even_number(a[i])) { evenSum += a[i]; }
	return evenSum;
}
int* Shift(int* a, int n)
{
	cout << "Shift to the right" << endl;
	int* b = new int[n];
	b[0] = a[n-1];
	for (int i = 0; i < n-1; i++)
	{
		b[i + 1] = a[i];
	}
	return b;
}
int* Mult_num(int* a, int n, int c)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = c * a[i];
	}
	return a;
}
void Show_mas(int* a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
			cout << a[i] << " ";
		cout << endl;
	}
}

int main()
{
	int n,k;
	cout << "Enter the size of array:";
	cin >> n;

	int* mas = Create_mas(n);
	if (A_even(mas, n)) { mas = Shift(mas, n); Show_mas(mas, n); }
	else
	{
		if (E_prime(mas, n))
		{
			swap(mas[1], mas[2]);
			Show_mas(mas, n);
		}
	}
	cout << "\n Enter the number to multipling:";
	cin >> k;
	mas = Mult_num(mas, n, k);
	Show_mas(mas, n);
}
