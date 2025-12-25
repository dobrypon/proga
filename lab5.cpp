#include <iostream>

enum WeaponType
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
        : Weapon("default_weapon_name", 10, 20, WeaponType::ONEHANDED)
    {
    }

    Weapon(const std::string& name,
        const int damage,
        const int weight,
        const WeaponType type)
        : m_name(name)
        , m_damage(damage)
        , m_weight(weight)
        , m_type(type)
    {
    }

    ~Weapon()
    {
        std::printf("(DESTRUCTOR) name: %s, damage: %d, weight: %d\n", m_name.c_str(), m_damage, m_weight);
    }

    void print()
    {
        std::printf("name: %s, damage: %d, weight: %d\n", m_name.c_str(), m_damage, m_weight);
    }

    bool is_weight_accessable(const int max_weight)
    {
        return m_weight > max_weight;
    }

    int sum_properties(const int weight)
    {
        return m_weight + weight;
    }

    int sum_properties(Weapon* weapon)
    {
        return sum_properties(weapon->m_weight);
    }

    void set_name(const std::string& name) { m_name = name; }
    void set_damage(const int damage) { m_damage = damage; }
    void set_weight(const int weight) { m_weight = weight; }

    const std::string& get_name() { return m_name; }
    virtual int get_damage() const { return m_damage; }
    int get_weight() { return m_weight; }
    WeaponType get_type() { return m_type; }

    inline bool operator>(const Weapon& right)
    {
        return get_damage() > right.get_damage();
    }
    inline bool operator<(const Weapon& right)
    {
        return get_damage() < right.get_damage();
    }
protected:
    std::string m_name;
    int m_damage;
    int m_weight;
    WeaponType m_type;
};

struct Player
{
    Player(const std::string& login, const std::string& password, const int id)
        : m_login(login)
        , m_password(password)
        , m_id(id)
    {
    }

    void print()
    {
        std::printf(
            "login: %s, password: %s, id: %d\n",
            m_login.c_str(),
            m_password.c_str(),
            m_id
        );
    }

    std::string m_login;
    std::string m_password;
    int m_id;
};

class MagicWeapon : public Weapon
{
public:
    MagicWeapon()
        : Weapon("magic_weapon", 10, 20, WeaponType::ONEHANDED)
        , m_additional_damage(5)
    {
    }

    MagicWeapon(const std::string& name,
        const int damage,
        const int additional_damage,
        const int weight,
        const WeaponType type)
        : Weapon(name, damage, weight, type)
        , m_additional_damage(additional_damage)
    {
    }

    int get_damage() const override { return m_damage + m_additional_damage; }
    int get_additional_damage() { return m_additional_damage; }
private:
    int m_additional_damage;
};

static void task_1()
{
    Weapon weapon("weapon_crossbow", 10, 5, WeaponType::CROSSBOW);
    MagicWeapon magic_weapon("magic_weapon", 10, 10, 5, WeaponType::CROSSBOW);
    Player player("hello", "world", 1425235);

    WeaponType type = weapon.get_type();
    switch (type)
    {
    case ONEHANDED:
        std::cout << "Одноручное оружие" << std::endl;
        break;
    case TWOHANDED:
        std::cout << "Двуручное оружие" << std::endl;
        break;
    case BOW:
        std::cout << "Лук" << std::endl;
        break;
    case CROSSBOW:
        std::cout << "Арбалет" << std::endl;
        break;
    }

    weapon.print();
    player.print();

    std::cout << "magic weapon damage: " << magic_weapon.get_damage() << std::endl;
    std::cout << "magic_weapon vs weapon: " << (magic_weapon > weapon) << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");

    task_1();
}
