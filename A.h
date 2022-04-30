//
// Created by alllowd on 4/30/22.
//

#ifndef VERSUCH_2_A_H
#define VERSUCH_2_A_H


class A {
    int *_nptr {nullptr};
    int *_aptr {nullptr};
public:
    explicit A(int);
    A(A const &);
    A(A &&) noexcept;
    A &operator=(A const &);
    A &operator=(A &&);
    ~A();
};


#endif //VERSUCH_2_A_H
