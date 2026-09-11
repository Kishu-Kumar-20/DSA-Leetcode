class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high){
        int l = low, r = mid+1;
        vector<int> temp;
        while(l<=mid && r<=high){
            if(arr[l] > arr[r]){
                temp.push_back(arr[r++]);
            }else {
                temp.push_back(arr[l++]);
            }
        }
        while(l<=mid){
            temp.push_back(arr[l++]);
        }
        while(r <= high){
            temp.push_back(arr[r++]);
        }
        for(int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
    }
    int countreverse(vector<int> &arr, int low, int mid, int high){
        int c = 0;
        int right = mid+1;
        for(int i = low; i < mid+1; i++){
            while((right <= high) && ((long long)arr[i] > 2 * (long long) arr[right])) right++;
            c += (right - (mid+1));
        }
        return c;
    }
    int findinversions(vector<int> &arr, int low, int high){
        int count = 0;
        if(low >= high) return count;
        int mid = (low+high)/2;
        count += findinversions(arr, low, mid);
        count += findinversions(arr, mid+1, high);
        count += countreverse(arr, low, mid, high);
        merge(arr, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        count = findinversions(nums, 0, nums.size()-1);
        return count;     
    }
};