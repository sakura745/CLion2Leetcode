### CLion上用LeetCode Editer插件刷题，方便本地调试，记录代码

安装流程，插件网上都有。


对`CMakeLists`文件来说，修改文件参数是必要的。

附上插件的关键设置参数

在`Settings`-->`Tools`-->`LeetCode plugin`中

修改`Code FileName`，配合插件`c/c++ single File Execution`，便于生成可执行程序

```
$!{question.frontendQuestionId}-${question.titleSlug}
```

修改`Code Template`便于本地调试，部分细节需要按照题意修改
```
${question.content}
\#include<bits/stdc++.h>

using namespace std;

/*struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};*/
void printLinkedList(ListNode* head);
${question.code}

int main()
{
    Solution s;
//    vector<int> a /*initilization*/;
//    auto x = s. /*function_name*/;
//    cout << x << endl;
    /*    ListNode* test = new ListNode(1);//自定义链表
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

void printLinkedList(ListNode* head) {//输出链表
    if(head == nullptr) return;
    while(head->next != nullptr){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;
}
```