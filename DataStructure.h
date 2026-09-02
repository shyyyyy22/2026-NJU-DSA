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
#ifdef DS_SEQLIST_IMPLEMENTATION
template <typename T>
SeqList<T>::SeqList(int size)
{
    maxSize = size;
    last = 0;
    data = new T[maxSize];
};
template <typename T>
SeqList<T>::SeqList(const SeqList<T> &L)
{
    maxSize = L.maxSize;
    last = L.last;
    data = new T[maxSize];
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
    for (int i = 0; i < last; i++)
    {
        data[i] = L.data[i];
    }
    return *this;
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
#endif
#endif // DATASTRUCTURE
