#ifndef __CList__H__
#define __CList__H__

/************************************************************************/
/* ��������ͷ��㣩���弰ʵ��                                         */
/* ע:��ģ���д�����ǽṹ��������ͣ�������Ĭ�Ϲ��캯������������!=    */
/*                                                                      */
/* 1. Append����������β������Ԫ��                                      */
/* 2. Insert����������ָ��λ�ô�����Ԫ�أ�������Ϊ�գ������Ԫ��Ϊ      */
/*    ��һ���������������Ϊ���һ��Ԫ�ص���һ��ʱ������Ԫ����ĩβ      */
/* 3. Remove����������Ԫ�ش�������ɾ�������ظ�Ԫ�ؾ�ɾ��                */
/* 4. RemoveAt����������������Ԫ��ɾ��                                  */
/* 5. Empty��������������������ͷ���                               */
/* 6. �����ط����[]����������±�������֧����Ϊ��ֵ����ֵ              */
/* 7. GetLength�������ȣ�������ͷ���                                 */
/* 8. IsEmpty�����ж������Ƿ�Ϊ�գ�������ͷ���                         */
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