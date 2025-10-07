#include <iostream>
#include <vector>
using namespace std;

// nums = {4, 1, 2, 1, 2}
// | Step | Current num (i) | xorr before | Operation | xorr after | Explanation               |
// | ---- | --------------- | ----------- | --------- | ---------- | ------------------------- |
// | 1    | 4               | 0           | 0 ^ 4     | 4          | Start XOR with 4          |
// | 2    | 1               | 4           | 4 ^ 1     | 5          | (Binary: 100 ^ 001 = 101) |
// | 3    | 2               | 5           | 5 ^ 2     | 7          | (Binary: 101 ^ 010 = 111) |
// | 4    | 1               | 7           | 7 ^ 1     | 6          | (Binary: 111 ^ 001 = 110) |
// | 5    | 2               | 6           | 6 ^ 2     | 4          | (Binary: 110 ^ 010 = 100) |


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (auto i : nums) {
            xorr ^= i;
        }
        return xorr;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    // Function call
    int result = sol.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}
