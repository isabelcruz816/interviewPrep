#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    int aux[256] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        aux[s1[i]] += 1;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        aux[s2[i]] -= 1;
    }
    for (int i = 0; i < 256; i++)
    {
        if (aux[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;

    cout << isPermutation(str1, str2) << endl;

    return 0;
}