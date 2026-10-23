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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1); 
        ListNode *temp1 = list1, *temp2 = list2, *temp = dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            int v1,v2; 
            v1 = temp1->val;
            v2 = temp2->val;
            if(v1 > v2){
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }else{
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
        }
        if(temp1) temp->next = temp1;
        if(temp2) temp->next = temp2;
        return dummy->next;
    }
};