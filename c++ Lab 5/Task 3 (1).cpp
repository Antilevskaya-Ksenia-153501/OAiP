 #include <iostream>
 using namespace std;
 int** creation(int n, int k)
 {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[k];
	}
	return matrix;
 }
 
 void initialization(int**matrix, int n, int k) 
 {
	 for (int i = 0; i < n; i++) 
	 {
		 for (int j = 0; j < k; j++) 
		 {
			 cout << "Enter a[" << i << j << "]: ";
			 cin >> matrix[i][j];
			 if (cin.fail())
			 {
				 cout << "Error. Enter a number, please!!!" << endl;
				 exit(0);
			 }
		 }
	 }
	 return;
 }

 void output(int** matrix, int n, int k) 
 {
	 cout << endl <<"Matrix: " << endl;
	 for (int i = 0; i < n; i++)
	 {
		 for (int j = 0; j < k; j++)
		 {
			 cout << matrix[i][j] << "\t";
		 }
	 cout << endl;
	 }
	 return;
 }
 void multiplication(int* matrix, int n) 
 {    
	 int mult = 1;
	 for (int i = 0; i < n; i++) 
	 {
		 mult *= matrix[i];
	 }
	 cout << endl << endl << "Multiplication of elements of new array: " << mult << endl;
	 return;
 }
 

 
int main()
{
	int n,k,count = 0;
	cout << "The program will create a new matrix from elements located on the main diagonal of the user's matrix and having an even value, calculate the multiplication of elements of new matrix" << endl;
	cout <<endl<< "Enter number of rows: ";
	cin >> n;
	if (cin.fail() || n <= 0)
	{
		cout << "Error. Enter a correct number, please!!!" << endl;
		exit(0);
	}
	cout << "Enter number of columns: ";
	cin >> k;
	if (cin.fail() || k <= 0)
	{
		cout << "Error. Enter a correct number, please!!!" << endl;
		exit(0);
	}
	
	int** matrix = creation(n, k);
	initialization(matrix, n, k);
	output(matrix, n, k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (matrix[i][j] % 2 == 0 && i == j) 
			{
				count++;
			}
		}
	}
	int* matrix1 = new int[count];
	int count1 = 0;
	cout <<endl<< "New matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{	
			if (matrix[i][j] % 2 == 0 && i == j)
			{
				matrix1[count1] = matrix[i][j];
				cout << matrix1[count1] << "\t";
				count1++;
			}
		}
	}
	multiplication(matrix1, count);
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] matrix1;
	system("pause");
	return 0;
}

