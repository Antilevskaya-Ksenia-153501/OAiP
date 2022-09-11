#include <iostream>

int main()
{
    int n = 1;
    double d0, d = 0, ε = 0.001;
    do
    {
        d0 = pow(1. / 2, n) + pow(1. / 3, n);
        d += d0;
        n++;
    } 
    while (d0 > ε);
    std::cout << "d = 1/2 + 1/3 + 1/4 + 1/9 + ... + (1/2)^n + (1/3)^n = " << d << std::endl;
    system("pause");
    return 0;
}

