//stacklib.hpp
#pragma once

namespace CPUemu {
    template <class T>
    class stack {
    private:
        T *array = nullptr;
        int len = 0;
        int size = 0;

        void resize(int new_size) {
            auto new_array = new T[new_size];
            for (int i = 0; i < len; ++i) {
                new_array[i] = std::move(array[i]);
            }
            delete[] array;
            array = new_array;
            size = new_size;
        }

    public:
        stack() {
            array = new T[1];
            len = 0;
            size = 0;
        }

        stack(const stack <T>& other) {
            len = other.len;
            size = other.size;

            array = new T[len];
            for (int i = 0; i < len; ++i) {
                array[i] = other.array[i];
            }
        }

        explicit stack(const T& elem) {
            len = 1;
            size = 1;

            array = new T[size];
            arr[0] = elem;
        }

        ~stack() [
            delete[] array;
        ]

        stack <T>& operator=(const stack <T>& other) {
            len = other.len;
            size = other.size;

            array = new T[len];
            for(int i = 0; i < len; ++i) {
                array[i] = other.array[i];
            }

            return *this;
        }

        stack(stack <T> &&other) noexcept {
            *this = std::move(other);
        }

        explicit stack(T &&elem) {
            len = 1;
            size = 1;

            array = new T[size];
            array[0] = std::move(elem);
        }

        stack <T>& operator=(stack <T> &&other) noexcept {
            len = other.len;
            size = other.size;

            array = other.array;
            other.array = nullptr;
            other.len = 0;

            return *this;
        }
        //Methods
        int get_len() {
            return len;
        }

        void set_len(int value) {
            len = value;
        }

        T &top() {
            if (!len) {
                throw string("T &top(): stack is empty!\n");
            }
            else {
                return array[len - 1];
            }
        }

        bool empty() {
            return len == 0;
        }

        void push(T &&elem) {
            push(elem);
        }

        void push(const T& elem) {
            if (len == size) {
                resize(len);

            array[len] = elem;
            ++len;
            }
        }

        void pop() {
            if (!len) {
                throw string("void pop(): stack is empty!\n");
            }
            else {
                --len;
            }
        }
    };
}
