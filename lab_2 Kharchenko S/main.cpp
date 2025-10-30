/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>//підключення бібліотеки математичних функцій
using namespace std;

int main ()
{
    //Дана маса M в кілограмах. Використовуючи операцію цілочисельного 
    //ділення, знайти кількість повних тон в ній і надлишок кілограмів (1 
    //тонна = 1000 кг). 
    cout << "Integer 2." << endl;
    int m, Mp, Mn;//декларація цілих змінних
    //введення даних
    cout << "Enter m: ";
    cin >> m;
    //розрахунок та відповідь
    Mp = (m / 1000);
    Mn = (m % 1000);
    cout << "Кількість повних тонн: " << Mp << endl;
    cout << "кількість надлишку: " << Mn << endl;
    
    cout << endl;
    
    //Дано числа x, y. Перевірити істинність висловлювання: «Точка з 
    //координатами (x, y) лежить в першій або третій координатній чверті».
    cout << "Boolean 28." << endl;
    int Tx, Ty;
    //введення даних
    cout << "Enter x: ";
    cin >> Tx;
    
    cout << "Enter y: ";
    cin >> Ty;
    //розв'язок та відповідь
    if ((Tx > 0) && (Ty > 0))
    {
        cout << "Точка з координатами (х, у) належить до першої координатної чверті." << endl;
    }
    else
    {
        if ((Tx < 0) && (Ty < 0))
        {
            cout << "Точка з координатами (х, у) належить до третьої координатної чверті." << endl;
        }
        else 
        {
            cout << "Точка з координатами (х, у) не належить до жодної з даниих чверть." << endl;
        }
    }
    
    cout << endl;

    //По наданій, в таблиці номер 3, в варіанті 11, формулі провести розрахунок. 
    cout << "Math 11." << endl;
    int x, y;
    //введення даних
    cout << "Enter x: ";
    cin >> x;
    //розрахунок та відповідь
    if ((cbrt(1 + ((x * x)/2)) + (log(abs(x)) / log(abs(3)))) == 0)
    {
        cout << "Не можна виконати завдання, оскільки знаменник дорівнюється 0." << endl;
    }
    else
    {
        y = (((2 * tan(x) * sin(x)) + (0.25 * sqrt(abs(1 - ((sin(x) * sin(x)) * tan(x)))))) / (cbrt(1 + ((x * x)/2)) + (log(abs(x)) / log(abs(3)))));
        cout << "Відповідь: " << y << endl;
    }
    
    return 0;
}