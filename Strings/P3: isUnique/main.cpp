#include <iostream>
#include <string>
using namespace std;

bool isUnique(string str)
{
    if (str.length() == 0)
    {
        return true;
    }
    int uniqueChar[128] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        if (uniqueChar[str[i]] == 1)
        {
            return false;
        }
        else
        {
            uniqueChar[str[i]] = 1;
        }
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    cout << isUnique(str) << endl;
    return 0;
}
