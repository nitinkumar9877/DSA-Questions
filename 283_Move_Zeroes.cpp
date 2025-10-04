#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j != -1)
        {
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (nums[i] != 0)
                {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
        }
    }
};

int main()
{
    vector<int> nums = {1, 1, 4, 3, 12, 0, 0, 0, 5, 2, 0, 0, 0, 0};
    Solution s;
    s.moveZeroes(nums);
    for (int x : nums)
        cout << x << " ";
}