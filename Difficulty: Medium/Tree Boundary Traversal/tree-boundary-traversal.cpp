/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    void leftboundary(Node *root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left!= NULL){
            leftboundary(root->left,ans);
        }
        else{
            leftboundary(root->right,ans);
        }
        
    }
    
    void leafnode(Node *root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        leafnode(root->left,ans);
        leafnode(root->right,ans);
        
    }
    
    void rightboundary(Node *root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(root->right != NULL){
            rightboundary(root->right,ans);
        }
        else{
            rightboundary(root->left,ans);
        }
        
        ans.push_back(root->data);
        
    }
    
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int>ans;
        //root
        if(root == NULL){
            return ans;
        }
        else{
            ans.push_back(root->data);
        }
        //left boundary
        leftboundary(root->left,ans);
        //left leaf node
        leafnode(root->left,ans);
        //right leaf node
        leafnode(root->right,ans);
        //revrse right boundary
        rightboundary(root->right,ans);
        
        return ans;
    }
};