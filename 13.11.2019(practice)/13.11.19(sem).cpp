#include <iostream>
#include <iomanip>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <vector>
#include <algorithm> 

using namespace std;
const int rep = 6;
int town_count;
vector<vector<int>>	routes;

int** Create()
{
	int** path_matrix = new int* [town_count - 1];
	for (int i = 0; i < town_count; i++)
	{
		path_matrix[i] = new int[town_count - 1];
	}
	for (int i = 0; i < town_count; i++)
		path_matrix[i][i] = 0;
	for (int i = 0; i < town_count - 1; i++)
		for (int j = i + 1; j < town_count; j++)
		{
			path_matrix[i][j] = rand() % 90 + 1;
			path_matrix[j][i] = path_matrix[i][j];
		}
	for (int i = 0; i < town_count; i++)
	{
		cout << setw(5) << i + 1;
	}
	cout << "\n";
	for (int i = 0; i < town_count; i++)
	{
		cout << i + 1;
		for (int j = 0; j < town_count; j++)
			cout << setw(5) << path_matrix[i][j];
		cout << "\n";
	}
	return path_matrix;
}

void rand(vector<int> bas, int start)
{
	for (int i = 0; i < rep; i++)
	{
		random_shuffle(bas.begin(), bas.end());
		routes[i][0] = start;
		for (int j = 1; j < town_count; j++)
			routes[i][j] = bas[j - 1];
		routes[i][town_count] = start;
	}
}

void show(vector<vector<int>> routes, int** matrix)
{
	int min_sum_route=0;
	vector<int> min_route;
	for (int j = 0; j < town_count; j++)
	{
		min_sum_route += matrix[routes[0][j]][routes[0][j + 1]];
		min_route = routes[0];
	}
	for (int i = 0; i < rep; i++)
	{
		int t = 0;
		int* sum = new int[rep];
	    sum[i] = 0;
		for (int j = 0; j < town_count; j++)
		{
			sum[i] += matrix[routes[i][j]][routes[i][j + 1]];
			cout << routes[i][j] + 1;
			t++;
			if (t < town_count) cout << " -> ";
		}
		cout << " -> " << routes[i][town_count]+1;
		cout << "   |  " << sum[i] << "\n";
		if(min_sum_route > sum[i]) { min_sum_route = sum[i], min_route = routes[i]; }
		delete[] sum;
	}
	cout << endl;
	cout << "The shortest route:\n";
	for (auto i = min_route.begin(); i != min_route.end(); ++i)
		cout << *i + 1 << " -> ";
	cout << min_sum_route;
	
}
void show_routes(int **path_matrix,int start)
{
	int** matrix = path_matrix;
	vector<int> bas;
	for (int i = 0; i < town_count; i++)
		if (i != start) bas.push_back(i);
	routes.resize(rep, vector<int>(town_count + 1));
	
	rand(bas, start);
	
	show(routes, matrix);
	bas.clear();
}
int main()
{
	char ans;

	cout << " Start route search: y - yes, n - not: ";
	bool finish = false;
	do 
	{
		cin >> ans;
		switch (ans)
		{
		case 'n': finish = true; break;
		case 'y'  : {int start;
			srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
			cout << "Enter the number of towns: ";
			cin >> town_count;
			int** Path_matrix = Create();
			cout << "Enter start town: ";
			cin >> start;
			show_routes(Path_matrix, start - 1);
			routes.clear();
			
		} break;
		

		default:
			finish = true; break;
		}
		if (!finish)cout << " \n Continue? Y - yes, N - not: ";
	} while (!finish);

	
}
