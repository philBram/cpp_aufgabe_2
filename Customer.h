//
// Created by alllowd on 4/30/22.
//

#ifndef VERSUCH_2_CUSTOMER_H
#define VERSUCH_2_CUSTOMER_H

#include <memory>

#include "AbstractDish.h"

class Customer {
    std::unique_ptr<dishlib::AbstractDish> customerDish;
    std::string const customerName;
public:
    Customer() = delete;
    explicit Customer(std::string );
    void ServeDish(std::unique_ptr<dishlib::AbstractDish> &dish);
    void EatDish();
};


#endif //VERSUCH_2_CUSTOMER_H
