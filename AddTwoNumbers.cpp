#include <iostream>
//Run the code in any C++ IDE and input your test case manually in the console. Online IDE: https://www.onlinegdb.com/online_c++_compiler#
//Leetcode link: https://leetcode.com/problems/add-two-numbers/description/

//ListNode struct
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
//converts int number arg to single LinkedList
ListNode* numList(int num){
    ListNode* result = new ListNode();
    ListNode* head = result;
    while(num > 0){
        head->val = num % 10;
        num /= 10;
        ListNode* nextDigit = new ListNode();
        head->next = nextDigit;
        head = head->next;
    }
    return result;
}

//converts LinkedList arg to int number
int getNum(ListNode* lnode){
        int multipleOfTen = 1;
        int num = 0;
        ListNode* current = lnode;
        while(current != NULL){
            num += (current->val * multipleOfTen);
            multipleOfTen *= 10;
            current = current->next;
        }
        return num;
}

//returns sum of 2 int numbers represented as LinkedList
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sumOfTwoNum = getNum(l1)+getNum(l2);
        return numList(sumOfTwoNum);
}

//prints elements in LinkedList
void printList(ListNode* list){
    ListNode* head = list;
    while(head->next != NULL){
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

//takes 2 int numbers as user input, returns sum of two numbers in LinkedList format
int main()
{
    int num1;
    int num2;
    std::cout << "Enter num 1" << std::endl;
    std::cin >> num1;
    std::cout << "Enter num 2" << std::endl;
    std::cin >> num2;
    ListNode* result1 = numList(num1);
    ListNode* result2 = numList(num2);
    ListNode* addedResult = addTwoNumbers(result1, result2);
    printList(result1);
    printList(result2);
    printList(addedResult);
}
