class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        
        int length = q.size();
        int mid = length/2;
        queue<int> p;
        
        for(int i = 0; i < mid; i++){
            int temp = q.front();
            q.pop();
            p.push(temp);
        }
        
        while(!p.empty()){
            
            int temp1 = p.front();
            p.pop();
            q.push(temp1);
            
            int temp2 = q.front();
            q.pop();
            q.push(temp2);
        }
        
    }
};