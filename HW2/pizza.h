#include <iostream>


class Pizza{
public:
    friend class HawaiianPizzaBuilder;
    friend class SpicyPizzaBuilder;
    friend class HandPizzaBuilder;
    Pizza() { }
    ~Pizza() { }

    virtual void ShowPizza()=0;

    std::string getDough(){ return dough; }
    std::string getSauce(){ return sauce; }
    std::string getTopping(){ return topping; }

protected:

    std::string dough;
    std::string sauce;
    std::string topping;

    void SetDough(const std::string& d) { dough = d; }
    void SetSauce(const std::string& s) { sauce = s; }
    void SetTopping(const std::string& t) { topping = t; }
};

class RussianPizza : public Pizza{
public:
    RussianPizza() : Pizza() {}
    ~RussianPizza(){}

    void ShowPizza()
    {
        std::cout << "Pizza with Dough as " << dough
             << ", Sauce as " << sauce
             << " and Topping as " << topping
             << " !!! " << std::endl;
        std::cout << "Приятного аппетита!" << std::endl << std::endl;
    }


};

class FrenchPizza : public Pizza{
public:
    FrenchPizza() : Pizza() {}
    ~FrenchPizza(){}

    void ShowPizza()
    {
        std::cout << "Pizza with Dough as " << dough
             << ", Sauce as " << sauce
             << " and Topping as " << topping
             << " !!! " << std::endl;
        std::cout << "Bon appetit!" << std::endl << std::endl;
    }


};

class PizzaBuilder{
public:
    Pizza* pizza;

    PizzaBuilder(){}
    virtual ~PizzaBuilder(){}

    Pizza* getPizza() {
        return pizza;
    }
    void createNewPizzaProduct(const std::string &type) {
        if (type == "Moscow") pizza = new RussianPizza();
        if (type == "Paris") pizza = new FrenchPizza();
    }

    virtual void buildDough()=0;
    virtual void buildSauce()=0;
    virtual void buildTopping()=0;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() : PizzaBuilder() {}
    ~HawaiianPizzaBuilder(){}

    void buildDough() { pizza->SetDough("cross"); }
    void buildSauce() { pizza->SetSauce("mild"); }
    void buildTopping() { pizza->SetTopping("ham and pineapple"); }
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    SpicyPizzaBuilder() : PizzaBuilder() {}
    ~SpicyPizzaBuilder() {}

    void buildDough() { pizza->SetDough("pan baked"); }
    void buildSauce() { pizza->SetSauce("hot"); }
    void buildTopping() { pizza->SetTopping("pepperoni and salami"); }
};

class HandPizzaBuilder : public PizzaBuilder {
public:
    HandPizzaBuilder() : PizzaBuilder() {}
    ~HandPizzaBuilder(){}

    void buildDough() {
        std::string s;
        std::cout << "Which dough do you want?" << std::endl;
        std::cin >> s;
        pizza->SetDough(s);
    }
    void buildSauce() {
        std::string s;
        std::cout << "Which sause do you want?" << std::endl;
        std::cin >> s;
        pizza->SetSauce(s);
    }
    void buildTopping() {
        std::string s;
        std::cout << "Which topping do you want?" << std::endl;
        std::cin >> s;
        pizza->SetTopping(s);
    }
};
class Pizzeria {
public:
    std::string city;
    PizzaBuilder* pizzaBuilder;

    Pizzeria() {}
    virtual ~Pizzeria() {}

    void setPizzaBuilder(PizzaBuilder* b) {
        pizzaBuilder = b;
    }

    Pizza* getPizza(){
        return pizzaBuilder->getPizza();
    }

    void ConstructPizza(){
        pizzaBuilder->createNewPizzaProduct(city);
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildTopping();
        std::cout << "Pizza is cooking..." << std::endl;
    }
    void BakePizza(){
        std::cout << "Pizza is baking..." << std::endl;
    }
    void PackPizza(){
        std::cout << "Pizza is packing..." << std::endl;
    }

    virtual void setCity()=0;

    virtual std::string getInfo()=0;

    std::string getCity() {
        return city;
    }
};

class MoscowPizzeria : public Pizzeria {
public:
    RussianPizza* rp;

    MoscowPizzeria() : Pizzeria() {
        setCity();
    }

    ~MoscowPizzeria() {}

    void setCity() override {
        city = "Moscow";
    }

    std::string getInfo() {
        return "Вас приветствует пицца Москвы!\n";
    }
};

class ParisPizzeria : public Pizzeria {
public:
    FrenchPizza fp;

    ParisPizzeria() : Pizzeria() {
        setCity();
    }

    ~ParisPizzeria() {}

    void setCity() override {
        city = "Paris";
    }

    std::string getInfo() {
        return "Вас приветствует пицца Парижа!\n";
    }
};

class Factory {
public:
    static Pizzeria* create(std::string &type) {
        if (type == "Moscow")
            return new MoscowPizzeria();
        if (type == "Paris")
            return new ParisPizzeria();
    }
};

std::string getInfo(std::string &city) {
    Pizzeria* p;
    if (city == "Moscow")
        p = new MoscowPizzeria;
    if (city == "Paris")
        p = new ParisPizzeria;
    return p->getInfo();
}
