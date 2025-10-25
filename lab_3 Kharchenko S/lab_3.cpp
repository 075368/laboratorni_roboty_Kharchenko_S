/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

//Дано ціле число. Вивести його рядок-опис виду «від’ємне парне число», 
//«нульове число», «додатне непарне число» і т. ін. 
void task_if1() //завдання 1 декларація та реалізація
{
    int num;
    cout << "********** If 1 **********" << endl;
    cout << "Введіть ціле число: ";
    cin >> num;

    if (num == 0) 
        cout << "Нульове число" << endl;
    else
    {
        if (num < 0) 
        {
           if (num % 2 == 0)
              cout << "Від'ємне парне число" << endl;
           else
              cout << "Від'ємне непарне число" << endl;
        }
        else 
        {
           if (num % 2 == 0)
              cout << "Додатне парне число" << endl;
           else
              cout << "Додатне непарне число" << endl;
        }
    }
}

//Визначити чи точка з координатами (х, у) потрапляє у простор зазначений у варіанті 16.
void task_geom2() //завдання 2 деклфрація та реалізація
{
    double x, y, r;
    cout << "Введіть координату х точки: ";
    cin >> x;
    cout << "Введіть координату y точки: ";
    cin >> y;
    cout << "Введіть радіус кола: ";
    cin >> r;
    
    bool in_left_down_side = ((x + r)*(x + r) + (y + r)*(y + r) <= (r * r)) && ((-x) - (2 * r) <= y) && (x = (-r));
    bool in_right_up_side = (x = r) && (y = 0) && ((-x) + (2 * r) <= y) && ((x - r)*(x - r) + (y - r)*(y - r) >= (r * r));
    
    if (in_left_down_side || in_right_up_side)
       cout << "Точка потрапляє у зафарбовану область визначену для варіанту 16." << endl;
    else
       cout << "Точка знаходиться поза зафарбованою областю визначену для варіанту 16." << endl;
    
    return;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian"); // Українська локалізація консолі
    int menu;
    cout << "Номер завдання: ";
    cin >> menu;
    //перемикання між завданнями
    switch (menu)
    {
        case 1: task_if1(); break; //завдання 1
        case 2: task_geom2(); break; //завдання 2
        default: cout << "Неправильний номер завдання (тільки 1 або 2)." << endl;
    }
    system ("pause");
    return 0;
}

