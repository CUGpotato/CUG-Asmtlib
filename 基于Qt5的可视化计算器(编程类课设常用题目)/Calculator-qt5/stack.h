#ifndef __MYOWNSTACK__
#define __MYOWNSTACK__

#include <stdexcept>

template<typename T>
class MyStack {
public:
    MyStack() : m_end(0) {
        m_array = new T[16];
        m_size = 16;
    }

    ~MyStack() {
        delete[] m_array;
    }

    bool empty() {
        return m_end <= 0;
    }

    const T& get_top() {
        if (empty())
            throw std::range_error("stack is empty, no top element");
        return m_array[m_end-1];
    }

    T& get() {
        if (empty())
            throw std::range_error("stack is empty");
        return m_array[--m_end];
    }

    void push(const T& element) {
        if (m_end >= m_size - 1)
            resize(m_size * 2);
        m_array[m_end++] = element;
    }

    void resize(const int new_size) {
        T *temp = new T[new_size];
        for (int i = 0; i < m_end; i++)
            temp[i] = m_array[i];
        delete[] m_array;
        m_array = temp;
    }

private:
    T *m_array;
    int m_end, m_size;
};

#endif
