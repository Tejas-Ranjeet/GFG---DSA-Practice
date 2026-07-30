/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        vector<int> ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        
        if(root == NULL){
            return ans;
        }
        
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            
            mp[line] = node->data;
            
            if(node->left != NULL){
                q.push({node->left,line-1});
            }
            if(node->right != NULL){
                q.push({node->right,line+1});
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
        