#include <iostream>
#include <cmath>
using namespace std;

//Використовуючи типи TPoint, TTriangle (див. Param64-65), описати процедуру 
//Altitudes (T, h1, h2, h3), що знаходить висоти h1, h2, h3 трикутника T (T - 
//вхідний параметр типу TTriangle, h1, h2, h3 – вихідні дійсні параметри), проведені відповідно з вершин TA, TB, TC За допомогою 
//цієї процедури знайти висоти трикутників ABC, ABD, ACD, якщо дано 
//координати точок A, B, C, D.  
struct TPoint //defining point
{
    float X, Y;
};

struct TTriangle //defining triangle
{
    TPoint A, B, C;
};

float distance_between_points(TPoint point_1, TPoint point_2) //length of side
{
    float distance;
    
    distance = sqrt(pow((point_2.X - point_1.X), 2) + pow((point_2.Y - point_1.Y), 2));
    
    return distance;
}

void Altitudes(TTriangle T, float &h1, float &h2, float &h3) //function which is doing task
{
    float a = distance_between_points(T.B, T.C); // for example side BC in for ABC triangle
    float b = distance_between_points(T.A, T.C); // for example side AC in for ABC triangle
    float c = distance_between_points(T.A, T.B); // for example side AB in ABC triangle
    
    float p = (a + b + c) / 2; // a half of circuit of for example ABC triangle
    
    float S = sqrt(p * (p - a) * (p - b) * (p - c)); //square of for example ABC triangle
    
    h1 = (2 * S) / a; //height 1 of for example ABC triangle
    h2 = (2 * S) / b; //height 2 of for example ABC triangle
    h3 = (2 * S) / c; //height 3 of for example ABC triangle
}

void print_result(string triangle, float h1, float h2, float h3) //printing result on console
{
    cout << "Triangle " << triangle << " heights: " << endl;
    cout << "h1 = " << h1 << endl;
    cout << "h2 = " << h2 << endl;
    cout << "h3 = " << h3 << endl;
    
    cout << endl;
}

void task_1() //doing task 1
{
    TPoint A, B, C, D; //defining points
    
    //entering coordinates of points
    cout << "Coordinate x of point A: ";
    cin >> A.X;
    cout << "Coordinate y of point A: ";
    cin >> A.Y;
    cout << endl;
    
    cout << "Coordinate x of point B: ";
    cin >> B.X;
    cout << "Coordinate y of point B: ";
    cin >> B.Y;
    cout << endl;
    
    cout << "Coordinate x of point C: ";
    cin >> C.X;
    cout << "Coordinate y of point C: ";
    cin >> C.Y;
    cout << endl;
    
    cout << "Coordinate x of point D: ";
    cin >> D.X;
    cout << "Coordinate y of point D: ";
    cin >> D.Y;
    cout << endl;
    
    //defining heights of triangle
    float h1, h2, h3;
    
    //doing task for each triangle
    TTriangle ABC = {A, B, C};
    Altitudes(ABC, h1, h2, h3);
    print_result("ABC", h1, h2, h3);
    cout << endl;
    
    TTriangle ABD = {A, B, D};
    Altitudes(ABD, h1, h2, h3);
    print_result("ABD", h1, h2, h3);
    cout << endl;
    
    TTriangle ACD = {A, C, D};
    Altitudes(ACD, h1, h2, h3);
    print_result("ACD", h1, h2, h3);
    cout << endl;
}

//Знайти корені квадратного рівняння A · x2 + B · x + C = 0, заданого своїми 
//коефіцієнтами A, B, C (A> 0), якщо відомо, що дискримінант рівняння позитивний. 
//Вивести спочатку менший, а потім більший із знайдених коренів. Коріння 
//квадратного рівняння знаходяться за формулою x1, х2 = (-B ± (D) 1/2) / (2 · A), де D - 
//дискримінант, рівний B2 - 4 · A · C.
struct Coefficients //defining coefficients of quadratic equatation
{
    float A, B, C; 
};

struct Roots //roots of quadratioc equatation
{
    float x_1, x_2;
};

bool right_data(Coefficients coeffies) //checking if coefficient A is right
{
    if (coeffies.A <= 0)
    {
        cout << "Wrong data!" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

Roots solution (Coefficients coeffies) //function which is doing task
{
    Roots result;
    
    float D = pow(coeffies.B, 2) - (4 * coeffies.A * coeffies.C); //delta of quadratic equatation
    
    float sqrt_D = sqrt(D);
    
    //counting roots
    float root_1 = (-(coeffies.B) - sqrt_D) / (2 * coeffies.A);
    float root_2 = (-(coeffies.B) + sqrt_D) / (2 * coeffies.A);
    
    if (root_1 < root_2) //defining the place for each root of quadratic equatation
    {
        result.x_1 = root_1;
        result.x_2 = root_2;
    }
    else
    {
        result.x_1 = root_2;
        result.x_2 = root_1;
    }
    
    return result;
}

void task_2() //doing task 2
{
    Coefficients coeffies; //defining coefficients
    
    //entering coefficients
    cout << "Enter coefficient A: ";
    cin >> coeffies.A;
    
    cout << "Enter coefficient B: ";
    cin >> coeffies.B;
    
    cout << "Enter coefficient C: ";
    cin >> coeffies.C;
    cout << endl;
    
    float D = pow(coeffies.B, 2) - (4 * coeffies.A * coeffies.C);
    
    if (D <= 0 || right_data(coeffies) == false) //checking if delta is positive
    {
        cout << "Ending of doing task!" << endl;
    }
    else
    {
        Roots result = solution(coeffies);
        
        cout << "First, smaller root: " << result.x_1 << endl;
        cout << "Second, bigger root: " << result.x_2 << endl;
    }
    
    cout << endl;
}

//Дано ціле число A. Перевірити істинність висловлювання: «Число A є непарним»
struct Number //defining a number
{
    int A;
};

void check_of_number (Number number) //checking if number fulfil task
{
    if (number.A % 2 != 0)
    {
        cout << "Number A is odd number." << endl;
    }
    else
    {
        cout << "Number A is even number." << endl;
    }
    
    cout << endl;
}

void task_3() //doing task 3
{
    Number number; //defining a number
    
    //entering numbet
    cout << "Enter a number: ";
    cin >> number.A;
    
    check_of_number(number);
}

int main () //main menu
{
    int task_num;
    
    do 
    {
        cout << "Task number: ";
        cin >> task_num;
        
        switch (task_num)
        {
            case 1: task_1(); break;
            case 2: task_2(); break;
            case 3: task_3(); break;
            case 0: cout << "Ending of doing tasks."; break;
            default: cout << "Wrong task number!" << endl;
        }
    }
    while (task_num != 0);
    
    return 0;
}