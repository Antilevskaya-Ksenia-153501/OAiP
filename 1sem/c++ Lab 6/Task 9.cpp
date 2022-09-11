#include <iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    cout << "The program will calculate sum of all numbers in a string\n\n";
    string s;
    getline(cin,s);
    stringstream ss(s);
    int sum = 0;
    for (;ss.rdbuf()->in_avail()!= 0;)
    {
        int a = 0;
        ss >> a;
        ss.clear();
        ss.get();
        sum += a;
    }
    cout<< sum <<endl;
    system("pause");
    return 0;
}



