#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr; // Base case: empty list
        }

        head->next = removeElements(head->next, val);

        return head->val == val ? head->next : head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;

    Solution solution;
    ListNode* newHead = solution.removeElements(head, val);

    cout << "Updated List: ";
    printList(newHead);

    // Free memory
    ListNode* temp;
    while (newHead != nullptr) {
        temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
