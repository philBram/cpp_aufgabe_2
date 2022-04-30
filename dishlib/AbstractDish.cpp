//
// Created by alllowd on 4/30/22.
//

#include "AbstractDish.h"

#include <utility>

namespace dishlib {

    AbstractDish::AbstractDish(std::string dishName): dishName {std::move(dishName)} {}

    void AbstractDish::AddIngredients(std::string const &ingredient) {
        vIngredients.emplace_back(ingredient);
    }

    std::string AbstractDish::GetDishName() const {
        return dishName;
    }

    std::vector<std::string> AbstractDish::GetIngredients() const {
        return vIngredients;
    }

    unsigned long AbstractDish::GetNumberIngredients() const {
        return vIngredients.size();
    }

}