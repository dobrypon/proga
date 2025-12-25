#include "lab4.h"

static void task_1()
{
    Weapon w1;
    Weapon w2("mace", 8, 10); 

    w1.print();
    w2.print();
}

static void task_2()
{
    Weapon w1;
    Weapon* w2 = new Weapon("mace", 8, 10); 

    std::cout << "1. weight check: " << w1.is_weight_accessable(28) << std::endl; 
    std::cout << "2. weight check: " << w2->is_weight_accessable(15) << std::endl;
    std::cout << "sum weights: " << w1.sum_properties(w2) << std::endl;

    delete w2;
}

static void task_4()
{
    Weapon w;

    std::cout << "get_name: " << w.get_name() << std::endl;
    std::cout << "get_damage: " << w.get_damage() << std::endl;
    std::cout << "get_weight: " << w.get_weight() << std::endl;

    w.set_name("great_sword");
    w.set_damage(300); 
    w.set_weight(150); 

    std::cout << "get_name: " << w.get_name() << std::endl;
    std::cout << "get_damage: " << w.get_damage() << std::endl;
    std::cout << "get_weight: " << w.get_weight() << std::endl;

    Characteristic ch(85); 
    std::cout << "characteristic: " << ch.get_damage(&w) << std::endl;

    std::cout << "add: " << MyMath::add(10, 25) << std::endl; 
    std::cout << "sub: " << MyMath::sub(15, 5) << std::endl;
    std::cout << "mul: " << MyMath::mul(6, 7) << std::endl;
    std::cout << "div: " << MyMath::div(20, 4) << std::endl;
    std::cout << "calls: " << MyMath::calls << std::endl;
}

int main()
{
    task_4();
}
