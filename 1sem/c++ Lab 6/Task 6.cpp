#include <iostream>
#include<string>
using namespace std;

int fact(int n)
{   
    if (n > 1) return n * fact(n - 1);
    else return 1;
}

int main()
{
    cout << "The program will calculate the number of different anagrams that can be obtained from word\n\n";
    string word;
    int len,res;
    cout << "Enter word: ";
    cin >> word;
    len = word.size();
    res = fact(len);
    for (int i = len - 1; i > 0; i--) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (word[j] > word[j + 1]) 
            {
                int temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }
   int count = 1;
   for (int i = 0; i < len - 1; i++)
   {
       for (int j = i + 1; j < len; j++)
       {
           if (word[i] == word[j])
           {
                count++;
                res /= count;
                break;
           }
           else if (word[i] != word[j])
           {
               count = 1;
           }
       }
   }
   cout <<"The number of different anagrams is " << res << endl;
   system("pause");
   return 0;
}

