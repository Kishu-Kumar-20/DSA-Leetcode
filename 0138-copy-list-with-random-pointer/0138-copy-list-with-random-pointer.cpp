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
        if(head == nullptr) return nullptr;
        Node *temp = head;
        while(temp != nullptr){
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while(temp != nullptr){
            if(temp->random) temp->next->random = temp->random->next;
            else temp->next->random = nullptr;
            temp = temp->next->next;
        }
        temp = head;
        Node *newhead = temp->next;
        while(temp != nullptr){
            Node* dummy = temp->next;
            temp->next = dummy->next;
            temp = temp->next;
            if(temp) dummy->next = temp->next;
        }
        return newhead;
    }
};