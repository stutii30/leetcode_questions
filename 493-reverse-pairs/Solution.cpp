class Solution {
public:
int count(vector<int>& nums, int low, int mid, int high){
    int ct=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high and (long long) nums[i]> (long long) 2*nums[j]){
            j++;
        }
        ct+=(j-(mid+1));
    }
    return ct;
}
void merge(vector<int>& nums, int left, int mid, int right){
    vector<int>a;
    int i=left, j=mid+1;
    while(i<=mid and j<=right){
        if(nums[i]<=nums[j]){
            a.push_back(nums[i]);
            i++;
        }
        else{
            a.push_back(nums[j]);
            j++;
        }
    }
        while(i<=mid) {
            a.push_back(nums[i]);
            i++;
        }
        while(j<=right){
            a.push_back(nums[j]);
            j++;
        }
        for(int k=left;k<=right;k++){
            nums[k]=a[k-left];
        }
}
    int mergesort(vector<int>&nums, int left,int right){
        if(left>=right) return 0;
        int mid=left+(right-left)/2;
        int c= mergesort(nums,left,mid)+mergesort(nums,mid+1,right);
       c+=count(nums,left,mid, right);
       merge(nums,left,mid,right);
        return c;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);

    }
};