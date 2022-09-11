#include <string>
#include <iostream>

using namespace std;

int main() 
{
    string s1, s2;
    int len1, n, lencount = 0, t = 1;
    cout << "Enter s1: ";
    getline(cin, s1);
    cin.get();
    cout << "Enter s2: ";
    getline(cin, s2);
    cin.get();
    for (int i = 0; i < s1.size(); i++) 
    {
        if (s1[i] = s2[0]) 
        {
            int j = 0, i1 = i;
            while (s2[j] == s1[i1]) 
            {
                j++; lencount++;
                if (s1[i1 + 1] != s2[j] || j >= s2.size() || i1 >= s1.size()) 
                {
                    break;
                }
                i1++;
            }
            i1 = i1 - 1;
            while (s2[j] == s1[i1])
            {
                j++; lencount++;
                if (i1 == 0) 
                {
                    break;
                }
                i1--;
            }
            if (lencount == s2.size())
            {
                t *= 0;
            }
        }
    }
    if (!t) cout << "Yes" << endl;
    else cout << "No" << endl;






    system("pause");
    return 0;
}