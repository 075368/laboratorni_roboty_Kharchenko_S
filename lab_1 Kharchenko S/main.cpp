/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main ()
{
    //задача Begin27
    //Швидкість першого автомобіля V1 км / год, другого - V2 км / год, відстань між 
    //ними S км. Визначити відстань між ними через T годин, якщо автомобілі 
    //віддаляються один від одного, рухаючись в протилежних напрямках. Дана 
    //відстань рівна сумі початкової відстані і загального шляху, пройденого 
    //автомобілями; загальний шлях = час · сумарна швидкість. 
    cout << "Begin 27" << endl;
    //декларація змінних
    double v1, v2, s, t, Sa;
    //введення змінних
    cout << "Enter v1: ";
    cin >> v1;
    
    cout <<"Enter v2: ";
    cin >> v2;
    
    cout << "Enter s: ";
    cin >> s;
    
    cout << "Enter t: ";
    cin >> t;
    //розрахунок результату
    Sa = s + ((v1 + v2) * t);
    //виведення результат
    cout << "Zahalnyy shlakh: " << Sa << endl;
    
    cout << endl;
    
    //задача Begin15
    //Дано змінні A, B, C. Змінити їх значення, перемістивши вміст A в C, C - в B, B - 
    //в A, і вивести нові значення змінних A, B, C.
    cout << "Begin 15" << endl;
    //декларація змінних
    int A, B, C, temp;
    //введення змінних
    cout << "Enter A: ";
    cin >> A;
    
    cout << "Enter B: ";
    cin >> B;
    
    cout << "Enter C: ";
    cin >> C;
    //надання нових вартостей
    temp = C;
    C = A;
    A = B;
    B = temp;
    //виведення результатів
    cout << "Нова вартість А: " << A << endl;
    cout << "Нова вартість В: " << B << endl;
    cout << "Нова вартість С: " << C << endl;
    
    cout << endl;
    
    //задача Begin36
    //Дано довжину кола L. Знайти діаметр D = L/π. Взяти π=3.14.
    cout << "Begin 36" << endl;
    //декларація змінних
    double L, pi = 3.14, D;
    //введення змінної
    cout << "Enter L: ";
    cin >> L;
    //розрахунок результату
    D = (L/pi);
    //виведення результату
    cout << "Diametr: " << D << endl;
    
    return 0;
}