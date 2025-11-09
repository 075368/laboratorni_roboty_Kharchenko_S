/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

//виконання завдання 1
void c_task_1(int R)
{
	float V, S;//дійсний тип даних для об'єму та площі
	double pi = 3.14; //стале значення pi = 3,14
	
	if (R < 0)
	   cout << "Радіус кулі не може бути від'ємним числом." << endl;
	else
	{
	    V = ((4 * pi * (R * R * R)) / 3);
	    cout << "Вартість об'єму кулі: " << V << endl;

	    S = (4 * pi * (R * R));
	    cout << "Вартість площі поверхні кулі: " << S << endl;
	}
}	

//завдання 1
void task_1()
{
    int R;
    
    cout << "Введіть значення радіуса кулі: ";
	cin >> R;
	c_task_1(R);//виклик функції
	cout << endl;
	
	cout << "Введіть значення радіуса кулі: ";
	cin >> R;
	c_task_1(R);//виклик функції
	cout << endl;
	
	cout << "Введіть значення радіуса кулі: ";
	cin >> R;
	c_task_1(R);//виклик функції
	cout << endl;
	
	cout << endl;
}

//виконання завдання 2
float DegToRad(float D)
{
    float R;
    double pi = 3.14; //стале значення pi = 3,14
    
    R = D * (pi / 180);
    return R;
}

//завдання 2
void task_2()
{
    float D;//дійсний тип радіуса
    
	cout << "Введіть значення D: ";
	cin >> D;
	if (D >= 0 && D < 360)//перевірка на виконання умови завдання
	   cout << "Вартість " << D << " градусів в радіанах становить: " << DegToRad(D) << endl;
	else
	   cout <<"Завдання не може бути виконаним." << endl; 
	cout << endl;
	
	   
	cout << "Введіть значення D: ";
	cin >> D;
	if (D >= 0 && D < 360)//перевірка на виконання умови завдання
	   cout << "Вартість " << D << " градусів в радіанах становить: " << DegToRad(D) << endl;
	else
	   cout <<"Завдання не може бути виконаним." << endl;
	cout << endl;
	
	
	cout << "Введіть значення D: ";
	cin >> D;
    if (D >= 0 && D < 360)//перевірка на виконання умови завдання
	   cout << "Вартість " << D << " градусів в радіанах становить: " << DegToRad(D) << endl;
	else
	   cout <<"Завдання не може бути виконаним." << endl;
	cout << endl;
	
	   
	cout << "Введіть значення D: ";
	cin >> D;
    if (D >= 0 && D < 360)//перевірка на виконання умови завдання
	   cout << "Вартість " << D << " градусів в радіанах становить: " << DegToRad(D) << endl;
	else
	   cout <<"Завдання не може бути виконаним." << endl;
	cout << endl;
	
	   
	cout << "Введіть значення D: ";
	cin >> D;
    if (D >= 0 && D < 360)//перевірка на виконання умови завдання
	   cout << "Вартість " << D << " градусів в радіанах становить: " << DegToRad(D) << endl;
	else
	   cout <<"Завдання не може бути виконаним." << endl;
	cout << endl;
	   
	cout << endl;
}

//перевірка введених даних для завдання 3
int test_task_3(int m)
{
    if (m < 0)
    {
       cout << "Вартість ваги має бути додатньою." << endl;
       return 0;
    }
    else 
       return 1;
}

//розрахунок потрібних вартостей для завдання 3
void count_task_3(int m)
{
    int Mp, Mn;
    Mp = (m / 1000);//обчислення кількості повних тонн
    Mn = (m % 1000);//обчислення надлишку в кілограмах
    
    cout << "Кількість повних тонн: " << Mp << endl;
    cout << "Кількість надлишку в кілограмах: " << Mn << endl;
}

//виведення вартостей для завдання 3
void print_task_3 (int m)
{
    int result_test_task_3 = test_task_3(m);
    
    if (result_test_task_3 == 1)//умова для вибору подальших дій після перевірки значення m
    {
        count_task_3(m);
        cout << endl;
    }
    else
        cout << endl;
}

//завдання 3
void task_3()
{
    int m;
    cout << "Введення кількості кілограм: ";
    cin >> m;
    
    print_task_3(m);
    
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    
    int task_num;
    cout << "Введіть номер завдання: ";
    cin >> task_num;
    
    switch (task_num)
    {
        case 1: task_1(); break; //завдання 1
        case 2: task_2(); break; //завдання 2
        case 3: task_3(); break; //завдання 3
        default: cout << "Неправильний номер завдання (тiльки 1, 2 або 3)."<< endl;
    }
    
    return 0;
}