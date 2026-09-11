class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high){
        int l = low, r = mid+1;
        int i = 0, c = 0;
        vector<int> temp;
        long long ele = arr[mid+1];
        int x = mid+1;
        for(int i = low; i < mid+1; i++){
            while((x <= high) && ((long long)arr[i] > 2 * (long long) arr[x])){
                c+= (mid-i+1);
                x++;
                // ele = arr[x];
            }
        }
        while(l<=mid && r<=high){
            if(arr[l] > arr[r]){
                temp.push_back(arr[r++]);
                i++;
            }else {
                temp.push_back(arr[l++]);
                i++;
            }
        }
        while(l<=mid){
            temp.push_back(arr[l++]);
            i++;
        }
        while(r <= high){
            temp.push_back(arr[r++]);
            i++;
        }
        for(int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
        return c;
    }
    int findinversions(vector<int> &arr, int low, int high){
        int count = 0;
        if(low >= high) return count;
        int mid = (low+high)/2;
        count += findinversions(arr, low, mid);
        count += findinversions(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        count = findinversions(nums, 0, nums.size()-1);
        return count;     
    }
};