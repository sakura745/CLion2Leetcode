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
${question.code}

int main()
{
    Solution s;
    vector<int> a /*initilization*/;
    auto x = s. /*function_name*/;
    cout << x << endl;
    return 0;
}
```