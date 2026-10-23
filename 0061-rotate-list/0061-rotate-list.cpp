/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        int len = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        k = k%len;
        if(k%len == 0) return head;
        int front = len-k;
        temp = head;
        for(int i = 1; i < front; i++){
            temp = temp->next;
        }
        ListNode *newhead = temp->next;
        temp->next = nullptr;
        temp = newhead;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = head;
        return newhead;
    }
};