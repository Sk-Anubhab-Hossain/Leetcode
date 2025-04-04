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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* temp=head;
        ListNode* temp1=head->next;
        ListNode*prev=nullptr; //handles previous unique nodes

        while(temp1){
            bool isduplicate=false;

            while(temp1 && temp->val==temp1->val){
                isduplicate=true;
                temp1=temp1->next;
            }

            if(isduplicate){
                if(prev){
                    prev->next=temp1;
                }
                else{
                    head=temp1;
                }
            }
            else{
                prev=temp;
            }

            temp=temp1;;
            if(temp1){
                temp1=temp1->next;
            }
        } 
        return head;
    }
};