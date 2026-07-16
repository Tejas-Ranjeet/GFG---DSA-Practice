/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  
    Node* reversal(Node* head){
        Node *prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        
        head = reversal(head);
        
        //logic of addition of 1
        
        int carry = 1;
        Node *temp = head;
        while(temp != NULL){
            
            int num = temp-> data;
            int sum = num + carry;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            
            temp->data = digit;
            
            if(temp->next == NULL && carry != 0){
                
                Node* newNode = new Node(carry);
                temp->next = newNode;
                temp = newNode;
                
            }
            //move to the next node otherwise the loop wil be stuck
            temp = temp -> next;
            
        }
        head = reversal(head);
        
        return head;
        
    }
};