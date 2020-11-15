# 剑指offer05.空格替换

## 题目描述

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof

## 解题思路1

- 遍历字符串计算空格的个数
- 利用resize函数开辟足够的空间
- 双指针，j从新的size()开始，i从字符串的末尾开始
- 碰到空格，往j的位置依次填入%20，不是空格，则将i位置的字符填到j位置

![05替换空格——剑指offer](img/05替换空格——剑指offer.png)

## 代码实现

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int count=0;
        int len=s.size();
        //计算空格的个数
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
                count++;
            }
        }
        //修改s的大小
        s.resize(s.size()+2*count);
        //for循环遍历字符串 i从字符串的末尾开始遍历，j从新的size开始遍历
        for(int i=len-1,j=s.size()-1;i<j;--i,--j)
        {
            //如果是空格则填入%20
            if(s[i]==' ')
            {
                j-=2;
                s[j]='%';
                s[j+1]='2';
                s[j+2]='0';
                
            }
            //如果不是空格填入字符
            else 
            {
                s[j]=s[i];
            }
        }
        return s;
    }
};
```

## 解题思路2

- 创建一个新的空字符串s1
- 循环遍历字符串s
- 如果是空格，依次s1.push_back() "%20"
- 如果不是空格，依次s1.push_back() s[i]
- 返回新的字符串s1

## 代码实现

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        //创建一个空的string s1
        string s1;
        //便利字符串s
        for(int i=0;i<s.size();++i)
        {
            //如果是空格，依次push_back"%20"
            if(s[i]==' ')
            {
                s1.push_back('%');
                s1.push_back('2');
                s1.push_back('0');
            }
            //如果不是空格，push_back字符
            else
            {
                char ch=s[i];
                s1.push_back(ch);
            }
        }
        return s1;
    }
};
```

