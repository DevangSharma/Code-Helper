/*QUES

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

*/

/****************************************************CODE*********************************************/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int mini = 1 , maxi = 1;
        int res = *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                mini = 1;
                maxi = 1;
            }
            int temp = nums[i]*maxi;
            maxi = max(nums[i]*mini,max(nums[i]*maxi,nums[i]));
            mini = min(nums[i]*mini,min(temp,nums[i]));
            
            res = max(res,max(maxi,mini));
        }
        
        return res;
    }
};
