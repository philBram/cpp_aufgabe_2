//
// Created by alllowd on 4/30/22.
//

#include "Customer.h"

#include <utility>

Customer::Customer(std::string customerName): customerName {std::move(customerName)}, customerDish {nullptr} {}

void Customer::ServeDish(std::unique_ptr<dishlib::AbstractDish> &dish) {
    customerDish = std::move(dish);
}

void Customer::EatDish() {
    std::cout << customerName << " eats " << customerDish->GetDishName() << std::endl;
    customerDish = nullptr;
}