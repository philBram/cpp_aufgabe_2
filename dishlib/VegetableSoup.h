//
// Created by alllowd on 4/30/22.
//

#ifndef VERSUCH_2_VEGETABLESOUP_H
#define VERSUCH_2_VEGETABLESOUP_H

#include "AbstractDish.h"

namespace dishlib {

    class VegetableSoup: public AbstractDish {
    public:
        VegetableSoup() = delete;
        explicit VegetableSoup(std::string const &);

        void Prepare() override;
    };

}

#endif //VERSUCH_2_VEGETABLESOUP_H
