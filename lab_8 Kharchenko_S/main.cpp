#include <iostream>
#include <fstream>
using namespace std;
const int N = 20, M = 20;
int results[N];
int n1;
int array_result[N];

//За допомогою текстового редактору створити текстовий файл 
//«array_in_n.txt» з елементами вихідного масиву (n - номер варіанта). У 
//програмі на С++ зчитати і перетворити цей масив відповідно до свого варіанту 
//завдання (див. лаб.роб.№6, завд.2), ім'я файлу і необхідні змінні ввести з 
//консолі. Вивести результати у файл «array_out_n.txt». 
bool enter_array(char* filename, int array[N], int & n) //введення масиву
{
    ifstream fin(filename);
    
    if (!fin.is_open()) //перевірка на невдале відкриття файлу
    {
        cout << "Error, can't open file!" << endl;
        return false;
    }
    else
    {
        fin >> n;
        
        for (int i = 0; i < n; i++)
        {
            fin >> array[i];
        }
    }
    
    fin.close();
    
    return true;
}

void present_array(const int array[N], const int n) //виведення масиву
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
}

void write_array(const int array[N], const int n) //записання модифікованого масиву у відповідний файл
{
    ofstream fout("array_out_104.txt");
    
    for (int i = 0; i < n1; i++)
    {
        fout << array_result[i] << " ";
    }
    
    fout.close();
}

void do_task_1(int array[N], int & n, int K, int M1) //проведення мадифікації масиву
{
    int t = n - K;
    int array_1[t];
    int s = K;
    n1 = 0;
    
    for(int i = 0; i < K; i++)
    {
        cout << array[i] << " ";
        array_result[n1] = array[i];
        n1 = n1 + 1;
    }
    
    for(int j = 0; j < (n - K); j++)
    {
        array_1[j] = array[s];
        s = s + 1;
    }
    
    n1 = K;
    
    for(int l = K; l < (K + M1); l++)
    {
        array[l] = 0;
        cout << array[l] << " ";
        array_result[n1] = array[l];
        n1 = n1 + 1;
    }
    
    n1 = (K + M1);
    
    for(int y = 0; y < (n - K); y++)
    {
        cout << array_1[y] << " ";
        array_result[n1] = array_1[y];
        n1 = n1 + 1;
    }
        
    cout << endl;
}

void task_1() //виконання завдання 1
{
    int array[N];
    int n;
    int K, M1;
    char filename[100];
    
    cout << "Enter filename: ";
    cin.getline(filename, 100);
    
    if (enter_array(filename, array, n))
    {
        cout << "Array: ";
        present_array(array, n);
        
        cout << "Enter number of column after which zeros must be added: ";
        cin >> K;
        
        cout << "Enter needed amount of zeros to do a task: ";
        cin >> M1;
        
        n1 = n + M1;
        
        cout << "Modified array: ";
        do_task_1(array, n, K, M1);
        write_array(array, n);
    }
    
    cout << endl;
}

//За допомогою текстового редактору створити текстовий файл 
//«matr_in_n.txt» з елементами вихідного двовимірного масиву (n - номер 
//варіанта). У програмі зчитати і обробити матрицю відповідно до свого 
//варіанту завдання (лаб.роб.№7, завд.1), ім'я файлу і необхідні змінні ввести з 
//консолі. Дописати результати в той же файл. 
bool enter_matrix(char* filename, int matrix[M][N], int & m, int & n) //введення матриці
{
    ifstream fin(filename);
    
    if (!fin.is_open()) //перевірка на невдале відкриття файлу
    {
        cout << "Error, can't open file!" << endl;
        return false;
    }
    else
    {
        fin >> m;
        fin >> n;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> matrix[i][j];
            }
        }
    }
    
    fin.close();
    
    return true;
}

void present_matrix(const int matrix[M][N], const int m, const int n) //виведення матриці
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        
        cout << endl;
    }
}

void write_matrix(char* filename, const int matrix[M][N], const int m, const int n) //записання результату у відповідний файл
{
    ofstream fout("matr_in_30.txt", ios_base::app);
    
    fout << " \nResult: ";
    
    for (int l = 0; l < n; l++)
    {
        fout << results[l] << " ";
    }
    
    fout.close();
}

void do_task_2(int matrix[M][N], int & m, int & n) //виконання підрахунків, скільки елементів з колони є більших за її середню арифметичну
{
    int a, k, s, sum, count_amount, count_elements, constant;
    float arith_mean = 0;
    
    constant = 0;
    k = 0; 
    s = 0;
    sum = 0;
    count_amount = 0;
    count_elements = 0;
    a = 0;
    
    while (k < n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (constant == j)
                {
                    s = matrix[i][j];
                    sum = sum + s;
                    count_amount += 1;
                }
            }
        }
        
        arith_mean = (sum / count_amount);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (constant == j)
                {
                    if (matrix[i][j] > arith_mean)
                    {
                        count_elements += 1;
                    }
                    
                    if (i == (m - 1))
                    {
                        a = count_elements;
                        results[j] = a;
                    }
                }
            }
        }
        
        cout << "Amount of elements that meet the task conditions in column: "<< count_elements << endl;
        
        
        
        constant = constant + 1;
        k = k + 1;
        
        a = 0;
        sum = 0;
        count_amount = 0;
        count_elements = 0;
    } 
    
    cout << endl;
}

void task_2() //виконання завдання 2
{
    int matrix[M][N];
    int row, col;
    char filename[100];
    
    cout << "Enter filename: ";
    cin.getline(filename, 100);
    
    if (enter_matrix(filename, matrix, row, col))
    {
        cout << "Matrix: " << endl;
        present_matrix(matrix, row, col);
        
        do_task_2(matrix, row, col);
        write_matrix(filename, matrix, row, col);
    }
}

//Вивчити метод сортування відповідно до свого варіанту (варіант 21) 
//проаналізувати його складність і продемонструвати на прикладі з 7-ми 
//елементів (відповідно до свого варіанту). Реалізувати у вигляді окремої функції 
//алгоритм сортування елементів масиву. Зчитування і виведення відсортованого 
//масиву організувати на файлах. 
bool enter_array_sort(char* filename, int array_sort[N], int & n) //введення масиву для сортування 
{
    ifstream fin(filename);
    
    if (!fin.is_open()) //перевірка на невдале відкриття файлу
    {
        cout << "Error, can't open file!" << endl;
        return false;
    }
    else
    {
        fin >> n;
        
        for (int i = 0; i < n; i++)
        {
            fin >> array_sort[i];
        }
    }
    
    fin.close();
    
    return true;
}

void present_array_sort(const int array_sort[N], const int n) //виведення масуву для сортування
{
    for (int i = 0; i < n; i++)
    {
        cout << array_sort[i] << " ";
    }
    
    cout << endl;
}

void write_array_sort(const int array_sort[N], const int n) //записання відсортованого масиву у відповідний файл
{
    ofstream fout("array_sort_out_21.txt");
    
    for (int i = 0; i < n; i++)
    {
        fout << array_sort[i] << " ";
    }
    
    fout.close();
}

void do_task_3(int array_sort[N], int & n) //виконання сортування масиву
{
    int a, b, k;
    
    k = 0;
    a = 0;
    
    for (int i = 0; i < n; i++)
    {
        a = array_sort[i];
        k = i;
        
        while ((k > 0) && (array_sort[k - 1] > a))
        {
            b = array_sort[k];
            array_sort[k] = array_sort[k - 1];
            array_sort[k - 1] = b;
            
            k--;
        }
        
        array_sort[k] = a;
    }
}

void task_3() //виконання завдання 3
{
    int array_sort[N];
    int n;
    char filename[100];
    
    cout << "Enter filename: ";
    cin.getline (filename, 100);
    
    if (enter_array_sort(filename, array_sort, n))
    {
        cout << "Array to sort: ";
        present_array_sort(array_sort, n);
        
        cout << "Sorted array: ";
        do_task_3(array_sort, n);
        present_array_sort(array_sort, n);
        write_array_sort(array_sort, n);
    }
    
    cout << endl;
}

int main() //головне меню
{
    int task_num;
    
    do 
    {
        cout << "Task number: ";
        cin >> task_num;
        cin.ignore(32767, '\n');
        
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
}