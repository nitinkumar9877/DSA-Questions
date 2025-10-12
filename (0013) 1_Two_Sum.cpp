#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            int pendingTarget = target - nums[i];
            if (mpp.find(pendingTarget) != mpp.end())
            {
                return {mpp[pendingTarget], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};

// give array[2,5,1,6,8,7,12,10] target = 13
// | i | nums[i] | pendingTarget (`13 - nums[i]`) | Is pendingTarget in map? | Map after step (`mpp`)         | Match Found? | Return   |
// | - | ------- | ------------------------------ | ------------------------ | ------------------------------ | ------------ | -------- |
// | 0 | 2       | 11                             | ❌ No                     | {2: 0}                         | ❌ No         | -        |
// | 1 | 5       | 8                              | ❌ No                     | {2: 0, 5: 1}                   | ❌ No         | -        |
// | 2 | 1       | 12                             | ❌ No                     | {2: 0, 5: 1, 1: 2}             | ❌ No         | -        |
// | 3 | 6       | 7                              | ❌ No                     | {2: 0, 5: 1, 1: 2, 6: 3}       | ❌ No         | -        |
// | 4 | 8       | 5                              | ✅ Yes (5 at index 1)     | {2: 0, 5: 1, 1: 2, 6: 3, 8: 4} | ✅ Yes        | `[1, 4]` |

int main()
{
    Solution solution;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices found: [" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
