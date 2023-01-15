// Given the head of a linked list, remove the nth node from the end of the list and return its head.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size = 0, ptr = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            ++list_size;
            curr = curr->next;
        }
        if(list_size <= 1) {
            return nullptr;
        }

        curr = head;
        int index = list_size - n;
        if(index == 0) {
            auto tmp = curr->next;
            delete curr;
            return tmp;
        }
        
        while(ptr != index) {
            ++ptr;
            if(ptr == index) {
                prev = curr;
            }
            curr = curr->next;
        }
        if(!prev->next->next) {
            prev->next = nullptr;
        } else {
            prev->next = prev->next->next;
        }
        return head;
    }
};