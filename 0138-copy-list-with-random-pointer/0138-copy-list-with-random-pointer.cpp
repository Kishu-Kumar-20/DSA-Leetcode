/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp1 = head;
        unordered_map<Node*, Node*> mpp;
        while(temp1 != nullptr){
            Node *newnode = new Node(temp1->val);
            mpp[temp1] = newnode;
            temp1 = temp1->next;
        }
        temp1 = head;
        while(temp1 != nullptr){
            Node *copied = mpp[temp1];
            copied->next = mpp[temp1->next];
            copied->random = mpp[temp1->random];
            temp1 = temp1->next;
        }
        return mpp[head];
    }
};