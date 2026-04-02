#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int N, M;
const int K = 10;
int results[K];

//Використати вивчений метод класу string та створити свою функцію, яка виконуватиме тіж самі дії. Використати метод та функцію для порівняння двох рядків.
void compare_rows(string str_1, string str_2)
{
    int i = 0;
    int j = 0;
    
    if (N == M)
    {
        while (i < N && j < M)
        {
            if(str_1[i] != str_2[j])
            {
                if (i == (N - 1) && j == (M - 1))
                {
                    cout << "Words are different!" << endl;
                }
                
                i = i + 1;
                j = j + 1;
            }
            
            if (str_1[i] == str_2[j])
            {
                if (i == (N - 1) && j == (M - 1))
                {
                    cout << "Words from two lines are same." << endl;
                }
                
                i = i + 1;
                j = j + 1;
            }
        }
    }
    else
    {
        cout << "Words are different!" << endl;
    }
    
    cout << endl;
}

void task_1() //викрнання завдання номер 1
{
    string str_1, str_2;
    N = 0;
    M = 0;
    
    cout << "Enter text: ";
    cin >> str_1;
    N = str_1.size();
    
    cout << "Enter text: ";
    cin >> str_2;
    M = str_2.size();
    
    if (str_1.compare(0, M, str_2) == 0)
    {
        cout << "Words from two lines are same." << endl;
    }
    else
    {
        cout << "Words are different!" << endl;
    }
    
    compare_rows(str_1, str_2);
}

//Дано рядок – речення  англійською мовою. Підрахувати кількість 
//розділових знаків в ньому. 
bool enter_sentences(char* filename, string sentences[K]) //введення 10 речень
{
    ifstream fin(filename);
    
    if(!fin.is_open())
    {
        cout << "Error, can't open file!" << endl;
        return false;
    }
    else
    {
        for (int i = 0; i < K; i++)
        {
            if(!getline(fin, sentences[i])) //зчитуємо речення з файлу і представляємо їх як масив, де кожне речення це один елемент масиву 
               break;
        } 
    }
    
    fin.close();
    
    return true;
}

void present_sentences(const string sentences[K]) //представлення 10 речень з завдання
{
    for (int i = 0; i < K; i++)
    {
        cout << sentences[i]  << endl;
    }
    
    cout << endl;
}

void write_result(char* filename, const string sentences[K]) //записування результатів виконання завдання до файлу
{
    ofstream fout("task_2.txt", ios_base::app);
    
    fout << " \nResult: ";
    
    for(int i = 0; i < K; i++)
    {
        fout << results[i] << " ";
    }
    
    fout.close();
}

void find_punctation_marks(string sentences[K]) //пошук розділових знаків в реченнях
{
    int a = 0;
    char sentences_sym[K][300];
    int size = 0;
    
    for(int i = 0; i < K; i++) //записання речень з файлу у масив, де кожне речення є одним елементом, але також беруться під увагу окремі елементи(літери, пробіли, символи, розділові знаки)
    {
        size = sentences[i].length();
        
        for(int j = 0; j < size; j++)
        {
            sentences_sym[i][j] = sentences[i][j];
        }
        
        sentences_sym[i][size] = '\0'; //перехід на новий рядок
    }
    
    for(int s = 0; s < K; s++)
    {
        for(int t = 0; sentences_sym[s][t] != '\0'; t++)
        {
            if(ispunct((unsigned char)sentences_sym[s][t])) //вбудована функція, яка підраховує кількість розділових знаків в кожному реченні
            {
                a = a + 1; 
            }
        }
            
        results[s] = a;
        a = 0;
    }
}

void present_results(const int results[K]) //представлення результатів в консолі
{
    for(int i = 0; i < K; i++)
    {
        cout << results[i] << " ";
    }
    
    cout << endl;
}

void task_2() //виконання завданяя номер 2
{
    string sentences[K];
    char filename[100];
    
    cin.ignore(100, '\n');
    
    cout << "Enter filename: ";
    cin.getline(filename, 100);
    
    if(enter_sentences(filename, sentences))
    {
        cout << "Sentences: " << endl;
        present_sentences(sentences);
        
        cout << "Results: ";
        find_punctation_marks(sentences);
        present_results(results);
        write_result(filename, sentences);
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
        
        switch (task_num)
        {
            case 1: task_1(); break;
            case 2: task_2(); break;
            case 0: cout << "Ending of doing tasks."; break;
            default: cout << "Wrong task number!" << endl;
        }
    }
    while(task_num != 0);
    
    return 0;
}