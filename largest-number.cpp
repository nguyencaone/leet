#include "./helper.cpp"
using namespace std;

static bool isLarge(const int &n1, const int &n2)
{
    string a = to_string(n1) + to_string(n2);
    string b = to_string(n2) + to_string(n1);
    return a > b;
}

string largestNumber(vector<int> &nums)
{
    int n = nums.size();
    string res = "";
    sort(nums.begin(), nums.end(), isLarge); // Sort using the custom comparator
    for (int i = 0; i < n; i++)
    {
        res += to_string(nums[i]);
    }
    int count = 0;
    while (res.length() > count && res[count] == '0')
    {
        count++;
    }
    if (count == n)
        count--;
    res = res.substr(count, res.length() - count);
    return res;
}

int main()
{
    vector<int> v = {1, 2, 3};
    cout << largestNumber(v);
    return 0;
}