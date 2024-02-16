#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
string sort_decend(string s)
{
    priority_queue<pair<int, char>> pq;
    unordered_map<unsigned char, int> mp;
    string st;
    for (const auto &v : s)
    {
        mp[v]++;
    }
    for (const auto &v : mp)
    {
        pq.push({v.second, v.first});
    }
    while (!pq.empty())
    {
        auto pair = pq.top();
        pq.pop();
        st.append(pair.first, pair.second);
    }
    return st;
}
int main()
{
    string s;
    cin >> s;
    string str = sort_decend(s);
    cout << "The sorted string : " << str << endl;
    return 0;
}