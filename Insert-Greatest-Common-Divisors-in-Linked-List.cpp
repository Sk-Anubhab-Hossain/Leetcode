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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head->next;
        while(temp1){
            int gcd=1;
            for(int i=1;i<=min(temp->val, temp1->val);i++){
                if(temp->val%i==0 && temp1->val%i==0){
                    gcd=max(gcd,i);
                }
            }
            ListNode* newnode=new ListNode(gcd);
            temp->next=newnode;
            newnode->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        return head;
    }
};