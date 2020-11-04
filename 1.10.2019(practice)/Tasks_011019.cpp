#include <iostream>
using namespace std;

void exe1();
void exe2();
void exe3();
void exe4();
void exe5();
void exe6();
void exe7();
void exe8();
void exe9();
void exe10();
void exe11();
void exe12();
void exe13();

double binpow(int a, int n);


int main()
{

	setlocale(LC_ALL, "RUS");
	int num_exe;
	bool finish = false;

	do {
		cout << "\n Выберете номер задачи(0-Завершить): " ;
		cin >> num_exe;

		switch (num_exe)
		{
			case 0: finish = true; break;
			case 1: exe1(); break;
			case 2: exe2(); break;
			case 3: exe3(); break;
			case 4: exe4(); break;
			case 5: exe5(); break;
			case 6: exe6(); break;
			case 7: exe7(); break;
			case 8: exe8(); break;
			case 9: exe9(); break;
			case 10: exe10(); break;
			case 11: exe11(); break;
			case 12: exe12(); break;
			case 13: exe13(); break;
			
		default:
			cout << "Такой задачи нет";
			break;
		}

	} while (!finish);

	
}

void exe1()
{
	cout << "\t =========== Задание 1 ===========" << endl;
	cout << "\t Сумма чётных цифр числа" <<endl;

	long int n=0;
	cout << " Введите число: ";
	cin >> n;

	long int sum = 0;
	long int t = n;

	while (t > 0)
	{
		if ((t % 10) % 2 == 0)
			sum += (t % 10);
		t /= 10;
	}
	cout << "Сумма чётных цифр числа " << n << " = " << sum << endl;


	string s(40, '=');
	cout << "\t" << s;
}

void exe2()
{
	cout << "\t =========== Задание 2 ==========="  << endl;
	cout << "\t Количество чётных и нечетных цифр числа" << endl;

	long int n=0;
	cout << " Введите число: ";
	cin >> n;

	long int even_count = 0;
	long int odd_count = 0;
	long int t = n;

	while (t > 0)
	{
		if ((t % 10) % 2 == 0)
			even_count++;
		else
			odd_count++;
		t /= 10;
	}
	cout << "Количество чётных цифр = " << even_count << endl << "Количество нечётных цифр = " << odd_count << endl;

	string s(40, '=');
	cout << "\t" << s;
	
}
void exe3()
{
	cout << "\t =========== Задание 3 ===========" << endl;
	cout << "\t Факториал числа" << endl;

	int i, sum = 0, fact = 1, n;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		//sum = sum + fact;
		fact = fact * i;
	}
	cout << "Факториал числа " << n << " = " << fact << endl;

	string s(40, '=');
	cout << "\t" << s;
}
void exe4()
{
	cout << "\t =========== Задание 4 ==========="  << endl;
	cout << "\t Сколько простых чисел было введено до первого числа меньше двух" << endl;

	int n, i;
	int count = 1;

	cout << " Введите число: ";
	cin >> n;
	while (n > 2)
	{
		bool isPrime = true;
		for (i = 2; i <= (sqrt(abs(n))); i++)
		{
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) { count++; }
		cout << " Введите число: ";
		cin >> n;
	}
	cout << "\nКоличество простых чисел " << count << endl;

	string s(40, '=');
	cout << "\t" << s;
}

void exe5()
{
	cout << "\t =========== Задание 5 ==========="  << endl;
	cout << "\t Сумма и произведение цифр числа" << endl;

	long int n;
	long sum = 0, prod = 1;
	cout << " Введите число: ";
	cin >> n;
	while (n > 0)
	{
		sum += n % 10;
		prod *= n % 10;
		n /= 10;
	}
	cout << "Сумма цифр = " << sum << endl << "Произведение цифр = " << prod << endl;

	string s(40, '=');
	cout << "\t" << s;
}

void exe6()
{
	cout << "\t =========== Задание 6 ===========" << endl;
	cout << "\t Ряд чисел Фибоначчи" << endl;

	int fib1 = 0, fib2 = 1;
	int fib = 1;
	int n;

	cout << " Введите число элементов ряда: ";
	cin >> n;

	while (n--)
	{
		fib = fib2 + fib1;
		fib2 = fib1;
		fib1 = fib;

		cout << fib << "  ";
	}

	cout << endl;
	string s(40, '=');
	cout << "\t" << s;
}
void exe7()
{
	cout << "\t =========== Задание 7 ==========="  << endl;
	cout << "\t Возвести в степень" << endl;

	double a, n;
	cout << " Введите основание степени: ";
	cin >> a;
	cout << " Введите степень: ";
	cin >> n;


	cout << a << "^" << n << " = " << binpow(a, n) << endl;

	string s(40, '=');
	cout << "\t" << s;

}

double binpow(int a, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 1)
	{
		return binpow(a, n - 1) * a;
	}
	else
	{
		double b = binpow(a, n / 2);
		return b * b;
	}
}

void exe8()
{
	cout << "\t =========== Задание 8 ==========="  << endl;
	cout << "\t Делители каждого числа из интервала" << endl;

	int m, n;
	cout << " Левая граница интервала: ";
	cin >> m;
	cout << " Правая граница интервала: ";
	cin >> n;
	while (m <= n)
	{
		cout << m << ": ";
		for (int i = 2; i < (m - 1); i++)
		{
			if (m % i == 0)
			{
				cout << i << " ";
			}
		}
		cout << endl;
		m++;
	}
	string s(40, '=');
	cout << "\t" << s;
}

void exe9()
{
	cout << "\t =========== Задание 9 ===========" << endl;
	cout << "\t Сумма произведений первого-второго и\n  третьего-четвёртого цифр четырёхзначного числа"<<endl;

	int n;
	int sum;
	cout << " Введите число: ";
	cin >> n;
	try 
	{
		if (((1000 > n) || (n > 9999))) { throw "Не четырёхзначное!"; }
		sum = (n / 1000) * ((n / 100) % 10) + ((n % 100) / 10) * (n % 10);
		cout << "Результат для числа " << n << " = " << sum << endl;
	}
	catch (const char* exeption)
	{
		cout << "Ошибка: " << exeption << '\n';
	}
	string s(40, '=');
	cout << "\t" << s;
}
void exe10()
{
	cout << "\t =========== Задание 10 ===========" << endl;
	cout << "\t Наибольший делитель числа" << endl;

	int n;
	int max=0; 
	cout << " Введите число: "; // подразумеваем, что составное
	cin >> n;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) max = i;
	}
	if (max)
	{
		cout << "Наибольший делитель числа " << n << " = " << max;
	}
	else
	{
		cout << "У числа нет делителей, кроме 1 и " << n << ". Оно простое";
	}

	cout << endl;
	string s(40, '=');
	cout << "\t" << s;

}

void exe11()
{
	
	cout << "\t =========== Задание 11 ===========" << endl;
	cout << "\t Сумма первой и последней цифр числа " << endl;

	long int n = 0;
	cout << " Введите число: ";
	cin >> n;
	long int sum = n % 10;
	while (n > 10)
	{
		n /= 10;
	}
	sum += n;
	cout << "Результат = " << sum<<endl;

	string s(40, '=');
	cout << "\t" << s;
}

void exe12()
{
	double a, b;
	int sum=0;
	cout << "\t =========== Задание 12 ===========" << endl;
	cout << "\t Сумма целых чисел интервала " << endl;
	cout << " Левая граница интервала: "; 
	cin >> a;
	cout << " Правая граница интервала: ";
	cin >> b;
	cout << endl;
	int x = int(a * 10);
	if (x %10 == 0) { sum += a; } // если левая граница - целое число - включаем в сумму
	for (int i = a+1; i <= b; i++) // ведём подсчёт от ближайшего правого целого числа до заданной правой границы
	{
		sum += i;
	}
	cout << "Сумма целых чисел интервала [" << a << "; " << b << "] = " << sum << endl;

	string s(40, '=');
	cout << "\t" << s;
}
void exe13()
{
	cout << "\t =========== Задание 13 ===========" << endl;
	cout << "\t  Проверка последовательности на возрастание" << endl;
	int n, m;
	int count;
	bool check = true;
	
	cout << " Введите число элементов в последовательности: ";
	cin >> count;
	cout << " Ввод элементов: " << endl;
	cin >> n;
	do
	{
		cin >> m;
		if (n > m)
			check = false;
		n = m;
		count--;
	} while (count-1);
	if (check) { cout << "Возрастающая" << endl; }
	else { cout << "Невозрастающая" << endl; }

	string s(40, '=');
	cout <<"\t"<< s;
}