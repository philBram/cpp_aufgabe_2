#include <iostream>
#include <vector>
#include <algorithm>

#include "A.h"
#include "DishFactory.h"
#include "AbstractDish.h"
#include "Customer.h"

using namespace std;
using Distype = std::unique_ptr<dishlib::AbstractDish>;
using DishFactory = dishlib::DishFactory;

int main() {
    /* // Teil A.1
    A a1{3};

    // Teil A.2
    A a2{a1};
    A a3{A{4}};

    // Teil A.3
    vector<A> v;
    v.push_back(A{5});

    // Teil A.4
    A a5{7};
    A a6{8};
    a6 = a5;

    // Teil A.5
    A a7{9};
    a7 = A{10};

    // Teil A.6
    A a8{11};
    A a9{move(a8)}; */

    // Fragen zu Teil A:

    // Warum wird bei “ A a3{A{4}}; “ in Teil A.2 kein Kopierkonstruktor aufgerufen?
    // Der Kompiler erkennt, dass A{4} nur temporär ist und verschachtelt ist -> Copy Elision

    // Warum wird in Teil A.3 “ class A destructor: nullptr ” ausgegeben?
    // Object wird in den vector verschoben, wodurch die Membervariablen des Objectes (durch swap in move ctor) jetzt auf nullptr zeigen
    // -> dtor-Aufruf da Object nicht mehr gebraucht wird.

    // Warum wird in Teil A.5 “ class A destructor: 9 ” ausgegeben?
    // Wird ausgegeben, da a7 die Werte von A {10} durch verschieben erhalten hat (swap in move assignment operator) somit
    // besitzt das temporäre Objekt die Werte von a7 und wird nicht mehr gebraucht -> dtor-Aufruf

    // Inwiefern verhält sich Teil A.6 anders als Teil A.2?
    // In Teil A.6 ist a8 ein lvalue mit move semantik wird daraus ein rvalue -> move ctor Aufruf
    // In Teil A.2 ist a1 ein lvalue -> ctor Aufruf
    // In Teil A.2 ist A{4} zwar auch ein rvalue, aber der Kompiler ist so schlau, zu erkennen, dass er A{4} nicht
    // extra erzeugen muss, um es dann anschließend zu verschieben und verwendet einfach nur den Wert 4 um damit a3 zu
    // erzeugen.

    vector<Distype> dishes;
    bool ascending {true};

    for (int i = 0; i < 3; i++) {
        dishes.emplace_back(move(DishFactory::CreateDish(DishFactory ::DishType::SOUP)));
        dishes.push_back(move(DishFactory::CreateDish(DishFactory ::DishType::PIZZA)));
    }

    sort(dishes.begin(), dishes.end(), [ascending](Distype &a, Distype &b) {
        return ascending ? a->GetNumberIngredients() < b->GetNumberIngredients() : a->GetNumberIngredients() > b->GetNumberIngredients();
    });

    for (auto const &a: dishes) {
        cout << "dish: " << a->GetDishName() << " - number of ingredients: " << a->GetNumberIngredients() << endl;
    }

    vector<unique_ptr<Customer>> customers;

    for (int i = 0; i < dishes.size(); i++) {
        customers.emplace_back(make_unique<Customer>("customer" + to_string(i)));
        customers.at(i)->ServeDish(dishes.at(i));
    }

    dishes.clear();

    for (auto const &customer: customers) {
        customer->EatDish();
    }

    for (auto const &dish: dishes) {
        cout << (nullptr == dish) << endl;
    }

    return 0;
}
