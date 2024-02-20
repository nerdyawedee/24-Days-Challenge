#include <iostream>
#define INT_MAX 2147483647
#include <unordered_map>
#include <string>
using namespace std;
string minimum_windowsubstring(string s, string t)
{
    if (s.empty() || t.empty())
    {
        return " ";
    }
    unordered_map<char, int> smp;
    unordered_map<char, int> tmp;
    for (char ch : t)
    {
        tmp[ch]++;
    }
    int left = 0, right = 0;
    int min_len = INT_MAX, start = 0;
    int required_char = t.size(), mached_char = 0;
    while (right < s.size())
    {
        char ch = s[right];
        smp[ch]++;
        if (smp[ch] == tmp[ch])
        {
            mached_char++;
        }
        while (required_char == mached_char)
        {
            if ((right - left + 1) < min_len)
            {
                min_len = right - left + 1;
                start = left;
            }
            char left_char = s[left];
            smp[left_char]--;
            if (smp[left_char] < tmp[left_char])
            {
                mached_char--;
            }
            left++;
        }
        right++;
    }
    return min_len == INT_MAX ? " " : s.substr(start, min_len);
}
int main()
{
    string s;
    cout << "Enter the first string : ";
    cin >> s;
    string t;
    cout << "Enter the second string : ";
    cin >> t;

    string str = minimum_windowsubstring(s, t);
    cout << str << endl;
    return 0;
}
