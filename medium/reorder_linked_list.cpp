/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/

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
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return;
        std::deque<ListNode*> lists;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            lists.push_back(ptr);
            ptr = ptr->next;
        }
        
        ListNode *first = lists.front();
        lists.pop_front();
        ListNode *last = lists.back();
        lists.pop_back();
        first->next = last;
        
        while(lists.size() > 1) {
            first = lists.front();
            lists.pop_front();
            last->next = first;
            last = lists.back();
            lists.pop_back();
            first->next = last;
        }

        if(!lists.empty()) {
            last->next = lists.back();
            last = lists.back();
            last->next = nullptr;
        } else {
            last->next = nullptr;
        }

    }
};