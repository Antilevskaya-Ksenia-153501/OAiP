#include <iostream>
#include <string>
using namespace std;

int expandfromCenter(string str, int left, int right)
{
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

string palindrome(string str) 
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < str.size(); i++) 
    {
        int len1 = expandfromCenter(str, i, i);
        int len2 = expandfromCenter(str, i, i + 1);
        int len;
        if (len1 > len2) len = len1;
        else len = len2;
        if (len > end - start) 
        {
            start = i - ((len - 1) / 2);
            end = i + (len / 2);
        }
    }
    return str.substr(start,end);
}

int main()
{
    cout << "This program will find the longest substring that is not a palindrome\n\n";
    string str;
    string palindrome;
    cout << "Enter string: ";
    cin>> str;
    int start = 0;
    int end = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int len1 = expandfromCenter(str, i, i);
        int len2 = expandfromCenter(str, i, i + 1);
        int len;
        if (len1 > len2) len = len1;
        else len = len2;
        if (len > end - start)
        {
            start = i - ((len - 1) / 2);
            end = i + (len / 2);
        }
    }
    palindrome = str.substr(start, end + 1 - start);
    cout << "Palindrome: " << palindrome << endl;
    cout << "Maximum non-palindrome lenght: ";
    if (palindrome.size() + start > palindrome.size() + str.size() - end - 1 && start != 0 && str.size() - end - 1 != 0) cout << palindrome.size() + start<< endl;
    else if ( start == 0 && str.size() - end - 1 == 0) cout << palindrome.size() - 1<< endl;
    else if (start == 0 && str.size() - end - 1 != 0) cout << palindrome.size() - 2 + str.size() - end << endl;
    else if (start != 0 && str.size() - end - 1 == 0) cout << palindrome.size() + start - 1 << endl;
    else if (palindrome.size() + start < palindrome.size() + str.size() - end - 1 && start != 0 && str.size() - end - 1 != 0) cout<<palindrome.size() + str.size() - end - 1<< endl;
    else if (start == str.size() - end - 1) cout << palindrome.size() + start << endl;
    system("pause");
    return 0;
}

