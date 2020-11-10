#pragma once
#include<assert.h>

namespace bin
{
	//����ڵ�list_node
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		//���캯��
		list_node(const T& data=T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{

		}
	};

	//������list_iterator
	//Ref���á�Ptrָ��
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_iterator<T, Ref, Ptr> my_iterator;
		typedef list_node<T> Node;
		Node* _node;
		//��������ĺ��Ļ��ǽڵ��ָ��

		//���캯��
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

	//����list
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

		//���캯������ͷ˫��ѭ������
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//�������캯��
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

		//operator=��ֵ���������
		//lt1=lt3 
		//list<T>& operator=(const list<T>& lt)
		//{
		//	//�Լ������Ը��Լ���ֵ
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

		//��������
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//clear()ɾ��list������Ԫ��
		void clear()
		{
			//������ָ������ͷ
			iterator it = begin();
			//��������
			while (it != end())
			{
				//����ɾ��������ָ���Ԫ��
				erase(it++);
			}
		}

		//push_back
		void push_back(const T& data) 
		{
			//�ҵ������β���
			Node* tail = _head->_prev;
			//�����µĽڵ�
			Node* newnode = new Node(data);

			//����β�ĺ�ָ��ָ���½��
			tail->_next = newnode;
			//�½���ǰָ��ָ������β���
			newnode->_prev = tail;
			//�½��ĺ�ָ��ָ�������ͷ���
			newnode->_next = _head;
			//ͷ����ǰָ��ָ���½��
			_head->_prev = newnode;
		}

		//pop_back() βɾ
		void pop_back()
		{
			erase(--end());
		}

		//push_front() ͷ��
		void push_front(const T& data)
		{
			insert(begin(),data);
		}

		//pop_front() ͷɾ
		void pop_front()
		{
			erase(begin());
		}

		//insert()����
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

		//erase() ɾ��
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
