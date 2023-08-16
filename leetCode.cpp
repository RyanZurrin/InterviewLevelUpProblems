//
// Created by Ryan.Zurrin001 on 1/6/2022.
//
#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "misc-no-recursion"

#include "Solutions.h"
#include "Utils.h"
typedef Solutions S;


int main()
{
    /** Test this function
     *     /**
     * 86. Partition List
     * Given the head of a linked list and a value x, partition it such that
     * all nodes less than x come before nodes greater than or equal to x.
     * You should preserve the original relative order of the nodes in each
     * of the two partitions.
     *
     * Example 1:
     * Input: head = [1,4,3,2,5,2], x = 3
     * Output: [1,2,2,4,3,5]
     *
     * Example 2:
     * Input: head = [2,1], x = 2
     * Output: [1,2]
     *
     * Constraints:
     * The number of nodes in the list is in the range [0, 200].
     * -100 <= Node.val <= 100
     * -200 <= x <= 200
     */
    ListNode* head = new ListNode(1);
    ListNode* head2 = new ListNode(4);
    ListNode* head3 = new ListNode(3);
    ListNode* head4 = new ListNode(2);
    ListNode* head5 = new ListNode(5);
    ListNode* head6 = new ListNode(2);
    head->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = head6;
    ListNode* ans = S::partition(head, 3);
    while (ans != nullptr)
    {
        std::cout << ans->val << " ";
        ans = ans->next;
    }
    std::cout << std::endl;




    return 0;
}
