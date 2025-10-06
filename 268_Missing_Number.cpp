#include <bits/stdc++.h>
using namespace std;

// //  First approch
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        int ans = 0;
        for (auto it : hash)
        {
            if (it.first != ans)
            {
                return ans;
            }
            ans++;
        }
        return ans;
    }
};

// best approch
// dry run

// |  A  |  B  | A ^ B |
// | :-: | :-: | :---: |
// |  0  |  0  |   0   |
// |  1  |  0  |   1   |
// |  0  |  1  |   1   |
// |  1  |  1  |   0   |

// |  i  | nums[i] | xor1 (nums XOR) | xor2 (index XOR) |
// | :-: | :-----: | :-------------: | :--------------: |
// |  0  |    9    |    0 ^ 9 = 9    |     0 ^ 0 = 0    |
// |  1  |    6    |    9 ^ 6 = 15   |     0 ^ 1 = 1    |
// |  2  |    4    |   15 ^ 4 = 11   |     1 ^ 2 = 3    |
// |  3  |    2    |    11 ^ 2 = 9   |     3 ^ 3 = 0    |
// |  4  |    3    |    9 ^ 3 = 10   |     0 ^ 4 = 4    |
// |  5  |    5    |   10 ^ 5 = 15   |     4 ^ 5 = 1    |
// |  6  |    7    |    15 ^ 7 = 8   |     1 ^ 6 = 7    |
// |  7  |    0    |    8 ^ 0 = 8    |     7 ^ 7 = 0    |
// |  8  |    1    |    8 ^ 1 = 9    |     0 ^ 8 = 8    |
// return xor1 ^ xor2;
// = 9 ^ 1 = 8 ✅

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            xor1 ^= nums[i];
            xor2 ^= i;
        }

        xor2 ^= n;
        return xor1 ^ xor2;
    }
};

// final code
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = (n * (n + 1)) / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
        }
        return sum;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {3, 0, 1};

    int missing = sol.missingNumber(nums);
    cout << "Missing number is: " << missing << endl;

    return 0;
}