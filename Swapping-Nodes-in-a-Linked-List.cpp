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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1,*p2,*temp;
        temp=head;
        p1=head;
        p2=head;
        int count=0;
        for(int i=1;i<k;i++){
            p1=p1->next;
        }
        while(temp){
            count++;
            temp=temp->next;
        }
        for(int i=0;i<count-k;i++){
            p2=p2->next;
        }
        swap(p1->val, p2->val);

        return head; 
    }
    
};