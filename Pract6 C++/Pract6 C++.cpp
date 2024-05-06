#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tree 
{
private:
    string vidy;
public:
    Tree(string vidy) : vidy(vidy) {}

    string getvidy() const 
    {
        return vidy;
    }
};

class Animal 
{
private: 
    string vidy;
public: 
    Animal(string vidy) : vidy(vidy) {}

    string getvidy() const 
    {
        return vidy;
    }
};

class Forest 
{
private:
    vector<Tree> trees;
    vector<Animal> animals;
public:
    void addTree(const Tree& tree) 
    {
        trees.push_back(tree);
    }

    void addAnimal(const Animal& animal) 
    {
        animals.push_back(animal);
    }

    void infoForest() const 
    {
        cout << "Дерева в лесу:" << endl;
        for (const auto& tree : trees) 
        {
            cout << tree.getvidy() << endl;
        }

        cout << "\nЖивотные в лесу:" << endl;
        for (const auto& animal : animals) 
        {
            cout << animal.getvidy() << endl;
        }
    }

    bool animalest(const string& species) const 
    {
        for (const auto& animal : animals) 
        {
            if (animal.getvidy() == species) 
            {
                return true;
            }
        }
        return false;
    }

    bool Treeest(const string& species) const
    {
        for (const auto& tree : trees) 
        {
            if (tree.getvidy() == species) 
            {
                return true;
            }
        }
        return false;
    }
};

int main() 
{
    setlocale(LC_ALL, "RUS");

    Tree dyb("Дуб");
    Tree sos("Сосна");

    Animal olen("Олень");
    Animal med("Медведь");

    Forest forest;

    forest.addTree(dyb);
    forest.addTree(sos);

    forest.addAnimal(olen);
    forest.addAnimal(med);

    cout << "Информация о лесе:" << endl;
    forest.infoForest();

    cout << "\nВ лесу есть сосна: " << (forest.Treeest("Сосна") ? "Да" : "Нет") << endl;
    cout << "В лесу есть волк: " << (forest.animalest("Волк") ? "Да" : "Нет") << endl;

    return 0;
}