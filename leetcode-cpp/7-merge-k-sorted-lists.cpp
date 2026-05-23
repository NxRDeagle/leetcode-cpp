#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;

        std::vector<std::pair<int, ListNode*>> arr;

        for (int i = 0; i < k; i++)
        {
            ListNode* curr_list = lists[i];

            while (curr_list != NULL)
            {
                arr.push_back({ curr_list->val, curr_list });
                curr_list = curr_list->next;
            }
        }

        if (arr.size() == 0)
            return NULL;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; i++)
            arr[i].second->next = arr[i + 1].second;

        arr[arr.size() - 1].second->next = NULL;

        return arr[0].second;
    }
};

#ifdef ACTIVE_MAIN
int main()
{
    Solution sl;

    std::vector<ListNode*> lists;
    ListNode* list1_3 = new ListNode(5);
    ListNode* list1_2 = new ListNode(4, list1_3);
    ListNode* list1_1 = new ListNode(1, list1_2);

    ListNode* list2_3 = new ListNode(4);
    ListNode* list2_2 = new ListNode(3, list2_3);
    ListNode* list2_1 = new ListNode(1, list2_2);

    ListNode* list3_2 = new ListNode(6, list2_3);
    ListNode* list3_1 = new ListNode(2, list3_2);

    lists = { list1_1, list2_1, list3_1 };

    sl.mergeKLists(lists);


    return 0;
}
#endif

//You are given an array of k linked - lists, each linked - list is sorted in ascending order.
//
//Merge all the linked - lists into one sorted linked - list and return it.
// 
//Example 1:
//
//Input: lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
//Output : [1, 1, 2, 3, 4, 4, 5, 6]
//Explanation : The linked - lists are :
//[
//    1->4->5,
//    1->3->4,
//    2->6
//]
//merging them into one sorted linked list :
//1->1->2->3->4->4->5->6
// 
//Example 2 :
//
//    Input : lists = []
//    Output : []
// 
//Example 3 :
//
//    Input : lists = [[]]
//    Output : []
//
//    Constraints :
//
//    k == lists.length
//    0 <= k <= 10^4
//    0 <= lists[i].length <= 500
//    - 10^4 <= lists[i][j] <= 10^4
//    lists[i] is sorted in ascending order.
//    The sum of lists[i].length will not exceed 10^4.