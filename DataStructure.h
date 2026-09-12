#ifndef DATASTRUCTURE
#define DATASTRUCTURE
#include <iostream>
#include <algorithm>
template <typename T>
class LinearList
{
public:
    LinearList() = default;
    virtual ~LinearList() = default;
    virtual int Size() const = 0;
    virtual int Length() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual int Search(const T &x) const = 0;
    virtual int Locate(int i) const = 0;
    virtual T *getData(int i) const = 0;
    virtual void setData(int i, const T &x) = 0;
    virtual bool Insert(int i, const T &x) = 0;
    virtual bool Remove(int i, T &x) = 0;
    virtual void Sort() = 0;
    virtual void Input() = 0;
    virtual void Output() = 0;
};
template <typename T>
class SeqList : public LinearList<T>
{
private:
    T *data;
    int maxSize;
    int last;

public:
    SeqList(int size = 64);
    SeqList(const SeqList<T> &L);
    ~SeqList();

    int Size() const override;
    int Length() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    int Search(const T &x) const override;
    int Locate(int i) const override;
    T *getData(int i) const override;
    void setData(int i, const T &x) override;
    bool Insert(int i, const T &x) override;
    bool Remove(int i, T &x) override;
    void Sort() override;
    void Input() override;
    void Output() override;

    void reSize(int newSize);
    SeqList<T> &operator=(const SeqList<T> &L);
};
template <typename T>
class SinglyLinkedList : public LinearList<T>
{
private:
    typedef struct Node
    {
        T data;
        Node *next;
    } Node;
    Node *head;

public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T> &L);
    ~SinglyLinkedList();

    int Size() const override;
    int Length() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    int Search(const T &x) const override;
    int Locate(int i) const override;
    T *getData(int i) const override;
    void setData(int i, const T &x) override;
    bool Insert(int i, const T &x) override;
    bool Remove(int i, T &x) override;
    void Sort() override;
    void Input() override;
    void Output() override;

    void pushFront(const T &x);
    void pushBack(const T &x);
    void removeFront();
    void removeBack();
    SinglyLinkedList<T> &operator=(const SinglyLinkedList<T> &L);
};
template <typename T>
class CircularLinkedList : public LinearList<T>
{
private:
    typedef struct Node
    {
        T data;
        Node *next;
    } Node;
    Node *head, *tail;

public:
    CircularLinkedList();
    CircularLinkedList(const CircularLinkedList<T> &L);
    ~CircularLinkedList();

    int Size() const override;
    int Length() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    int Search(const T &x) const override;
    int Locate(int i) const override;
    T *getData(int i) const override;
    void setData(int i, const T &x) override;
    bool Insert(int i, const T &x) override;
    bool Remove(int i, T &x) override;
    void Sort() override;
    void Input() override;
    void Output() override;

    void pushFront(const T &x);
    void pushBack(const T &x);
    void removeFront();
    void removeBack();
    bool isCircular() const;
    CircularLinkedList<T> &operator=(const CircularLinkedList<T> &L);
};
template <typename T>
class DoublyLinkedList : public LinearList<T>
{
private:
    typedef struct Node
    {
        T data;
        Node *prev;
        Node *next;
    } Node;
    Node *head;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T> &L);
    ~DoublyLinkedList();

    int Size() const override;
    int Length() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    int Search(const T &x) const override;
    int Locate(int i) const override;
    T *getData(int i) const override;
    void setData(int i, const T &x) override;
    bool Insert(int i, const T &x) override;
    bool Remove(int i, T &x) override;
    void Sort() override;
    void Input() override;
    void Output() override;

    void pushFront(const T &x);
    void pushBack(const T &x);
    void removeFront();
    void removeBack();
    void OutputReverse();
    void reverseList();
    DoublyLinkedList<T> &operator=(const DoublyLinkedList<T> &L);
};
template <typename T>
class Stack
{
public:
    Stack() = default;
    virtual ~Stack() = default;
    virtual void Push(const T &x) = 0;
    virtual bool Pop(T &x) = 0;
    virtual bool getTop(T &x) const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual int getSize() const = 0;
};
template <typename T>
class SeqStack : public Stack<T>
{
private:
    T *elements;
    int top;
    int maxSize;
    void overflowProcess();

public:
    SeqStack(int sz = 64);
    SeqStack(const SeqStack<T> &S);
    ~SeqStack() override;
    void Push(const T &x) override;
    bool Pop(T &x) override;
    bool getTop(T &x) const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    int getSize() const override;

    void MakeEmpty();
    friend std::ostream &operator<<(std::ostream &os, SeqStack<T> &s);

    SeqStack<T> &operator=(const SeqStack<T> &S);
};

#ifdef DS_SEQLIST_IMPLEMENTATION
template <typename T>
SeqList<T>::SeqList(int size)
{
    maxSize = size;
    last = 0;
    data = new T[maxSize];
    if (data == nullptr)
    {
        std::cerr << "malloc memory failed for SeqList" << std::endl;
        exit(1);
    }
};
template <typename T>
SeqList<T>::SeqList(const SeqList<T> &L)
{
    maxSize = L.maxSize;
    last = L.last;
    data = new T[maxSize];
    if (data == nullptr)
    {
        std::cerr << "malloc memory failed for SeqList" << std::endl;
        exit(1);
    }
    for (int i = 0; i < last; i++)
    {
        data[i] = L.data[i];
    }
}
template <typename T>
SeqList<T>::~SeqList()
{
    delete[] data;
}
template <typename T>
int SeqList<T>::Size() const
{
    return maxSize;
}
template <typename T>
int SeqList<T>::Length() const
{
    return last;
}
template <typename T>
bool SeqList<T>::IsEmpty() const
{
    return last == 0;
}
template <typename T>
bool SeqList<T>::IsFull() const
{
    return last == maxSize;
}
template <typename T>
int SeqList<T>::Search(const T &x) const
{
    for (int i = 0; i < last; i++)
    {
        if (data[i] == x)
        {
            return i + 1;
        }
    }
    return 0;
}
template <typename T>
int SeqList<T>::Locate(int i) const
{
    if (i < 1 || i > last)
    {
        return 0;
    }
    return i;
}
template <typename T>
T *SeqList<T>::getData(int i) const
{
    if (i < 1 || i > last)
    {
        return nullptr;
    }
    return &data[i - 1];
}
template <typename T>
void SeqList<T>::setData(int i, const T &x)
{
    if (i < 1 || i > last)
    {
        return;
    }
    data[i - 1] = x;
}
template <typename T>
bool SeqList<T>::Insert(int i, const T &x)
{
    if (i < 1 || i > last + 1 || last == maxSize)
    {
        return false;
    }
    for (int j = last; j >= i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i - 1] = x;
    last++;
    return true;
}
template <typename T>
bool SeqList<T>::Remove(int i, T &x)
{
    T *re = this->getData(i);
    if (re == nullptr)
    {
        return false;
    }
    x = *re;
    for (int j = i - 1; j < last - 1; j++)
    {
        data[j] = data[j + 1];
    }
    last--;
    return true;
}
template <typename T>
void SeqList<T>::Sort()
{
    if (last <= 0)
    {
        return;
    }
    std::sort(data, data + last);
}
template <typename T>
void SeqList<T>::Input()
{
    std::cout << "Input the length of the list: ";
    std::cin >> last;
    while (last > maxSize)
    {
        std::cout << "The length is too long,max size is " << maxSize << ", please input again: ";
        std::cin >> last;
    }
    while (last < 0)
    {
        std::cout << "The length is negative, please input again: ";
        std::cin >> last;
    }
    for (int i = 0; i < last; i++)
    {
        std::cout << "Input the " << i + 1 << "th element: ";
        std::cin >> data[i];
    }
}
template <typename T>
void SeqList<T>::Output()
{
    std::cout << "The length of the list is: " << last << std::endl;
    for (int i = 0; i < last; i++)
    {
        std::cout << "The " << i + 1 << "th element is: " << data[i] << std::endl;
    }
}
template <typename T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize <= 0)
    {
        std::cout << "The new size is invalid, please input again: ";
        return;
    }
    T *newData = new T[newSize];
    if (newData == nullptr)
    {
        std::cerr << "malloc memory failed for SeqList" << std::endl;
        exit(1);
    }
    int newLast = std::min(last, newSize);
    for (int i = 0; i < newLast; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    maxSize = newSize;
    last = newLast;
}
template <typename T>
SeqList<T> &SeqList<T>::operator=(const SeqList<T> &L)
{
    if (this == &L)
    {
        return *this;
    }
    delete[] data;
    maxSize = L.maxSize;
    last = L.last;
    data = new T[maxSize];
    if (data == nullptr)
    {
        std::cerr << "malloc memory failed for SeqList" << std::endl;
        exit(1);
    }
    for (int i = 0; i < last; i++)
    {
        data[i] = L.data[i];
    }
    return *this;
}
#endif
#ifdef DS_SINGLYLINKEDLIST_IMPLEMENTATION
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = new Node;
    if (head == nullptr)
    {
        std::cerr << "malloc memory failed for SinglyLinkedList.head" << std::endl;
        exit(1);
    }
    head->next = nullptr;
}
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &L)
{
    head = new Node;
    if (head == nullptr)
    {
        std::cerr << "malloc memory failed for SinglyLinkedList.head" << std::endl;
        exit(1);
    }
    head->next = nullptr;
    Node *p = L.head->next;
    Node *q = head;
    while (p != nullptr)
    {
        q->next = new Node;
        if (q->next == nullptr)
        {
            std::cerr << "malloc memory failed for SinglyLinkedList.q->next" << std::endl;
            exit(1);
        }
        q = q->next;
        q->data = p->data;
        p = p->next;
        q->next = nullptr;
    }
}
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    Node *p = head->next;
    while (p != nullptr)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
    delete head;
}
template <typename T>
int SinglyLinkedList<T>::Size() const
{
    int sz = 0;
    Node *p = head->next;
    while (p != nullptr)
    {
        sz++;
        p = p->next;
    }
    return sz;
}
template <typename T>
int SinglyLinkedList<T>::Length() const
{
    return Size();
}
template <typename T>
bool SinglyLinkedList<T>::IsEmpty() const
{
    return head->next == nullptr;
}
template <typename T>
bool SinglyLinkedList<T>::IsFull() const
{
    return false;
}
template <typename T>
int SinglyLinkedList<T>::Search(const T &x) const
{
    Node *p = head->next;
    int i = 1;
    while (p != nullptr)
    {
        if (p->data == x)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return 0;
}
template <typename T>
int SinglyLinkedList<T>::Locate(int i) const
{
    if (i < 1 || i > Size())
    {
        return 0;
    }
    return i;
}
template <typename T>
T *SinglyLinkedList<T>::getData(int i) const
{
    if (i < 1 || i > Size())
    {
        return nullptr;
    }
    Node *p = head->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    return &p->data;
}
template <typename T>
void SinglyLinkedList<T>::setData(int i, const T &x)
{
    if (i < 1 || i > Size())
    {
        return;
    }
    Node *p = head->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    p->data = x;
    return;
}
template <typename T>
bool SinglyLinkedList<T>::Insert(int i, const T &x)
{
    if (i < 1 || i > Size() + 1)
    {
        return false;
    }
    Node *p = head;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for SinglyLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}
template <typename T>
bool SinglyLinkedList<T>::Remove(int i, T &x)
{
    if (i < 1 || i > Size())
    {
        return false;
    }
    Node *p = head;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    Node *delNode = p->next;
    x = delNode->data;
    p->next = delNode->next;
    delete delNode;
    return true;
}
template <typename T>
void SinglyLinkedList<T>::Sort()
{
    if (IsEmpty())
    {
        return;
    }
    for (Node *p = head->next; p != nullptr; p = p->next)
    {
        for (Node *q = p->next; q != nullptr; q = q->next)
        {
            if (p->data > q->data)
            {
                std::swap(p->data, q->data);
            }
        }
    }
}
template <typename T>
void SinglyLinkedList<T>::Input()
{
    std::cout << "Input the length of the list: ";
    int len;
    std::cin >> len;
    while (len < 0)
    {
        std::cout << "The length is negative, please input again: ";
        std::cin >> len;
    }
    for (int i = 0; i < len; i++)
    {
        T x;
        std::cout << "Input the " << i + 1 << "th element: ";
        std::cin >> x;
        pushBack(x);
    }
}
template <typename T>
void SinglyLinkedList<T>::Output()
{
    std::cout << "The length of the list is: " << Size() << std::endl;
    Node *p = head->next;
    int i = 1;
    while (p != nullptr)
    {
        std::cout << "The " << i << "th element is: " << p->data << std::endl;
        p = p->next;
        i++;
    }
}
template <typename T>
void SinglyLinkedList<T>::pushFront(const T &x)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for SinglyLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;
}
template <typename T>
void SinglyLinkedList<T>::pushBack(const T &x)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for SinglyLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = nullptr;
    Node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = newNode;
}
template <typename T>
void SinglyLinkedList<T>::removeFront()
{
    T x;
    Remove(1, x);
}
template <typename T>
void SinglyLinkedList<T>::removeBack()
{
    T x;
    Remove(Size(), x);
}
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList<T> &L)
{
    if (this == &L)
    {
        return *this;
    }
    Node *p = head->next;
    while (p != nullptr)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
    head->next = nullptr;
    p = L.head->next;
    Node *q = head;
    while (p != nullptr)
    {
        q->next = new Node;
        if (q->next == nullptr)
        {
            std::cerr << "malloc memory failed for SinglyLinkedList.q->next" << std::endl;
            exit(1);
        }
        q = q->next;
        q->data = p->data;
        p = p->next;
    }
    q->next = nullptr;
    return *this;
}
#endif
#ifdef DS_CIRCULARLINKEDLIST_IMPLEMENTATION
template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
    head = new Node;
    if (head == nullptr)
    {
        std::cerr << "malloc memory failed for :CircularLinkedList.head" << std::endl;
        exit(1);
    }
    tail = head;
    head->next = head;
}
template <typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T> &L)
{
    head = new Node;
    if (head == nullptr)
    {
        std::cerr << "malloc memory failed for :CircularLinkedList.head" << std::endl;
        exit(1);
    }
    head->next = head;
    Node *p = L.head->next;
    Node *q = head;
    while (p != L.head)
    {
        q->next = new Node;
        if (q->next == nullptr)
        {
            std::cerr << "malloc memory failed for :CircularLinkedList.q->next" << std::endl;
            exit(1);
        }
        q = q->next;
        q->data = p->data;
        p = p->next;
    }
    tail = q;
    q->next = head;
}
template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Node *p = head->next;
    while (p != head)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
    delete head;
}
template <typename T>
int CircularLinkedList<T>::Size() const
{
    int sz = 0;
    Node *p = head->next;
    while (p != head)
    {
        sz++;
        p = p->next;
    }
    return sz;
}
template <typename T>
int CircularLinkedList<T>::Length() const
{
    return Size();
}
template <typename T>
bool CircularLinkedList<T>::IsEmpty() const
{
    return head->next == head;
}
template <typename T>
bool CircularLinkedList<T>::IsFull() const
{
    return false;
}
template <typename T>
int CircularLinkedList<T>::Search(const T &x) const
{
    Node *p = head->next;
    int i = 1;
    while (p != head)
    {
        if (p->data == x)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return 0;
}
template <typename T>
int CircularLinkedList<T>::Locate(int i) const
{
    if (i < 1 || i > Size())
    {
        return 0;
    }
    return i;
}
template <typename T>
T *CircularLinkedList<T>::getData(int i) const
{
    if (i < 1 || i > Size())
    {
        return nullptr;
    }
    Node *p = head->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    return &p->data;
}
template <typename T>
void CircularLinkedList<T>::setData(int i, const T &x)
{
    if (i < 1 || i > Size())
    {
        return;
    }
    Node *p = head->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    p->data = x;
    return;
}
template <typename T>
bool CircularLinkedList<T>::Insert(int i, const T &x)
{
    if (i < 1 || i > Size() + 1)
    {
        return false;
    }
    Node *p = head;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for :CircularLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
    if (p == tail)
    {
        tail = newNode;
    }
    return true;
}
template <typename T>
bool CircularLinkedList<T>::Remove(int i, T &x)
{
    if (i < 1 || i > Size())
    {
        return false;
    }
    Node *p = head;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    Node *delNode = p->next;
    x = delNode->data;
    p->next = delNode->next;
    if (delNode == tail)
    {
        tail = p;
    }
    delete delNode;
    return true;
}
template <typename T>
void CircularLinkedList<T>::Sort()
{
    if (IsEmpty())
    {
        return;
    }
    for (Node *p = head->next; p != head; p = p->next)
    {
        for (Node *q = p->next; q != head; q = q->next)
        {
            if (p->data > q->data)
            {
                std::swap(p->data, q->data);
            }
        }
    }
}
template <typename T>
void CircularLinkedList<T>::Input()
{
    std::cout << "Input the length of the list: ";
    int len;
    std::cin >> len;
    while (len < 0)
    {
        std::cout << "The length is negative, please input again: ";
        std::cin >> len;
    }
    for (int i = 0; i < len; i++)
    {
        T x;
        std::cout << "Input the " << i + 1 << "th element: ";
        std::cin >> x;
        pushBack(x);
    }
}
template <typename T>
void CircularLinkedList<T>::Output()
{
    std::cout << "The length of the list is: " << Size() << std::endl;
    Node *p = head->next;
    int i = 1;
    while (p != head)
    {
        std::cout << "The " << i << "th element is: " << p->data << std::endl;
        p = p->next;
        i++;
    }
}
template <typename T>
void CircularLinkedList<T>::pushFront(const T &x)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for :CircularLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;
}
template <typename T>
void CircularLinkedList<T>::pushBack(const T &x)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for :CircularLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}
template <typename T>
void CircularLinkedList<T>::removeFront()
{
    T x;
    Remove(1, x);
}
template <typename T>
void CircularLinkedList<T>::removeBack()
{
    T x;
    Remove(Size(), x);
}
template <typename T>
bool CircularLinkedList<T>::isCircular() const
{
    return tail->next == head;
}
template <typename T>
CircularLinkedList<T> &CircularLinkedList<T>::operator=(const CircularLinkedList<T> &L)
{
    if (this == &L)
    {
        return *this;
    }
    Node *p = head->next;
    while (p != head)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
    head->next = head;
    p = L.head->next;
    Node *q = head;
    while (p != L.head)
    {
        q->next = new Node;
        if (q->next == nullptr)
        {
            std::cerr << "malloc memory failed for :CircularLinkedList.q->next" << std::endl;
            exit(1);
        }
        q = q->next;
        q->data = p->data;
        p = p->next;
    }
    tail = q;
    q->next = head;
    return *this;
}
#endif
#ifdef DS_DOUBLYLINKEDLIST_IMPLEMENTATION
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = new Node;
    if (head == nullptr)
    {
        std::cerr << "malloc memory failed for :DoublyLinkedList.head" << std::endl;
        exit(1);
    }
    head->prev = head;
    head->next = head;
}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &L)
{
    head = new Node;
    if (head == nullptr)
    {
        std::cerr << "malloc memory failed for :DoublyLinkedList.head" << std::endl;
        exit(1);
    }
    head->prev = head;
    head->next = head;
    Node *p = L.head->next;
    Node *q = head;
    while (p != L.head)
    {
        q->next = new Node;
        if (q->next == nullptr)
        {
            std::cerr << "malloc memory failed for :DoublyLinkedList.q->next" << std::endl;
            exit(1);
        }
        q->next->prev = q;
        q = q->next;
        q->data = p->data;
        p = p->next;
    }
    head->prev = q;
    q->next = head;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node *p = head->next;
    while (p != head)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
    delete head;
}
template <typename T>
int DoublyLinkedList<T>::Size() const
{
    int sz = 0;
    Node *p = head->next;
    while (p != head)
    {
        sz++;
        p = p->next;
    }
    return sz;
}
template <typename T>
int DoublyLinkedList<T>::Length() const
{
    return Size();
}
template <typename T>
bool DoublyLinkedList<T>::IsEmpty() const
{
    return head->next == head;
}
template <typename T>
bool DoublyLinkedList<T>::IsFull() const
{
    return false;
}
template <typename T>
int DoublyLinkedList<T>::Search(const T &x) const
{
    Node *p = head->next;
    int i = 1;
    while (p != head)
    {
        if (p->data == x)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return 0;
}
template <typename T>
int DoublyLinkedList<T>::Locate(int i) const
{
    if (i < 1 || i > Size())
    {
        return 0;
    }
    return i;
}
template <typename T>
T *DoublyLinkedList<T>::getData(int i) const
{
    if (i < 1 || i > Size())
    {
        return nullptr;
    }
    Node *p = head->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    return &p->data;
}
template <typename T>
void DoublyLinkedList<T>::setData(int i, const T &x)
{
    if (i < 1 || i > Size())
    {
        return;
    }
    Node *p = head->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    p->data = x;
    return;
}
template <typename T>
bool DoublyLinkedList<T>::Insert(int i, const T &x)
{
    if (i < 1 || i > Size() + 1)
    {
        return false;
    }
    Node *p = head;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for :DoublyLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->prev = p;
    p->next->prev = newNode;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}
template <typename T>
bool DoublyLinkedList<T>::Remove(int i, T &x)
{
    if (i < 1 || i > Size())
    {
        return false;
    }
    Node *p = head;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    Node *delNode = p->next;
    x = delNode->data;
    p->next = delNode->next;
    delNode->next->prev = p;
    delete delNode;
    return true;
}
template <typename T>
void DoublyLinkedList<T>::Sort()
{
    if (IsEmpty())
    {
        return;
    }
    for (Node *p = head->next; p != head; p = p->next)
    {
        for (Node *q = p->next; q != head; q = q->next)
        {
            if (p->data > q->data)
            {
                std::swap(p->data, q->data);
            }
        }
    }
}
template <typename T>
void DoublyLinkedList<T>::Input()
{
    std::cout << "Input the length of the list: ";
    int len;
    std::cin >> len;
    while (len < 0)
    {
        std::cout << "The length is negative, please input again: ";
        std::cin >> len;
    }
    for (int i = 0; i < len; i++)
    {
        T x;
        std::cout << "Input the " << i + 1 << "th element: ";
        std::cin >> x;
        pushBack(x);
    }
}
template <typename T>
void DoublyLinkedList<T>::Output()
{
    std::cout << "The length of the list is: " << Size() << std::endl;
    Node *p = head->next;
    int i = 1;
    while (p != head)
    {
        std::cout << "The " << i << "th element is: " << p->data << std::endl;
        p = p->next;
        i++;
    }
}
template <typename T>
void DoublyLinkedList<T>::pushFront(const T &x)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for :DoublyLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->prev = head;
    head->next->prev = newNode;
    newNode->next = head->next;
    head->next = newNode;
}
template <typename T>
void DoublyLinkedList<T>::pushBack(const T &x)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        std::cerr << "malloc memory failed for :DoublyLinkedList.newNode" << std::endl;
        exit(1);
    }
    newNode->data = x;
    newNode->next = head;
    head->prev->next = newNode;
    newNode->prev = head->prev;
    head->prev = newNode;
}
template <typename T>
void DoublyLinkedList<T>::removeFront()
{
    T x;
    Remove(1, x);
}
template <typename T>
void DoublyLinkedList<T>::removeBack()
{
    T x;
    Remove(Size(), x);
}
template <typename T>
void DoublyLinkedList<T>::OutputReverse()
{
    std::cout << "Reversed Ouput:" << std::endl;
    std::cout << "The length of the list is: " << Size() << std::endl;
    Node *p = head->prev;
    int i = Size();
    while (p != head)
    {
        std::cout << "The " << i << "th element is: " << p->data << std::endl;
        p = p->prev;
        i--;
    }
}
template <typename T>
void DoublyLinkedList<T>::reverseList()
{
    if (IsEmpty())
    {
        return;
    }
    Node *p = head->next, *tmp = NULL;
    while (p != head)
    {
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
    }
    tmp = head->next;
    head->next = head->prev;
    head->prev = tmp;
}
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &L)
{
    if (this == &L)
    {
        return *this;
    }
    Node *p = head->next;
    while (p != head)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
    head->prev = head;
    head->next = head;
    p = L.head->next;
    Node *q = head;
    while (p != L.head)
    {
        q->next = new Node;
        if (q->next == nullptr)
        {
            std::cerr << "malloc memory failed for :DoublyLinkedList.q->next" << std::endl;
            exit(1);
        }
        q->next->prev = q;
        q = q->next;
        q->data = p->data;
        p = p->next;
    }
    head->prev = q;
    q->next = head;
    return *this;
}
#endif
#ifdef DS_SEQSTACK_IMPLEMENTATION
template <typename T>
void SeqStack<T>::overflowProcess()
{
    maxSize *= 2;
    T *newElements = new T[maxSize];
    if (newElements == nullptr)
    {
        std::cerr << "malloc memory failed for SeqStack.newElements" << std::endl;
        exit(1);
    }
    for (int i = 0; i < top + 1; ++i)
    {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}
template <typename T>
SeqStack<T>::SeqStack(int sz)
{
    maxSize = sz;
    top = -1;
    elements = new T[maxSize];
    if (elements == nullptr)
    {
        std::cerr << "malloc memory failed for SeqStack.elements" << std::endl;
        exit(1);
    }
}
template <typename T>
SeqStack<T>::SeqStack(const SeqStack<T> &S)
{
    maxSize = S.maxSize;
    elements = new T[maxSize];
    if (elements == nullptr)
    {
        std::cerr << "malloc memory failed for SeqStack.elements" << std::endl;
        exit(1);
    }
    top = S.top;
    for (int i = 0; i < top + 1; ++i)
    {
        elements[i] = S.elements[i];
    }
}
template <typename T>
SeqStack<T>::~SeqStack()
{
    delete[] elements;
};
template <typename T>
void SeqStack<T>::Push(const T &x)
{
    if (IsFull())
    {
        overflowProcess();
    }
    elements[++top] = x;
};
template <typename T>
bool SeqStack<T>::Pop(T &x)
{
    if (IsEmpty())
    {
        std::cout << "Stack is empty, Pop() failed";
        return false;
    }

    x = elements[top--];

    return true;
};
template <typename T>
bool SeqStack<T>::getTop(T &x) const
{
    if (IsEmpty())
    {
        std::cout << "Stack is empty, getTop() failed";
        return false;
    }
    x = elements[top];
    return true;
};
template <typename T>
bool SeqStack<T>::IsEmpty() const
{
    return top == -1;
};
template <typename T>
bool SeqStack<T>::IsFull() const
{
    return top == maxSize - 1;
};
template <typename T>
int SeqStack<T>::getSize() const
{
    return top + 1;
};
template <typename T>
void SeqStack<T>::MakeEmpty()
{
    top = -1;
}
template <typename T>
SeqStack<T> &SeqStack<T>::operator=(const SeqStack<T> &S)
{
    if (this == &S)
    {
        return *this;
    }
    delete[] elements;
    maxSize = S.maxSize;
    top = S.top;
    elements = new T[maxSize];
    if (elements == nullptr)
    {
        std::cerr << "malloc memory failed for SeqStack.elements" << std::endl;
        exit(1);
    }
    for (int i = 0; i < top + 1; ++i)
    {
        elements[i] = S.elements[i];
    }

    return *this;
};
template <typename T>
std::ostream &operator<<(std::ostream &os, SeqStack<T> &s)
{
    os << "top = " << s.top << std::endl;
    for (int i = 0; i < s.top + 1; ++i)
    {
        os << s.elements[i] << " ";
    }
    os << std::endl;
    return os;
};
#endif
#endif // DATASTRUCTURE
