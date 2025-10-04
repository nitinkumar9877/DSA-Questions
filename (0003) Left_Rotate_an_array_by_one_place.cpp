#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums)
    {
        int n = nums.size();
        int first = nums[0];
        for (int i = 1; i < n; i++)
        {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = first;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution s;
    s.rotate(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
