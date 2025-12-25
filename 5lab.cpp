#include <iostream>

enum class WeaponType
{
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon
{
public:
    Weapon()
        : Weapon("basic_sword", 12, 18, WeaponType::ONEHANDED)
    {
    }

    Weapon(const std::string& n, int dmg, int wgt, WeaponType t)
        : name(n), damage(dmg), weight(wgt), type(t)
    {
    }

    virtual ~Weapon()
    {
        std::printf("(DESTRUCTOR) name: %s, damage: %d, weight: %d\n", name.c_str(), damage, weight);
    }

    void print()
    {
        std::printf("name: %s, damage: %d, weight: %d\n", name.c_str(), damage, weight);
    }

    virtual void attack() = 0;

    bool is_weight_accessable(int max_wgt)
    {
        return weight > max_wgt;
    }

    int sum_properties(int w)
    {
        return weight + w;
    }

    int sum_properties(Weapon* wpn)
    {
        return sum_properties(wpn->weight);
    }

    void set_name(const std::string& n) { name = n; }
    void set_damage(int d) { damage = d; }
    void set_weight(int w) { weight = w; }

    const std::string& get_name() { return name; }
    virtual int get_damage() const { return damage; }
    int get_weight() { return weight; }
    WeaponType get_type() { return type; }

    bool operator>(const Weapon& rhs) { return get_damage() > rhs.get_damage(); }
    bool operator<(const Weapon& rhs) { return get_damage() < rhs.get_damage(); }

protected:
    std::string name;
    int damage;
    int weight;
    WeaponType type;
};

class MagicWeapon : public Weapon
{
public:
    MagicWeapon()
        : Weapon("magic_sword", 16, 20, WeaponType::ONEHANDED)
        , extra_damage(8)
    {
    }

    MagicWeapon(const std::string& n, int dmg, int extra_dmg, int wgt, WeaponType t)
        : Weapon(n, dmg, wgt, t)
        , extra_damage(extra_dmg)
    {
    }

    void attack() override { std::cout << "Атакуем магическим оружием\n"; }

    int get_damage() const override { return damage + extra_damage; }
    int get_extra_damage() { return extra_damage; }

private:
    int extra_damage;
};

class OneHandedWeapon : public Weapon
{
public:
    OneHandedWeapon()
        : used(false)
    {
    }

    void attack() override
    {
        if (!used)
            std::cout << "Атакуем одноразовым оружием\n";
        else
            std::cout << "Оружие уже использовано\n";

        used = true;
    }

private:
    bool used;
};

class TwoHandedWeapon : public Weapon
{
public:
    TwoHandedWeapon(WeaponType l, WeaponType r)
        : left(l), right(r)
    {
    }

    void attack() override { std::cout << "Атакуем двуручным оружием\n"; }

    void set_left_weapon(WeaponType l) { left = l; }
    void set_right_weapon(WeaponType r) { right = r; }

    WeaponType get_left_weapon() { return left; }
    WeaponType get_right_weapon() { return right; }

private:
    WeaponType left;
    WeaponType right;
};

static void task_1()
{
    MagicWeapon magic("fire_sword", 15, 12, 7, WeaponType::ONEHANDED);
    OneHandedWeapon one;
    one.set_name("dagger");
    one.set_damage(8);
    one.set_weight(5);
    magic.attack();

    one.attack();
    one.attack();

    TwoHandedWeapon bow_crossbow(WeaponType::BOW, WeaponType::CROSSBOW);

    std::cout << "Left weapon type: " << static_cast<int>(bow_crossbow.get_left_weapon())
        << ", Right weapon type: " << static_cast<int>(bow_crossbow.get_right_weapon()) << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    task_1();
}
