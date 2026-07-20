class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
            if(arr[i]< mini){
                mini = arr[i];
            }
        }
        return {mini,maxi};
        
    }
};