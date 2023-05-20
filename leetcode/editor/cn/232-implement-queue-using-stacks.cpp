/**
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）： 

 实现 MyQueue 类： 

 
 void push(int x) 将元素 x 推到队列的末尾 
 int pop() 从队列的开头移除并返回元素 
 int peek() 返回队列开头的元素 
 boolean empty() 如果队列为空，返回 true ；否则，返回 false 
 

 说明： 

 
 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
 
 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。 
 

 

 示例 1： 

 
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

 
 

 

 提示： 

 
 1 <= x <= 9 
 最多调用 100 次 push、pop、peek 和 empty 
 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作） 
 

 

 进阶： 

 
 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。 
 

 Related Topics 栈 设计 队列 👍 914 👎 0

*/
#include<bits/stdc++.h>

using namespace std;

/*struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};*/
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;
    MyQueue() {


    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();//函数的复用
        stackOut.push(result);
        return result;
    }
    
    bool empty() {
        //return stackIn.empty() && stackOut.empty() ? true : false; //可以被简化为下面的
        return stackIn.empty() && stackOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<int> a /*initilization*/;
//    auto x = s. /*function_name*/;
//    cout << x << endl;
    /*    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(6);
    test->next->next->next = new ListNode(3);
    test->next->next->next->next = new ListNode(4);
    test->next->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next->next = new ListNode(6);*/
//    ListNode* head = generateRandomLinkedList(MaxSize, MaxValue);
//    auto x = s. /*function_name*/;
    
    
    
    return 0;
}

/*void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}*/