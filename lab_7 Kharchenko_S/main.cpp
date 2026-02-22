#include <iostream>
using namespace std;
int const m = 20;
int const n = 20;

//Дана матриця розміру M × N. У кожному її стовпці знайти кількість 
//елементів, більших ніж середнє арифметичне всіх елементів цього 
//стовпчика. 
void enter_matrix(int ** matrix, int M, int N) //введення елементів масиву
{
    cout << "Amount of rows: ";
    cin >> M;
    cout << "Amount of columns: ";
    cin >> N;
    
    cout << "Element of matrix: " << endl;
    
    for (int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin << matrix[i][j] << endl;
        }
    }
    
    cout << endl;
}

void present_matrix(int M, int N, int ** matrix) //виведення масиву
{
    cout << "Elements of matrix: " << endl;
    
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << endl;
}

void find_amount_of_right_elements(int ** matrix, int M, int N) //знаходження кількості елементів в стовпці більших за середню арифметичну цього стовпця
{
    int sum, count_amount, count_elements, constant, k, s;
    double arith_mean;
    constant = 1;
    k = 0;
    s = 0;
    arith_mean = 0;
    sum = 0;
    count_amount = 0;
    count_elements = 0;
    
    while (k < N)
    {
       for (int i = 1; i <= M; i++)
       {
           for (int j = 1; j <= N; j++)
           {
               if (constant == j)
               {
                  s = matrix[i][j];
                  sum = sum + s;
                  count_amount += 1;
               }
               
            constant += 1; 
            
            }
        } 
    
        arith_mean = (sum / count_amount);
    
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
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
        
        cout << "Amount of elements that meet the task conditions in column: " << count_elements << endl;
    }
    
    cout << endl;
}

void task_1() //виконання завдання 1
{
    int M, N;
    int matrix[M][N];
    
    enter_matrix(matrix, M, N);
    present_matrix(M, N, matrix);
    find_amount_of_right_elements(matrix, M, N);
}

//Дана матриця розміру M × N і ціле число K (1 ≤ K ≤ N). Після стовпчика 
//матриці з номером K вставити стовпець з одиниць. 
void add_column(int M, int N, int K, int ** matrix) //вставлення стовпця з одиниць після стовпця під номером К
{
    int t;
    int В[M][N];
    int d = 1;
    t = K + 1;
    
    cout << "Modified matrix: " << endl;
    
    for (int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
    
    for (int a = 1; a <= M; a++)
    {
        for (int b = 1; b <= (N - K); b++)
        {
            В[a][b] = matrix[a][t];
            t = t + 1;
        }
    }
    
    for (int k = 1; k <= M; k++)
    {
        for (int l = (K + 1); l < (K + 2); l++)
        {
            matrix[k][l] = d;
            cout << matrix[k][l] << " ";
        }
    }
    
    for (int x = 1; x <= M; x++)
    {
        for (int y = 1; y <= (N - K); y++)
        {
            cout << В[x][y] << " ";
        }
    }
    
    cout << endl;
}

void task_2() //виконання завдання 2
{
    int M, N, K, matrix[M][N];
    
    cout << "Number of column after which must be added new column: ";
    cin >> K;
    
    enter_matrix(matrix, M, N);
    present_matrix(M, N, matrix);
    add_column(M, N, K, matrix);
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
           default: cout << "Wrong task!" << endl;
        }
    }
    while (task_num != 0);
    
    return 0;
}