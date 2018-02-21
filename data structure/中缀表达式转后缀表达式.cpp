

1)	中缀表达式转后缀表达式  O(n)
  a)	建立一个用于存运算符的栈,逐一扫描该中缀表达式中的元素
      i)	如果遇到一个数,则输出该数
      ii)	如果遇到左括号,把左括号入栈
      iii)	如果遇到右括号,不断取出栈顶并输出,直到栈顶为左括号,然后把左括号出栈
      iv)	如果遇到运算符,只要栈顶符号的优先级不低于新符号,就不断取出栈顶并输出,最后把新符号入栈 (优先级 : 乘除>加减>左括号)
  b)	依次取出并输出栈中的所有剩余符号,最终输出的序列就是一个与原中缀表达式等价的后缀表达式
  c)	如果式中数字为多位数,并且表达式是使用字符串逐字符存储的,我们只需要稍加判断,把连续的一段数字看成一个数即可


// 数值栈
vector<int> nums;
// 运算符栈
vector<char> ops;

// 优先级
int grade(char op) {
    switch (op) {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
    }
    return 0;
}

// 处理后缀表达式中的一个运算符
void calc(char op) {
    // 从栈顶取出两个数
    int y = *nums.rbegin();
    nums.pop_back();
    int x = *nums.rbegin();
    nums.pop_back();
    int z;
    switch (op) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
    }
    // 把运算结果放回栈中
    nums.push_back(z);
}

// 中缀表达式转后缀表达式，同时对后缀表达式求值
int solve(string s) {
    nums.clear();
    ops.clear();
    int top = 0, val = 0;
    for (int i = 0; i < s.size(); i++) {
        // 中缀表达式的一个数字
        if (s[i] >= '0' && s[i] <= '9') {
            val = val * 10 + s[i] - '0';
            if (s[i+1] >= '0' && s[i+1] <= '9') continue;
            // 后缀表达式的一个数，直接入栈
            nums.push_back(val);
            val = 0;
        }
            // 中缀表达式的左括号
        else if (s[i] == '(') ops.push_back(s[i]);
            // 中缀表达式的右括号
        else if (s[i] == ')') {
            while (*ops.rbegin() != '(') {
                // 处理后缀表达式的一个运算符
                calc(*ops.rbegin());
                ops.pop_back();
            }
            ops.pop_back();
        }
            // 中缀表达式的加减乘除号
        else {
            while (ops.size() && grade(*ops.rbegin()) >= grade(s[i])) {
                calc(*ops.rbegin());
                ops.pop_back();
            }
            ops.push_back(s[i]);
        }
    }
    while (ops.size()) {
        calc(*ops.rbegin());
        ops.pop_back();
    }
    // 后缀表达式栈中最后剩下的数就是答案
    return *nums.begin();
}
int main()
{
    string s;
    cin>>s;
    we(solve(s));

}
