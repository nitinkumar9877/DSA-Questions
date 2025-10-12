#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> hash;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int majorElementSize = nums.size() / 2;
            hash[nums[i]]++;
            if (hash[nums[i]] > majorElementSize)
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};

// n = 7
// majorElementSize = 7 / 2 = 3
// | i | nums[i] | hash map     | hash[nums[i]] | Action                | ans |
// | - | ------- | ------------ | ------------- | --------------------- | --- |
// | 0 | 2       | {2: 1}       | 1             | Not > 3               | 0   |
// | 1 | 2       | {2: 2}       | 2             | Not > 3               | 0   |
// | 2 | 1       | {2: 2, 1: 1} | 1             | Not > 3               | 0   |
// | 3 | 1       | {2: 2, 1: 2} | 2             | Not > 3               | 0   |
// | 4 | 1       | {2: 2, 1: 3} | 3             | Not > 3 (== 3)        | 0   |
// | 5 | 2       | {2: 3, 1: 3} | 3             | Not > 3 (== 3)        | 0   |
// | 6 | 2       | {2: 4, 1: 3} | 4             | **> 3 → set ans = 2** | 2   |