class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty()) return 0;

        map<int,int> hashArray;
        for(int i=0; i<nums.size(); i++){
            hashArray[nums[i]]++;
        }

        int count = 0;
        for(auto it: hashArray){
            nums[count] = it.first; 
            count++;
        }

        return count;
    }
};
