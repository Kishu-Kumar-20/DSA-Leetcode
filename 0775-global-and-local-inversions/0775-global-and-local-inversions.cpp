class Solution {
public:
    long long merge(vector<int> &arr, int low, int mid, int high){
        int l = low, r = mid+1;
        int i = 0, cnt = 0 ;
        int temp[high-low+1];
        while(l<=mid && r<=high){
            if(arr[l] > arr[r]){
                cnt += (mid-l+1);
                temp[i++] = arr[r++];
            }else {
                temp[i++] = arr[l++];
            }
        }
        while(l<=mid){
            temp[i++] = arr[l++];
        }
        while(r <= high){
            temp[i++] = arr[r++];
        }
        for(int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
        return cnt;
    }
    long long findinversions(vector<int> &arr, int low, int high){
        long long cnt = 0;
        if(low >= high) return cnt;
        int mid = (low+high)/2;
        cnt += findinversions(arr, low, mid);
        cnt += findinversions(arr, mid+1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    bool isIdealPermutation(vector<int>& nums) {
        long long count2 = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) count2++;
        }
        long long count1 = findinversions(nums, 0, nums.size()-1);
        return (count1 == count2); 
    }
};