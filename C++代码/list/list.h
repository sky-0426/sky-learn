#pragma once
#include<assert.h>

namespace bin
{
	//链表节点list_node
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		//构造函数
		list_node(const T& data=T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{

		}
	};

	//迭代器list_iterator
	//Ref引用、Ptr指针
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_iterator<T, Ref, Ptr> my_iterator;
		typedef list_node<T> Node;
		Node* _node;
		//链表迭代的核心还是节点的指针

		//构造函数
		list_iterator(Node* node=nullptr)
			:_node(node)
		{

		}

		//*
		Ref operator*()
		{
			return _node->_data;
		}

		//->
		Ptr operator->()
		{
			return &_node->_data;
		}

		//++it
		my_iterator operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//it++
		my_iterator operator++(int)
		{
			list_iterator<T, Ref, Ptr> tmp(*this);
			//_node = _node->_next;
			++(*this);
			return tmp;
		}
		
		//--it
		my_iterator operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//it--
		my_iterator operator--(int)
		{
			list_iterator<T, Ref, Ptr> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		//!=
		bool operator!=(const my_iterator& it)
		{
			return _node != it._node;
		}

		//==
		bool operator==(const my_iterator& it)
		{
			return _node == it._node;
		}

	};

	//链表list
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
	
		//begin()
		iterator begin() 
		{
			return iterator(_head->_next);
		}

		//end()
		iterator end()  
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		//构造函数，带头双向循环链表
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//拷贝构造函数
		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		//operator=赋值运算符重载
		//lt1=lt3 
		//list<T>& operator=(const list<T>& lt)
		//{
		//	//自己不可以给自己赋值
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}
		list<T>& operator=(const list<T>& lt)
		{
			swap(_head, lt._head);
			return *this;
		}

		//析构函数
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//clear()删除list中所有元素
		void clear()
		{
			//迭代器指向链表头
			iterator it = begin();
			//遍历链表
			while (it != end())
			{
				//依次删除迭代器指向的元素
				erase(it++);
			}
		}

		//push_back
		void push_back(const T& data) 
		{
			//找到链表的尾结点
			Node* tail = _head->_prev;
			//创建新的节点
			Node* newnode = new Node(data);

			//链表尾的后指针指向新结点
			tail->_next = newnode;
			//新结点的前指针指向链表尾结点
			newnode->_prev = tail;
			//新结点的后指针指向链表的头结点
			newnode->_next = _head;
			//头结点的前指针指向新结点
			_head->_prev = newnode;
		}

		//pop_back() 尾删
		void pop_back()
		{
			erase(--end());
		}

		//push_front() 头插
		void push_front(const T& data)
		{
			insert(begin(),data);
		}

		//pop_front() 头删
		void pop_front()
		{
			erase(begin());
		}

		//insert()插入
		void insert(iterator pos, const T& data)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(data);

			//prev newnode cur

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

		}

		//erase() 删除
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* del = pos._node;
			Node* prev = del->_prev;
			Node* next = del->_next;

			prev->_next = next;
			next->_prev = prev;
			delete del;

			return iterator(next);
		}
	private:
		Node* _head;
	};
}
