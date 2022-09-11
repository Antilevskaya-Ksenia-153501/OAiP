#include <iostream>

int main()
{
    std::cout << "In a string, that consists of ones and zeroes, the program will count the number of symbols in the longest group\n\n";
    int lenght, count = 1, max = 0;
    char str[80] = {};
    std::cout << "Enter a string, that consists of groups of zeros and ones: ";
    std::cin >> str;
    std::cout << "Your string: " << str << std::endl;
    lenght = strlen(str);
    for (int i = 0; i < lenght; i++)
    {
        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        if (max < count) max = count;
        count = 1;
    }
    std::cout << "The number of symbols in the longest group: " << max << std::endl;
    system("pause");
    return 0;
}

