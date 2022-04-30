//
// Created by alllowd on 4/30/22.
//

#include "DishFactory.h"

namespace dishlib {

    std::unique_ptr<AbstractDish> DishFactory::CreateDish(DishFactory::DishType dishType) {
        std::unique_ptr<AbstractDish> dish;

        switch (dishType) {
            case DishType::SOUP:
                dish = std::make_unique<VegetableSoup>("soup");
                dish->Prepare();
                return dish;
            case DishType::PIZZA:
                dish = std::make_unique<PizzaMargherita>("pizza");
                dish->Prepare();
                return dish;
            default:
                return nullptr;
        }
    }

}