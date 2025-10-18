#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0, val = LONG_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            val = max(val, sum);
            if (sum < 0)
                sum = 0;
        }

        return val;
    }
};
// | Index (i) | nums[i] | sum (current running sum) | val (max so far) | Explanation               |
// | --------- | ------- | ------------------------- | ---------------- | ------------------------- |
// | 0         | -2      | -2                        | -2               | Start: sum = -2, val = -2 |
// |           |         | sum < 0 → reset to 0      |                  |                           |
// | 1         | 1       | 0 + 1 = 1                 | max(-2, 1) = 1   | sum positive → keep it    |
// | 2         | -3      | 1 + (-3) = -2             | max(1, -2) = 1   | sum < 0 → reset to 0      |
// | 3         | 4       | 0 + 4 = 4                 | max(1, 4) = 4    | sum positive              |
// | 4         | -1      | 4 + (-1) = 3              | max(4, 3) = 4    | keep sum                  |
// | 5         | 2       | 3 + 2 = 5                 | max(4, 5) = 5    | sum increases             |
// | 6         | 1       | 5 + 1 = 6                 | max(5, 6) = 6    | best so far               |
// | 7         | -5      | 6 + (-5) = 1              | max(6, 1) = 6    | sum small but positive    |
// | 8         | 4       | 1 + 4 = 5                 | max(6, 5) = 6    | final sum 5               |

int main()
{
    Solution obj;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << obj.maxSubArray(nums) << endl;
    return 0;
}
