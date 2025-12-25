#include <iostream>
#include "lab2.h"

static void task_1()
{
	int x = 0;
	int y = 0;

	std::cout << "Введите два числа по очереди: " << std::endl;
	std::cin >> x >> y;
	std::cout << "Среднее арифметическое: "
		<< (x + y) / 2.0f << std::endl;

	char op;
	std::cout << "Введите знак '+', '-', '*', '/'" << std::endl;
	std::cin >> op;

	//if (op == '+')
	//	std::cout << "Сложение переменных: " << a + b << std::endl;
	//else if (op == '-')
	//	std::cout << "Вычитание переменных: " << a - b << std::endl;
	//else if (op == '*')
	//	std::cout << "Умножение переменных: " << a * b << std::endl;
	//else if (op == '/')
	//	std::cout << "Деление переменных: " << a / b << std::endl;

	switch (op)
	{
	case '+':
		std::cout << "Сложение переменных: " << x + y << std::endl;
		break;
	case '-':
		std::cout << "Вычитание переменных: " << x - y << std::endl;
		break;
	case '*':
		std::cout << "Умножение переменных: " << x * y << std::endl;
		break;
	case '/':
		std::cout << "Деление переменных: " << x / y << std::endl;
		break;
	default:
		std::cout << "Введён неизвестный оператор" << std::endl;
		break;
	}
}

static void task_2()
{
	int n = 0;

	while (true)
	{
		std::cout << "Введите целое положительное число: ";
		std::cin >> n;

		if (n >= 0)
			break;
		else
			std::cout << "Введите целое положительное число!" << std::endl;
	}

	std::cout << '1';
	for (int i = 2; i <= n; i++)
		std::cout << " + " << i;

	std::cout << std::endl;

	int arr[10] =
	{
		1, 2, 3, 4, 5,
		11, 12, 13, 14, 16
	};

	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << ' ';

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			std::cout << arr[i] << ' ';
	}

	std::cout << std::endl;

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 1)
			sum += arr[i];
	}

	std::cout << "Сумма нечетных чисел в массиве: " << sum << std::endl;
}

static int task_3_abs(const int v = 1)
{
	if (v <= 0)
		return 0;

	int sum = v;
	for (int i = 1; i < v - 1; i++)
		sum += i;

	return sum;
}

static void task_3_args(const int a,
	const int b,
	int& ra,
	int& rb)
{
	ra = a + b;
	rb = a * b;
}

static void task_3()
{
	const int r = 2;
	const int c = 3;

	int arr[r][c] =
	{
		1, 2, 3,
		4, 5, 6
	};

	int sum = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sum += arr[i][j];

	const int len = 3;
	int res[len];

	for (int i = 0; i < len; i++)
	{
		int tmp = 0;
		for (int j = 0; j < r; j++)
			tmp += arr[j][i];

		res[i] = tmp;
	}

	for (int i = 0; i < len; i++)
		std::cout << res[i] << ' ';

	std::cout << std::endl;

	float x = 20.84f;

	float& r1 = x;
	float& r2 = x;

	r1 = 12.12f;

	std::cout << "ref_1: " << r1 << " ref_2: " << r2 << std::endl;

	int ra, rb;
	task_3_args(12, 10, ra, rb);

	std::cout << "ref_int_a: " << ra << " ref_int_b: " << rb << std::endl;
}

#define add(a, b) a + b\

static void task_4()
{
	lab2::task_4_static(20);
	lab2::task_4_static(15);
	lab2::task_4_static(10);
}

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int t = 0;
	cout << "Введите номер задания" << endl;
	cin >> t;

	if (t == 1)
		task_1();
	else if (t == 2)
		task_2();
	else if (t == 3)
		task_3();
	else if (t == 4)
		task_4();
}

void lab2::task_4_static(const int value)
{
	static int last = 0;

	cout << "sum: " << last + value
		<< " static_field: " << last << endl;

	last = value;
}
