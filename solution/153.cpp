//Binary Search
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]||nums.size()==1)return nums[0];
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[left]<nums[mid])left=mid;
            else right=mid;
        }
        return nums[left+1];
    }
};
//Divide and Conquer
class Solution {
public:
    int helper(vector<int>& nums,int start,int end){
        if(nums[start]<=nums[end])return nums[start];
        int mid=(start+end)/2;
        return min(helper(nums,start,mid),helper(nums,mid+1,end));
    }
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};

class Solution {
public:
    int helper(vector<int>& nums,int l,int r){
        if(nums[l]<nums[r])return nums[l];
        if(r-l<=1)return min(nums[l],nums[r]);
        int mid=(l+r)/2;
        return min(helper(nums,l,mid-1),helper(nums,mid,r));
    }
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};