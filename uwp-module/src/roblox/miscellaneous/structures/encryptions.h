#pragma once
#include <string_view>
#include <cstdint>
#include <string>

#define vm_value1 vmvalue1
#define vm_value2 vmvalue2
#define vm_value3 vmvalue3
#define vm_value4 vmvalue4

#define vmvalue1_t vmvalue1
#define vmvalue2_t vmvalue2
#define vmvalue3_t vmvalue3
#define vmvalue4_t vmvalue4

#define addenc_t vmvalue1
#define sub2enc_t vmvalue2
#define xorenc_t vmvalue3
#define sub1enc_t vmvalue4


template <typename T> struct vmvalue1 {
private:
    T storage;
public:
    operator const T() const {
        return (T)((uintptr_t)storage - (uintptr_t)this);
    }

    void operator=(const T& value) {
        storage = (T)((uintptr_t)value + (uintptr_t)this);
    }

    const T operator->() const {
        return operator const T();
    }
};

template <typename T> struct vmvalue2 {
private:
    T storage;
public:
    operator const T() const {
        return (T)((uintptr_t)this - (uintptr_t)storage);
    }

    void operator=(const T& value) {
        storage = (T)((uintptr_t)this - (uintptr_t)value);
    }

    const T operator->() const {
        return operator const T();
    }
};

template <typename T> struct vmvalue3 {
private:
    T storage;
public:
    operator const T() const {
        return (T)((uintptr_t)this ^ (uintptr_t)storage);
    }

    void operator=(const T& value) {
        storage = (T)((uintptr_t)value ^ (uintptr_t)this);
    }

    const T operator->() const {
        return operator const T();
    }
};

template <typename T> struct vmvalue4 {
private:
    T storage;
public:
    operator const T() const {
        return (T)((uintptr_t)this + (uintptr_t)storage);
    }

    void operator=(const T& value) {
        storage = (T)((uintptr_t)value - (uintptr_t)this);
    }

    const T operator->() const {
        return operator const T();
    }
};