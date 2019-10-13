#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isOneAway(string first, string second)
{
    int lengthdiff = first.length() - second.length();
    if (abs(lengthdiff) > 1)
        return false;

    // s1 is my shortest string and s2 is the longest string
    string s1 = first.length() < second.length() ? first : second;
    string s2 = first.length() < second.length() ? second : first;

    bool difference = 0;

    if (s1.length() == s2.length())
    {
        // They can be one replacement away
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (difference)
                    return false;
                difference = 1;
            }
        }
    }
    else
    {
        int index1 = 0, index2 = 0;
        // They can be one insert or remove away
        while (index1 < s1.length() && index2 < s2.length())
        {
            if (s1[index1] == s2[index2])
            {
                index1++;
                index2++;
            }
            else
            {
                if (difference)
                    return false;
                difference = 1;
                index2++;
            }
        }
    }

    return true;
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << isOneAway(s1, s2) << endl;
    return 0;
}