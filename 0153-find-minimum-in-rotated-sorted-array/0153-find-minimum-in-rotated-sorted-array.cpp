class Solution {
public:
int index(vector<int> &arr){
        int low = 0;
        int high = arr.size()-1;
        int _min = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            _min = min(arr[mid], _min);
            if(arr[low] <= arr[high]){
                _min = min(arr[low], _min);
            }
            if(arr[mid] >= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return _min;
    }
    int findMin(vector<int>& nums) {
        return index(nums);
    }   
};