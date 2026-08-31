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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *temp = head->next, *prev = head, *nex;
        vector<int> v;
        int flag = 0, cnt = 1;
        while(temp->next != nullptr){
            nex = temp->next;
            cnt++;
            if(temp->val < prev->val && temp->val < nex->val){
                v.push_back(cnt);
                flag = 1;
            }else if(temp->val > prev->val && temp->val > nex->val){
                v.push_back(cnt);
                flag = 1;
            }
            prev = temp;
            temp = nex;
        }
        vector<int> ans;
        if(flag == 0 || v.size() < 2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int _max = v.back()-v[0];
        int _min = INT_MAX;
        for(int i = 1; i < v.size(); i++){
            int diff = v[i]-v[i-1];
            _min = min(_min, diff);
        }
        ans.push_back(_min);
        ans.push_back(_max);
        return ans;

    }
};