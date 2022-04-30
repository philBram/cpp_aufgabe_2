//
// Created by alllowd on 4/30/22.
//

#include "VegetableSoup.h"

namespace dishlib {

    VegetableSoup::VegetableSoup(std::string const &dishName): AbstractDish {dishName} {}

    void VegetableSoup::Prepare() {
        std::cout << "boil water" << std::endl;
        AddIngredients("hot water");
        std::cout << "cut carrots" << std::endl;
        AddIngredients("carrots");
        std::cout << "cut onions" << std::endl;
        AddIngredients("onions");
        std::cout << "cut paprika" << std::endl;
        AddIngredients("paprika");
    }

}