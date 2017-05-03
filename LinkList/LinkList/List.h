#ifndef __CList__H__
#define __CList__H__

/************************************************************************/
/* 单链表（含头结点）定义及实现                                         */
/* 注:当模板中传入的是结构体或类类型，必须有默认构造函数，必须重载!=    */
/*                                                                      */
/* 1. Append方法在链表尾部插入元素                                      */
/* 2. Insert方法在链表指定位置处插入元素，当链表为空，插入的元素为      */
/*    第一个；当插入的索引为最后一个元素的下一个时，插入元素在末尾      */
/* 3. Remove方法将给定元素从链表中删除，对重复元素均删除                */
/* 4. RemoveAt方法将给定索引的元素删除                                  */
/* 5. Empty方法清空链表，但不会清除头结点                               */
/* 6. 已重载方框号[]运算符进行下标索引，支持作为左值或右值              */
/* 7. GetLength求链表长度，不包含头结点                                 */
/* 8. IsEmpty方法判断链表是否为空，不包含头结点                         */
/************************************************************************/

#define NULL  0

template<class T>
class CList
{
public:
	CList();
	~CList();
public:
	void Append(T data);
	void Insert(T data, unsigned int index);
	void Remove(T data);
	void RemoveAt(unsigned int index);
	void Empty();
	T& operator [](unsigned int index);
public:
	unsigned int GetLength();
	bool IsEmpty();
private:
	struct node
	{
		T data;
		node *next;
		node() : next(NULL) {}
		node(T _data) : data(_data), next(NULL) {}
	};
private:
	void LocateEnd(node*& pnode, unsigned int *index);
	void Locate(unsigned int index, node*& pnode);
	void Locate(T data, node*& pnode);
	node * m_head;
};

template<class T>
CList<T>::CList()
{
	m_head = new node;
}

template<class T>
CList<T>::~CList()
{
	Empty();
	delete m_head;
}

template<class T>
void CList<T>::Append(T data)
{
	node *p = m_head;
	unsigned int _pos = 0;
	LocateEnd(p, &_pos);
	node *temp = new node(data);
	p->next = temp;
}

template<class T>
void CList<T>::Insert(T data, unsigned int index)
{
	if (IsEmpty()) {Append(data); return;}
	if (index < 0 || index > GetLength()) throw 0;


	node *p = m_head;
	Locate(index, p);
	node *temp = new node(data);
	temp->next = p->next;
	p->next = temp;
}

template<class T>
void CList<T>::Remove(T data)
{
	if (IsEmpty()) return;

	node *p = m_head;
	while (p && p->next)
	{
		Locate(data, p);
		if (p->next)
		{
			node *temp = p->next;
			p->next = temp->next;
			delete temp;
			temp = NULL;
			p = p->next;
		}
	}
}

template<class T>
void CList<T>::RemoveAt(unsigned int index)
{
	if (IsEmpty()) return;
	if (index < 0 || index > GetLength()) throw 0;

	node *p = m_head;
	Locate(index, p);
	node * temp = p->next;
	p->next = temp->next;
	delete temp;
	temp = NULL;
}

template<class T>
T& CList<T>::operator [](unsigned int index)
{
	if (IsEmpty() ||index < 0 || index >= GetLength()) throw 0;

	node *p = m_head->next;
	Locate(index, p);
	return p->data;
}

template<class T>
void CList<T>::Empty()
{
	node *p = m_head->next;
	while (m_head->next)
	{
		m_head->next = p->next;
		delete p;
		p = m_head->next;
	}
}

template<class T>
bool CList<T>::IsEmpty()
{
	return m_head->next ? false : true;
}

template<class T>
unsigned int CList<T>::GetLength()
{
	if (IsEmpty()) return 0;

	unsigned int _pos = 0;
	node *p = m_head;
	LocateEnd(p, &_pos);
	return _pos;
}

template<class T>
void CList<T>::LocateEnd(node*& pnode, unsigned int *index)
{
	unsigned int _pos = 0;
	while (pnode && pnode->next)
	{
		pnode = pnode->next;
		++_pos;
	}
	*index = _pos;
}

template<class T>
void CList<T>::Locate(unsigned int index, node*& pnode)
{
	unsigned int _pos = 0;
	while (pnode && pnode->next && _pos != index)
	{
		pnode = pnode->next;
		++_pos;
	}
}

template<class T>
void CList<T>::Locate(T data, node*& pnode)
{
	while (pnode && pnode->next && pnode->next->data != data)
		pnode = pnode->next;
}

#endif //__CList__H__