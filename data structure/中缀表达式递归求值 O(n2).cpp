


  中缀表达式递归求值 O(n2)
  a)	目标:求解中缀表达式S[1~n]的值
  b)	子问题:求解中缀表达式S的子区间表达式S[ L , R ]
      i)	在L~R中考虑没有被任何括号包含的运算符
        (1)	若存在加减号,选其中最后一个,分成左右两半递归,结果相加减,返回
        (2)	若存在乘除号,选其中最后一个,分成左右两边递归,结果相乘除,返回
     ii)	若不存在没有被任何括号包含的运算符
        (1)	若首位字符是括号,递归求解S[ L+1 , R-1 ],把结果返回
        (2)	否则,说明区间S[ L ~ R ]是一个数,直接返回数值
  c)	代码
      string s;
    // 递归法求中缀表达式的值，O(n^2)
    int calc(int l, int r) {
        // 寻找未被任何括号包含的最后一个加减号
        for (int i = r, j = 0; i >= l; i--) {
            if (s[i] == '(') j++;
            if (s[i] == ')') j--;
            if (j == 0 && s[i] == '+') return calc(l, i - 1) + calc(i + 1, r);
            if (j == 0 && s[i] == '-') return calc(l, i - 1) - calc(i + 1, r);
        }
        // 寻找未被任何括号包含的最后一个乘除号
        for (int i = r, j = 0; i >= l; i--) {
            if (s[i] == '(') j++;
            if (s[i] == ')') j--;
            if (j == 0 && s[i] == '*') return calc(l, i - 1) * calc(i + 1, r);
            if (j == 0 && s[i] == '/') return calc(l, i - 1) / calc(i + 1, r);
        }
        // 首尾是括号
        if (s[l] == '('&&s[r] == ')') return calc(l + 1, r - 1);
        // 是一个数
        int ans = 0;
        for (int i = l; i <= r; i++) ans = ans * 10 + s[i] - '0';
        return ans;
    }
