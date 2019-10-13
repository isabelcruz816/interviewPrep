#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

bool isPalindromePermutation(string s)
{
    unordered_map<char, int> myMap;

    // Llenar el map
    for (int i = 0; i < s.length(); i++)
    {
        myMap[s[i]] += 1;
    }
    for (auto x : myMap)
    {
        cout << x.first << " " << x.second << endl;
    }
    return true;
}

int main()
{
    string input;
    cout << isPalindromePermutation(input) << endl;
}