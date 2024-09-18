#include "helper.cpp"
using namespace std;

bool isSubsequence(string s, string t)
{
    int sp = 0;
    int tp = 0;
    int sl = s.length();
    int tl = t.length();
    while (tp < tl)
    {
        if (s[sp] == t[tp])
        {
            sp++;
            if (sp == sl)
            {
                return true;
            }
        }
        tp++;
    }
    return false;
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t);
    return 0;
}
