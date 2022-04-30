//
// Created by alllowd on 4/30/22.
//

#ifndef VERSUCH_2_ABSTRACTDISH_H
#define VERSUCH_2_ABSTRACTDISH_H

#include <iostream>
#include <vector>

namespace dishlib {

    class AbstractDish {
    protected:
        std::vector<std::string> vIngredients;
        std::string const dishName;

        void AddIngredients(std::string const &);
    public:
        AbstractDish() = delete;
        explicit AbstractDish(std::string );
        virtual ~AbstractDish() = default;

        virtual void Prepare() = 0;
        [[nodiscard]] std::string GetDishName() const;
        [[nodiscard]] std::vector<std::string> GetIngredients() const;
        [[nodiscard]] unsigned long GetNumberIngredients() const;
    };

}

#endif //VERSUCH_2_ABSTRACTDISH_H
