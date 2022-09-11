#include <iostream>
#include<string>
#include<cmath>
using namespace std;


int main()
{
    cout << "The program will determine the number of strings that satisfy restructions\n\n";
    const int alphabet = 26;
    int m, lenght, variation = 0;
    string prefix, suffix;
    cout << "Enter prefix: ";
    cin >> prefix;
    cout << "Enter suffix: ";
    cin >> suffix;
    cout << "Enter lenght of full string: ";
    cin >> lenght;
    cout << "Enter m: ";
    cin >> m;
    if (prefix.size() + suffix.size() > lenght && prefix != suffix) 
    {
        bool n = true;
        for (int i = lenght - suffix.size(); i < prefix.size(); i++) 
        {
            if (prefix[i] != suffix[i - lenght + suffix.size()]) 
            {
                n = false;
            }
        }
        if (n)
        {
            variation++;
        }
        n = true;
        for (int i = lenght - prefix.size(); i < suffix.size(); i++) 
        {
            if (suffix[i] != prefix[i - lenght + prefix.size()]) 
            {
                n = false;
            }
        }
        if (n)
        {
           variation++;
        }
        cout << "Number of possible variants is " << variation << endl;
    }
    else  if (prefix.size() + suffix.size() == lenght)
    {
        variation = 2;
        cout << "Number of possible variants is " << variation << endl;
    }
    else if (prefix.size() + suffix.size() < lenght)
    {
        int between = lenght - (prefix.size() + suffix.size());
        variation = pow(alphabet, between) * 2;
        cout << "Number of possible variants is " << variation % m << endl;
    }
    else if (prefix.size() == lenght && prefix == suffix && suffix.size() == lenght)
    {
        variation = 1;
        cout << "Number of possible variants is " << variation << endl;;
    }
    system("pause");
    return 0;
}

