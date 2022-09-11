#include <iostream>
using namespace std;

int** creation(int n, int n_1) 
{
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
    { 
        matrix[i] = new int[n_1];
    }
    return matrix;
}
void initialize_1(int** matrix, int n, int n_1) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= 5)
            {
                matrix[i][j] = 3 * i * j - 3;
            }
            else if (i > 5 && i < n)
            {
                matrix[i][j] = 2 * i * j - 2;
            }
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
void initialize_2(int** matrix, int n, int n_1) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 7 && i < n)
            {
                matrix[i][j] = 4 * i * j - 5;
            }
            else if (i <= 7)
            {
                matrix[i][j] = 5 * i * j - 4;
            }
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
 int sum(int** matrix,int n, int n_1)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n_1; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n_1 - 1) sum += matrix[i][j];
          
        }
    }
    return sum;
 }

 int main()
{
    cout << "This program will initialize two matrices and calculate the sum of the elements located along the perimeter" << endl;
    int n;
    cout << endl<< "Enter size of matrices: ";
    cin >> n;
    if (cin.fail() || n <= 0)
    {
        cout << "Error. Enter a correct number, please!!!" << endl;
        exit(0);
    }
    int** matrix1;
    int** matrix2;
    matrix1 = creation(n, n);
    cout << "Matrix 1: " << endl;
    initialize_1(matrix1, n, n);
    matrix2 = creation(n, n);
    cout << "Matrix 2: " << endl;
    initialize_2(matrix2, n, n);
    cout << "The sum of the elements of matrix 1,that are located along the perimeter = ";
    cout<< sum(matrix1, n, n);
    cout << endl;
    cout << "The sum of the elements of matrix 2,that are located along the perimeter = ";
    cout<< sum(matrix2, n, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    for (int i = 0; i < n; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    system("pause");
    return 0;
}

