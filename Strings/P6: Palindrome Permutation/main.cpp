#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

bool isPalindromePermutation(string s)
{
    unordered_map<char, int> myMap;
    int even_count = 0;

    // Llenar el map
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            myMap[s[i]] += 1;
        }
    }

    for (auto x : myMap)
    {
        if (x.second % 2 != 0)
        {
            even_count++;
        }
    }

    if (even_count > 1)
    {
        return false;
    }
    return true;
}

int main()
{
    string input;
    getline(cin, input);
    cout << isPalindromePermutation(input) << endl;
}