#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int profit = 0;
        int minVal = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int cost = nums[i] - minVal;
            profit = max(profit, cost);
            minVal = min(minVal, nums[i]);
        }
        return profit;
    }
};

// | Index (i) | prices[i] | minVal (min so far) | cost = prices[i] - minVal | profit (max so far) | Explanation                             |
// | --------- | --------- | ------------------- | ------------------------- | ------------------- | --------------------------------------- |
// | 0         | 7         | 7                   | —                         | 0                   | Initialize `minVal` and `profit`        |
// | 1         | 1         | min(7, 1) = 1       | 1 - 1 = 0                 | max(0, 0) = 0       | New lower price found → update `minVal` |
// | 2         | 5         | 1                   | 5 - 1 = 4                 | max(0, 4) = 4       | First profit found → update `profit`    |
// | 3         | 3         | 1                   | 3 - 1 = 2                 | max(4, 2) = 4       | Profit lower than max → no update       |
// | 4         | 6         | 1                   | 6 - 1 = 5                 | max(4, 5) = 5       | New highest profit → update `profit`    |
// | 5         | 4         | 1                   | 4 - 1 = 3                 | max(5, 3) = 5       | Profit lower than max → no update       |

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution sol;
    int result = sol.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}
