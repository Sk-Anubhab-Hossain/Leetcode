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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        int count=0;
        ListNode* temp,* temp1, *temp2;
        temp=head;
        temp1=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int pos=count-n;
        if(pos==0){
            ListNode* newHead= head->next;
            delete head;
            return newHead;
        }
        for(int i=0;i<pos-1;i++){
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        return head;
    }
    
};