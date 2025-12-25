#ifndef _LAB_4_H
#define _LAB_4_H
#include <iostream>
#include <string>

class Weapon
{
    friend class Characteristic;
public:
    Weapon()
        : Weapon("basic_sword", 15, 25) 
    {
    }

    Weapon(const std::string& n, const int dmg, const int wgt)
        : name(n), damage(dmg), weight(wgt)
    {
    }

    ~Weapon()
    {
        std::printf("(DESTRUCTOR) name: %s, damage: %d, weight: %d\n", name.c_str(), damage, weight);
    }

    void print()
    {
        std::printf("name: %s, damage: %d, weight: %d\n", name.c_str(), damage, weight);
    }

    bool is_weight_accessable(const int max_wgt)
    {
        return weight > max_wgt;
    }

    int sum_properties(const int w)
    {
        return weight + w;
    }

    int sum_properties(Weapon* wpn)
    {
        return sum_properties(wpn->weight);
    }

    void set_name(const std::string& n) { name = n; }
    void set_damage(const int d) { damage = d; }
    void set_weight(const int w) { weight = w; }

    const std::string& get_name() { return name; }
    int get_damage() { return damage; }
    int get_weight() { return weight; }

private:
    std::string name;
    int damage;
    int weight;
};

class Characteristic
{
public:
    Characteristic(const int str)
        : strength(str)
    {
    }

    int get_damage(Weapon* w)
    {
        return strength + w->damage;
    }

private:
    int strength;
};

class MyMath
{
public:
    static int add(const int a, const int b)
    {
        calls++;
        return a + b;
    }

    static int sub(const int a, const int b)
    {
        calls++;
        return a - b;
    }

    static int mul(const int a, const int b)
    {
        calls++;
        return a * b;
    }

    static int div(const int a, const int b)
    {
        calls++;
        return a / b;
    }

    static inline int calls = 0;
};

#endif // !_LAB_4_H
