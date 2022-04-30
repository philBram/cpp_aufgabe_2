//
// Created by alllowd on 4/30/22.
//

#ifndef VERSUCH_2_PIZZAMARGHERITA_H
#define VERSUCH_2_PIZZAMARGHERITA_H

#include "AbstractDish.h"

namespace dishlib {

    class PizzaMargherita : public AbstractDish {
    public:
        PizzaMargherita() = delete;
        explicit PizzaMargherita(std::string const &name);
        void Prepare() override;
    };

}

#endif //VERSUCH_2_PIZZAMARGHERITA_H
