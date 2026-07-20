
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        for(int x : arr){
            if(mp[x] == 1){
                return x;
            }
            
        }
        return 0;
    }
};
