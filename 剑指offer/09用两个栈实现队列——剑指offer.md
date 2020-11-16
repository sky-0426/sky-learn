# 剑指offer09.用两个栈实现队列

## 题目描述

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

[https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&&tqId=11158&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking](用两个栈实现队列)

## 解题思路

![剑指offer——用两个栈实现队列](img/剑指offer——用两个栈实现队列.jpg)

- 维护两个栈stack1和stack2，栈stack1用来实现入队操作push，栈stack2用来实现出队操作pop
- 入队时，直接将元素压入栈stack1
- 出队时，判断栈stack2是否为空，
  - 若不为空，则将栈stack2的栈顶元素出栈；
  - 若为空，则将栈stack1中的元素依次出栈压入栈Stack2中，直到栈stack1为空，再将栈stack2的栈顶元素出栈；

## 代码实现

```C++
class Solution
{
public:
    //入队操作
    void push(int node) {
        //直接压入stack1
        stack1.push(node);
    }
	//出队操作
    int pop() {
        //判断stack2是否为空
        if(stack2.empty())
        {
            //若stack2为空
            while(!stack1.empty())
            {
                //将stack1中的元素依次压入stack2
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret=stack2.top();
        //stack2执行出栈操作
        stack2.pop();
        //返回栈顶元素
        return ret;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
```



