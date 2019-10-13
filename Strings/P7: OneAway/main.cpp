#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isOneAway(string first, string second)
{
    int lengthdiff = first.length() - second.length();
    bool difference = 0;

    if (abs(lengthdiff) > 1)
        return false;

    if (first.length() == second.length())
    {
        // They can be one replacement away
        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] != second[i])
            {
                if (difference)
                    return false;
                difference = 1;
            }
        }
        return true;
    }
    else
    {
        // s1 is my shortest string and s2 is the longest string
        string s1 = first.length() < second.length() ? first : second;
        string s2 = first.length() < second.length() ? second : first;
        int index1 = 0, index2 = 0;

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