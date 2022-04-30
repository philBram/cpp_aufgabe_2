//
// Created by alllowd on 4/30/22.
//

#include <iostream>

#include "A.h"

A::A(int const value): _nptr {new int}, _aptr {new int [5]} {
    std::cout << "class A constructor: " + std::to_string(value) << std::endl;

    *_nptr = value;

    for (int i = 0; i < 5; i++) {
        *(_aptr + i) = 42;
    }
}

A::A(A const &a): _nptr {new int}, _aptr {new int [5]} {
    std::cout << "class A copy constructor: " + std::to_string(*(a._nptr)) << std::endl;

    *_nptr = *(a._nptr);

    for (int i = 0; i < 5; i++) {
        *(_aptr + i) = *(a._aptr + i);
    }
}

A::A(A &&a) noexcept {
    std::cout << "class A move constructor: " + std::to_string(*(a._nptr)) << std::endl;

    std::swap(a._nptr, _nptr);
    std::swap(a._aptr, _aptr);
}

A &A::operator=(const A &a) {
    std::cout << "class A copy assignment operator: " + std::to_string(*(a._nptr)) << std::endl;

    if (&a == this) {
        return *this;
    }

    _nptr = new int;
    _aptr = new int [5];

    *(_nptr) = *(a._nptr);

    for (int i = 0; i < 5; i++) {
        *(_aptr + i) = *(a._aptr + i);
    }

    return *this;
}

A &A::operator=(A &&a) {
    std::cout << "class A move assignment operator: " + std::to_string(*a._nptr) << std::endl;

    std::swap(a._nptr, _nptr);
    std::swap(a._aptr, _aptr);

    return *this;
}

A::~A() {
    if (nullptr == _nptr && nullptr == _aptr) {
        std::cout << "class A destructor: nullptr" << std::endl;
    }
    else {
        std::cout << "class A destructor: " + std::to_string(*_nptr) << std::endl;
        delete _nptr;
        delete[] _aptr;
    }
}
