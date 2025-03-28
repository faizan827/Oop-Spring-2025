class Character {
public:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
    virtual void attack() {}
    virtual void defend() {}
    virtual void displayStats() {}
};

class Warrior : public Character {
public:
    int armorStrength;
    int meleeDamage;
    void attack() {}
};

class Mage : public Character {
public:
    int manaPoints;
    int spellPower;
    void defend() {}
};

class Archer : public Character {
public:
    int arrowCount;
    int rangedAccuracy;
    void attack() {}
};

class Rogue : public Character {
public:
    int stealthLevel;
    int agility;
    void displayStats() {}
};

int main() {
    return 0;
}
