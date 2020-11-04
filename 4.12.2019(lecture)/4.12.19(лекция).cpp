#include<iostream> 
#include<cstring> 

using namespace std;
const int n = 100;

/////////////////////////////////////////////// 

void strcpy1(char s[n], char t[n])
{
	int i = 0;
	while ((s[i] = t[i]) != '\0')i++;// одновременно присваивает и проверяет!
}

///////////////////////////////////////////// 

// string  s is substring of p;   
bool strstr1(char s[n], char p[n])
{
	int i, j;
	bool t = false;
	for (i = 0; i < strlen(p) - strlen(s) + 1 && !t; i++) // Написали формулу ЕА
	{
		bool r = true;
		for (j = 0; j < strlen(s) && r; j++)
			if (s[j] != p[i + j]) r = false;
		t = r;
	}
	return t;
}

// position substring s in string  p;   
int strstr2(char s[n], char p[n])
{
	int i, j;
	int pos = -1;
	bool t = false;
	for (i = 0; i < strlen(p) - strlen(s) + 1 && !t; i++)
	{
		bool r = true;
		for (j = 0; j < strlen(s) && r; j++)
			if (s[j] != p[i + j]) r = false;
		t = r;
	}
	if (t) pos = i - 1; else pos = -1; //? зачем else
	return pos;
}

/////////////////////////////////////////////// 

void conc(char x[n], char y[n])
{
	int i, j;
	int p = strlen(x);
	int q = strlen(y);
	i = p;
	j = 0;
	while ((x[i] = y[j]) != '\0') { j++; i++; }// забросили у в х (? и ноль-символ?)
}

/////////////////////////////////////////////// 

void delette(char x[n], int pos, int len)
{
	int i, j;
	if (pos > strlen(x) - len)
	{
		cout << "impossible!" << endl;
		return;
	}
	j = pos;  i = pos + len;
	while ((x[j] = x[i]) != '\0')
	{
		i++; j++;
	}
}

///////////////////////////////////////////////
// insert string y[n] to string x[n]  
// with position pos in x[n] 
void insert(char y[n], int pos, char x[n])
{
	if (pos == strlen(x))
	{
		conc(x, y);  return;
	}
	//if ((pos>strlen(x))||(pos<0)) 
	//{ 
	//cout<<" impossible!! "; 
	//return; 
	//} 
	char z[n], m[n];
	int i, j;
	i = 0;
	j = pos;

	while ((z[i] = x[j]) != '\0')//запоминаем подстроку с позиции pos в массив z
	{
		i++; j++;
	}

	strcpy1(m, y);
	conc(m, z);
	i = pos;
	j = 0;

	while ((x[i] = m[j]) != '\0')
	{
		i++; j++;
	}
}

/////////////////////////////////////////////// 

int  main()
{

	char t[n];
	int pos;
	char u[n], s[n];
	int p;
	///////////////////////////////////////// 

	cout << "Task 1" << endl;

	cout << " calculate number of substr t in str u" << endl;

	cout << " Enter string u= " << endl;

	cin.getline(u, n);



	cout << " Enter substring t t= " << endl;

	cin.getline(t, n);

	p = 0;

	while (strstr2(t, u) != -1)
	{
		u[strstr2(t, u)] = '#'; // предыдущие подстроки разрушаются #-кой, поэтому подсчет р(кол-во вхождений подстроки) верен
		p++;
	}

	cout << "u = " << u << endl;

	cout << "number of input substring t in string u  p= " << p << endl;

	cin.get();

	cout << "reconstruction  u" << endl;

	int i = 0;

	while (i < strlen(u))
	{
		if (u[i] == '#') u[i] = t[0]; // восстановление 
		i++;
	}

	cout << "u = " << u << endl;

	cin.get();

	////////////////////////////////////////////// 

	cout << "Task 2" << endl;

	cout << "delete  substring t in string  u" << endl;

	while (strstr2(t, u) != -1)
	{
		delette(u, strstr2(t, u), strlen(t));
	}

	cout << "new  u = " << u << endl;

	cin.get();

	/////////////////////////////////////////////// 

	cout << "Task3" << endl;

	cout << "in string u change substring t on substring s" << endl;

	cout << " Enter string u= " << endl;

	cin.getline(u, n);

	cout << " Enter string  t= " << endl;

	cin.getline(t, n);



	cout << " Enter  string s= " << endl;

	cin.getline(s, n);

	if (strstr2(t, u) == -1)
	{
		cout << " string t is not substring of string u: error!!" << endl;
		return  0;
	}

	while (strstr2(t, u) != -1) // А что будет в случае, если t такой, что при вставление его в массив u в массиве u возникнет t
	{
		p = strstr2(t, u);
		cout << "p= " << p << endl;
		delette(u, p, strlen(t));
		cout << " after delete  new string  u = " << u << endl;
		cout << "length u= " << strlen(u) << endl;
		cin.get();
		insert(s, p, u);
		cout << "after insert new  u = " << u << endl;
		cout << "len u= " << strlen(u) << endl;
		cin.get();
	}
	cout << "new  u = " << u << endl;
	cin.get();
	system("pause");
	return 0;

}

