#include "./helper.cpp"
#include <unordered_set>

vector<string> res;
string bitMask = "0000000000";
unordered_set<string> myMap;

void dfs(int bitRemain, int currentHour, int currentMin)
{
    if (currentHour >= 12 || currentMin >= 60)
        return;
    if (myMap.find(bitMask) != myMap.end())
    {
        return;
    }
    if (bitRemain == 0)
    {
        myMap.insert(bitMask);
        res.push_back(to_string(currentHour) + ":" +
                      (currentMin < 10 ? "0" : "") + to_string(currentMin));
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (bitMask[i] - '0' == 0)
        {
            bitMask[i] = '1';
            dfs(bitRemain - 1, currentHour + pow(2, i), currentMin);
            bitMask[i] = '0';
        }
    }
    for (int i = 4; i < 10; i++)
    {
        if (bitMask[i] - '0' == 0)
        {
            bitMask[i] = '1';
            dfs(bitRemain - 1, currentHour, currentMin + pow(2, i - 4));
            bitMask[i] = '0';
        }
    }
}

vector<string> readBinaryWatch(int turnedOn)
{
    if (turnedOn >= 9)
        return {};
    int currentHour = 0;
    int currentMin = 0;
    dfs(turnedOn, currentHour, currentMin);
    return res;
}

int main()
{
    return 0;
}