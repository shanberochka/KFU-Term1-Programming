#include<iostream> 

#include<iomanip> 

#include<fstream> 

#include<cstring> 

using namespace std;
const int numberCourse = 5;
const int numberMark = 4;
const int lengthIndent = 7;// длина абзаца 
const int lengthTable = 56;// длина таблицы 
const int lengthColumn = 10;// длина колонки 
///////////////////////////////////////////////// 

void star(int n, int m)
{
	cout.width(n);
	int i;
	for (i = 0; i < m; i++)
		cout << '*';
	cout << endl;
}

/////////////////////////////////////////////// 

void star1(int n)
{
	int i;
	cout.width(n);
	cout << "*";
	cout.width(lengthColumn + 1);
	cout << "*";
	for (i = 0; i < numberMark; i++)
	{
		cout.width(lengthColumn + 1);
		cout << '*';

	}

	cout << endl;

}

///////////////////////////// 

int main()

{

	char name_Course[numberCourse][15];
	char name_Mark[numberMark][20];
	int  number_Student[numberCourse][numberMark];
	char name_Faculty[80];
	int Total[numberMark];

	ifstream in("arb.txt");

	ofstream out("vmk.txt");

	int i, j;

	in.getline(name_Faculty, 80);



	for (i = 0; i < numberCourse; i++)

		in >> name_Course[i];

	for (i = 0; i < numberMark; i++)

		in >> name_Mark[i];



	for (i = 0; i < numberCourse; i++)

		for (j = 0; j < numberMark; j++)

			in >> number_Student[i][j];



	/*

	  cout<<name_Faculty<<endl;



	  for (i=0;i<numberCourse;i++)

	cout<<name_Course[i]<<"   ";

	cout<<endl;



	  for (i=0;i<numberMark;i++)

	 cout<< name_Mark[i]<<"   ";

		   cout<<endl;

		 for (i=0;i<numberCourse;i++)

		  {

	  for (j=0;j<numberMark;j++)

	  cout<<number_Student[i][j]<<"  ";

	  cout<<endl;

		   }

	*/

	cout << endl << endl;

	cout.width(lengthTable + 4);

	cout << name_Faculty << endl;

	cout << endl << endl;



	star(lengthIndent + 1, lengthTable);//   

	star1(lengthIndent + 1);



	cout.width(lengthIndent + 1);

	cout << "*";

	cout.width(lengthColumn + 1);

	cout << "*";



	for (i = 0; i < numberMark; i++)

	{

		cout << " " << name_Mark[i];

		cout.width(lengthColumn - strlen(name_Mark[i]));

		cout << "*";

	}

	cout << endl;



	star1(lengthIndent + 1);

	star(lengthIndent + 1, lengthTable);

	for (i = 0; i < numberCourse; i++)

	{

		star1(lengthIndent + 1);



		cout.width(lengthIndent + 1);

		cout << "*";

		cout << " " << name_Course[i];

		cout.width(lengthColumn - strlen(name_Course[i]));

		cout << "*";



		for (j = 0; j < numberMark; j++)

		{
			cout << setw(6) << number_Student[i][j];

			cout << setw(5);

			cout << "*";

		}

		cout << endl;

		star1(lengthIndent + 1);

		star(lengthIndent + 1, lengthTable);

	}

	for (j = 0; j < numberMark; j++)
	{
		Total[j] = 0;
		for (i = 0; i < numberCourse; i++)
			Total[j] += number_Student[i][j];
	}
	star(lengthIndent + 1, lengthTable);
	star1(lengthIndent + 1);

	cout.width(lengthIndent + 1);
	cout << "*" << " Total    *";
	for (j = 0; j < numberMark; j++)
	{
		cout << setw(6) << Total[j];
		cout << setw(5);
		cout << "*";
	}
	cout << endl;
	star1(lengthIndent + 1);
	star(lengthIndent + 1, lengthTable);
	cout << endl;
	system("pause");
	return 0;

}

