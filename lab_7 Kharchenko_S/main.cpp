#include <iostream>
using namespace std;
const int M = 20, N = 20; //максимальне кількість рядків та стовпців

//Дана матриця розміру M × N. У кожному її стовпці знайти кількість 
//елементів, більших ніж середнє арифметичне всіх елементів цього 
//стовпчика. 
void enter_matrix(int matrix [M][N], int & m, int & n) //введення масиву
{
    if (m >= 2 && m <= 20 && n >= 2 && n <= 20)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << "Enter [" << i << "][" << j << "] element of matrix: ";
                cin >> matrix[i][j];
            }
        }
    }
    else
    {
        cout << "Write right amount rows and columns!";
    }
    
    cout << endl;
}

void present_matrix(const int matrix[M][N], const int m, const int n) //виведення масиву
{
    cout << "Matrix: " << endl;
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << endl;
}

void elements(int matrix[M][N], int & m, int & n) //зноходження кількості елементів в стовпці, які будуть більшими за середнє арифметичне
{
    int k, s, sum, count_amount, count_elements, constant;
    float arith_mean = 0;
    
    constant = 1;
    k = 1;
    s = 0;
    sum = 0;
    count_amount = 0;
    count_elements = 0;
    
    while(k <= n)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
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
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (constant == j)
                {
                    if (matrix[i][j] > arith_mean)
                    {
                        count_elements += 1;
                    }
                }
            }
        }
        
        cout << "Amount of elements that meet the task conditions in column " << constant << ": " << count_elements << endl;
        
        constant = constant + 1;
        k = k + 1;
        
        sum = 0;
        count_amount = 0;
        count_elements = 0;
    }
    
    cout << endl;
}

void task_1() //виконання завдання 1
{
    int matrix_1[M][N];
    int row_1, col_1;
    
    cout << "Amount of rows (from 2 to 20): ";
    cin >> row_1;
    cout << "Amount of columns (from 2 to 20): ";
    cin >> col_1;
    
    enter_matrix(matrix_1, row_1, col_1);
    present_matrix(matrix_1, row_1, col_1);
    elements(matrix_1, row_1, col_1);
}

//Дана матриця розміру M × N і ціле число K (1 ≤ K ≤ N). Після стовпчика 
//матриці з номером K вставити стовпець з одиниць. 
void add_column(int matrix[M][N], int & m, int & n, int K) //вставлення стовпця одиниць після стовпця матриці під номером К
{
    int B[M][N];
    int d = 1;
    int b = 1;
    int t = (K + 1);
    
    cout << "Modified matrix: " << endl;
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= K)
            {
                cout << matrix[i][j] << " ";
            }
            
            if (j >= (K + 1))
            {
                
                if (b <= (n - K))
                {
                    B[i][b] = matrix[i][j];
                }
                
                if (j == (K + 1))
                {
                    matrix [i][t] = d;
                    cout << matrix[i][t] << " ";
                }
                
                if (b <= (n - K))
                {
                    cout << B[i][b] << " ";
                }
                
                b = b + 1;
                t = t + 1;
            }
        }
        
        b = 1;
        t = (K + 1);
        
        cout << endl;
    }
    
    cout << endl;
}

void task_2() //виконяння завдання 2
{
    int matrix_2[M][N];
    int row_2, col_2;
    int K;
    
    cout << "Amount of rows (from 2 to 20): ";
    cin >> row_2;
    cout << "Amount of columns (from 2 to 20): ";
    cin >> col_2;
    cout << "Number of column after which must be added new column: ";
    cin >> K;
    
    if (K >= 1 && K <= N)
    {
        enter_matrix(matrix_2, row_2, col_2);
        present_matrix(matrix_2, row_2, col_2);
        add_column(matrix_2, row_2, col_2, K);
    }
    else
    {
        cout << "Wrong number of column!";
        cout << endl;
    }
}

int main() //головне меню
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
            default: cout << "Wrong task number!" << endl;
        }
    }
    while (task_num != 0);
    
    return 0;
}