//
// Created by alllowd on 4/30/22.
//

#ifndef VERSUCH_2_DISHFACTORY_H
#define VERSUCH_2_DISHFACTORY_H

#include <memory>

#include "AbstractDish.h"
#include "VegetableSoup.h"
#include "PizzaMargherita.h"

namespace dishlib {

    class DishFactory {
    public:
        enum class DishType {SOUP, PIZZA};
        static std::unique_ptr<AbstractDish> CreateDish(DishType dishType);
    };

}

#endif //VERSUCH_2_DISHFACTORY_H
