/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* next_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_node;
        }
        return prev;
    }
};