//
// Created by alllowd on 4/30/22.
//

#include "PizzaMargherita.h"

namespace dishlib {

    PizzaMargherita::PizzaMargherita(const std::string &name): AbstractDish {name} {}

    void PizzaMargherita::Prepare() {
        std::cout << "prepare dough" << std::endl;
        AddIngredients("dough");
        std::cout << "include tomato sauce" << std::endl;
        AddIngredients("tomato sauce");
        std::cout << "include cheese" << std::endl;
        AddIngredients("cheese");
    }

}