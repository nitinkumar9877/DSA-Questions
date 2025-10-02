#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        map<int, int> hashArray;
        for (int i = 0; i < nums.size(); i++)
        {
            hashArray[nums[i]]++;
        }

        int count = 0;
        for (auto it : hashArray)
        {
            nums[count] = it.first;
            count++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
