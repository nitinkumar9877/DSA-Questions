#include <bits/stdc++.h>
using namespace std;

void reverseArr(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverseArr(nums, 0, n - k - 1);
        reverseArr(nums, n - k, n - 1);
        reverseArr(nums, 0, n - 1);
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution s;
    s.rotate(nums, k);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
