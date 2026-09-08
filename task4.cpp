#include <iostream>
using namespace std;
int findPattern(string text, string pattern)
{
    if (pattern == "")
        return 0;
    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        if (text.substr(i, pattern.length()) == pattern)
            return i;
    }
    return -1;
}
int main()
{
    cout << findPattern("nust seecs", "nust") << endl; // on Beginning
    cout << findPattern("nust seecs", "seecs") << endl;  // in End
    cout << findPattern("nust seecs", "dsa") << endl;//dsa word not present
    cout << findPattern("nust seecs", "") << endl;  // Empty pattern
    return 0;
}