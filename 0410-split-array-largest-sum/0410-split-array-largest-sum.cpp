class Solution {
public:
    int no_of_subarrays(vector<int> &arr, int max, int lim){
	    int subarr = 1;
	    int sum = 0;
	    for(int i = 0; i < arr.size(); i++){
	        if(sum + arr[i] > max){
	            sum = arr[i];
	            subarr++;
	        }else{
	            sum += arr[i];
	        }
	        if(subarr > lim) return subarr;
	    }
	    return subarr;
	}
    int splitArray(vector<int>& nums, int k) {
        int low = * max_element(nums.begin(), nums.end());
		long long high = accumulate(nums.begin(), nums.end(), 0);
		while (low <= high) {
			long long mid = low + (high - low)/2;
			int numb = no_of_subarrays(nums, mid, k);
			if (numb > k) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
        return low;
    }
};