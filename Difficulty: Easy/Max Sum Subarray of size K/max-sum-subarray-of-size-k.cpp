class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int l = 0;
        int r = k - 1;
        int n = arr.size();
        int sum = 0;
        
        for(int i = 0; i < k; i++){
            sum = sum + arr[i];
        }
        
        int max_sum = sum;
        
        while(r < n-1){
             
             sum = sum - arr[l];
             l++;
             r++;
             sum = sum + arr[r];
             
             max_sum = max(sum,max_sum);
        }
        
        return max_sum;
        
    }
};