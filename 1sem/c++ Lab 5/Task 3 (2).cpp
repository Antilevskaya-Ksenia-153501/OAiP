#include <iostream>
using namespace std;
double** creation(int n, int m) 
{
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new double[m];
    }
    return matrix;
}
void initialization(double** matrix, int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << "Enter a[" << i << j << "]: ";
            cin >> matrix[i][j];
            if (cin.fail()) 
            {
                cout << "Error.Enter a correct number,please!!!" << endl;
                exit(0);
            }
        }
    }
    return;
}
void output(double** matrix, int n, int m)
{
    cout << endl << "Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return;
}
void zero(double** matrix, int n, int m) 
{
    int count = 0;
    cout << endl << "Indices of elements equal to zero: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout << i << " " << j << "; ";
                count++;
            }
            
        }
    }
    cout << "\nNumber of elements equal to zero: " << count<<endl;
    return;
}
void inverse (double** matrix, int n, int m) 
{
    cout << endl << "New array: " << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "The program will find elemnts of matrix equal to zero and rearrange the elements of matrix in reverse order" << endl;
    cout << endl << "Enter number of rows: ";
    cin >> n;
    if (cin.fail() || n <= 0)
    {
        cout << "Error.Enter a correct number,please!!!" << endl;
        exit(0);
    }
    cout << "Enter number of columns: ";
    cin >> m;
    if (cin.fail() || m <= 0)
    {
        cout << "Error.Enter a correct number,please!!!" << endl;
        exit(0);
    }
    double** matrix = creation(n, m);
    initialization(matrix, n, m);
    output(matrix, n, m);
    zero(matrix, n, m);
    inverse(matrix, n, m);
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
   system("pause");
   return 0;
}

