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
        ListNode *temp1 = list1, *temp2 = list2, *temp = nullptr, *head;
        while(temp1 != nullptr || temp2 != nullptr){
            int v1 = 101, v2 = 101; 
            if(temp1) v1 = temp1->val;
            if(temp2) v2 = temp2->val;
            if(v1 > v2){
                if(temp) temp->next = temp2;
                if(!temp) head = temp2;
                temp = temp2;
                if(temp2) temp2 = temp2->next;
            }else{
                if(temp) temp->next = temp1;
                if(!temp) head = temp1;
                temp = temp1;
                if(temp1) temp1 = temp1->next;
            }
        }
        return head;
    }
};