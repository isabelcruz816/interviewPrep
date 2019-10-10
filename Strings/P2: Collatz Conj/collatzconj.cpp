#include <iostream>
using namespace std;

int collatz(int n)
{
    if (n % 2 == 0)
    {
        return n / 2;
    }
    else
    {
        return n * 3 + 1;
    }
}

int main()
{
    int number;
    cin >> number;

    if (number > 0)
    {
        while (number != 1)
        {
            number = collatz(number);
            cout << number << endl;
        }
    }

    return 0;
}