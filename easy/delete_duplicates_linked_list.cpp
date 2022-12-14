struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* curr = head;
        ListNode* aux;
        while(curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                aux = curr->next->next;
                delete curr->next;
                curr->next = aux;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};