#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int LargestElement(vector<int> &nums)
    {
        if (nums.empty())
            return INT_MIN;
        int larger_num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            larger_num = max(larger_num, nums[i]);
        }
        return larger_num;
    }
};
