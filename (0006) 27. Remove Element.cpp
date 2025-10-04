#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // Example Input
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << "Number of elements after removal: " << k << endl;
    cout << "Array after removing " << val << ": ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}