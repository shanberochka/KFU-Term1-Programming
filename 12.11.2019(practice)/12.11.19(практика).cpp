
#include <iostream>
#include <iomanip>
using namespace std;

const int n = 3;
int i, j;

int** create()
{
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "x[" << i << "][" << j << "]=";
			cin >> z[i][j];
		}
	return z;
}
void show(int** z)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(6) << z[i][j];
		cout << endl;
	}
	cout << endl;
}
int** Shift(int** a)
{
	cout << "Shift to the left\n";
	int** b = new int* [n];
	for ( i = 0; i < n; i++)
		b[i] = new int[n];
	for (i = 0; i < n; i++)
	{
		b[i][n-1] = a[i][0];
	}
	for (j = 0; j < n-1;j++)
		for (i = 0; i < n; i++)
		{
			b[i][j] = a[i][j + 1];
		}
	return b;
}
void Swap(int** a, int x, int y)
{
	cout << "Swap\n";
	for (i = 0; i < n; i++)
	{
		swap(a[i][x], a[i][y]);
	}
}
int Max_Col(int** a)
{
	int max_sum = 0;
	int max_ind = 0;
	int sum;
	for (j = 0; j < n; j++)
	{
		sum = 0;
		for (i = 0; i < n; i++)
		{
			sum += a[i][j];
		}
		max_sum < sum ? max_sum = sum, max_ind = j : 0;
	}
	return max_ind;
}
int Min_Row(int** a)
{
	int min_sum=0;
	int min_ind = 0;
	for (j = 0; j < n; j++)
	{
		min_sum += a[0][j];
	}
	for (i = 1; i < n; i++)
	{
		int sum = 0;
		for (j = 0; j < n; j++)
		{
			sum += a[i][j];
		}
		min_sum > sum ? min_sum = sum, min_ind = i : 0;
	}
	return min_ind;
}
void Positiv_on_diag(int** a)
{
	int k = 0;
	cout << "\nPositive element on the diagonal: ";
	for (i = 0; i < n; i++)
		if (a[i][i] > 0) { cout << a[i][i] << " "; }
		else k++;
	if (k == n) cout << "no positive elements. ";
}
void Index_of_min(int** a)
{
	cout << "\nIndexes of minimal value in array: ";
	int min = a[0][0];
	for (i=0;i<n;i++)
		for (j = 0; j < n; j++)
		{
			min > a[i][j] ? min = a[i][j] : 0; // Ищем значение минимального элемента в массиве. Сохраним его в min
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] == min) { cout  << "\n\t" << i << "; " << j << "\t"; }
}
void Сonv_to_str(int** matrix, int* str)
{
	int k = 0;
		for (j=0;j<n;j++)
			for (i = 0; i < n; i++)
			{
				str[k] = matrix[i][j];
				k++;
			}				
}
void Max_in_each_col(int** a)
{
	
	for (j = 0; j<n;j++)
	{ 
		int max = a[0][j];
		for (i = 0; i < n; i++)
		{
			max < a[i][j] ? max = a[i][j] : 0;
		}
		cout << "\nMax in " << j << " column: " << max;
	}
}
void Where_3k(int** a,int k)
{
	cout << "Rows where " << k << " meets more than twice: " << "\n";
	int count;
	for (i = 0; i < n; i++)
	{
		count=0;
		for (j = 0; j < n; j++)
			if (a[i][j] == k) count++;
		if (count > 2) { cout << i << " "; }
	}
	cout << endl;
}
int** Big_matrix(int** a, int** b)
{
	cout << "\nBig matrix:\n";
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (a[i][j] > b[i][j]) { z[i][j] = a[i][j]; }
			else { z[i][j] = b[i][j]; }
		}
	return z;
}
void Last_in_row_is_sum()
{
	cout << "This function create matrix in which last element in each row is sum of previous elements\n";
	cout << "Enter the matrix:\n";
	int** z = new int* [n];
	for (i = 0; i < n; i++)
		z[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n-1; j++)
		{
			cout << "x[" << i << "][" << j << "]=";
			cin >> z[i][j];
		}
	for (i = 0; i < n; i++)
		{
			z[i][n-1] = 0;
			for (j = 0; j < n - 1; j++)
				z[i][n-1] += z[i][j];
		}
	show(z);
}
void Swap_diag(int** a)
{
	for (i = 0; i < n; i++)
		swap(a[i][i],a[i][n - 1 - i]);
}
int F_12(int** a)
{
	cout << "\nЕhe maximum element among the minimum elements of the matrix columns\n";
	int Max, min = a[0][0];
	for (i = 1; i < n; i++)
		if (a[i][0] < min) { min = a[i][0]; }
	Max = min;
	for (j = 1; j < n; j++)
	{
		min = a[0][j];
		for (i=1;i<n;i++)
			if (a[i][j] < min) { min = a[i][0]; }
		if (Max < min) { Max = min; }
	}
	return Max;
}
int F_13(int** a)
{
	cout << "\nCount of two-valued numbers\n";
	int count = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if ((a[i][j] > 9) && (a[i][j] < 100)) count++;
	return count;
}
void F_14(int** a)
{
	cout << "\nSum of each row and each column\n";
	int sum;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < n; j++)
		{
			sum += a[i][j];
			cout << setw(6) << a[i][j];
		}
		cout << setw(6) << sum;
		cout << endl;
	}
	for (j = 0; j < n; j++)
	{
		sum = 0;
		for (i = 0; i < n; i++)
			sum += a[i][j];
		cout << setw(6) << sum;
	}

}
int** Mult(int** a, int** b)
{
	int** c = new int* [n];
	for (i = 0; i < n; i++)
		c[i] = new int[n];
	int s;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	return c;
}
int main()
{
	//int x, y;
	cout << "enter array A:" << endl;
	int** a = create();
	show(a);
	cout << "enter array B:" << endl;
	int** b = create();
	show(b);
	int** c = Mult(a, b);
	show(c);
	//cout << "Enter number of columns to swap: "; cin >> x >> y;
	//Swap(a, x,y);
	//show(a);
	////a = Shift(a);
	////show(a);
	//int k = Max_Col(a);
	//cout << "Max col is " << k << endl;
	//k = Min_Row(a);
	//cout << "Min row is " << k << endl;
	//Positiv_on_diag(a);
	//Index_of_min(a);

	//int str[n*n];
	//cout << "\n Conversion to string: ";
	//Сonv_to_str(a, str);
	//for (i = 0; i < n * n; i++)
	//	cout << str[i] << " ";
	//Max_in_each_col(a);
	//
	//cout << "\n Enter k = "; cin >> k;
	//Where_3k(a, k);
	//cout << "enter array A:" << endl;
	//int** A = create();
	//cout << "enter array B:" << endl;
	//int** B = create();
	//show(A);
	//show(B);
	//A = Big_matrix(A, B);
	//show(A);
	/*Last_in_row_is_sum();
	Swap_diag(a);
	show(a);
	cout << "\nF12: " << F_12(a);
	cout << "\nF13: " << F_13(a);
	F_14(a);*/

}