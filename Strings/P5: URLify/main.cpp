#include <iostream>
#include <cstring>
using namespace std;

int const MAX = 10000;

int replaceSpaces(char s[])
{
    int space_count = 0, i = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
        {
            space_count++;
        }
    }

    // Remove traling spaces
    while (s[i - 1] == ' ')
    {
        space_count--;
        i--;
    }

    // Find new length
    int newLength = i + space_count * 2 + 1;

    if (newLength > MAX)
        return -1;
    int index = newLength - 1;
    s[index--] = '\0';

    for (int j = i - 1; j >= 0; j--)
    {
        if (s[index] == ' ')
        {
            s[index] = '0';
            s[index - 1] = '2';
            s[index - 2] = '%';
            index = index - 3;
        }
        else
        {
            s[index] = s[j];
            index--;
        }
    }
    return newLength;
}

int main()
{
    char s[1000] = "Mr John Smith";
    int newLength = replaceSpaces(s);
    for (int i = 0; i < newLength; i++)
    {
        cout << s[i];
    }
    cout << endl;
    return 0;
}