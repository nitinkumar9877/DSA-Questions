#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// | i | nums[i] | Condition (nums[i]==1?)  | con (current count) | ans (max count so far) | Explanation                       |
// | - | ------- | -----------------------  | ------------------- | ---------------------- | --------------------------------- |
// | 0 | 1       | ✅ Yes                   | con = 1             | ans = 1                | First 1 found                     |
// | 1 | 1       | ✅ Yes                   | con = 2             | ans = 2                | Second consecutive 1              |
// | 2 | 0       | ❌ No                    | con = 0             | ans = 2                | Reset since we hit a 0            |
// | 3 | 1       | ✅ Yes                   | con = 1             | ans = 2                | New streak starts                 |
// | 4 | 1       | ✅ Yes                   | con = 2             | ans = 2                | Continuing streak                 |
// | 5 | 1       | ✅ Yes                   | con = 3             | ans = 3                | Longest streak (3 consecutive 1s) |

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int con = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                con++;
                ans = max(ans, con);
            } else {
                con = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    // Function call
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive 1s: " << result << endl;

    return 0;
}
