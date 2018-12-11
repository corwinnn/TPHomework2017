#include <gtest/gtest.h>
#include "pizza.h"
TEST(TestCase, TestName) {
    std::string reference_str = "Вас приветствует пицца Парижа!\n";
    std::string result = getInfo("Paris");
    EXPECT_EQ(reference_str, result);
}

TEST(Moscow, Hawaiian) {
    Pizzeria *mp = Factory::create("Moscow");
    std::cout << mp->getInfo();
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    mp->setPizzaBuilder(&hawaiianPizzaBuilder);
    mp->ConstructPizza();
    mp->BakePizza();
    mp->PackPizza();
    Pizza *pizza = mp->getPizza();
    pizza->ShowPizza();
    std::string s1 = "cross";
    std::string s2 = "mild";
    std::string s3 = "ham and pineapple";
    EXPECT_EQ(s1, pizza->getDough());
    EXPECT_EQ(s2, pizza->getSauce());
    EXPECT_EQ(s3, pizza->getTopping());
    delete mp;
}

TEST(Moscow, Spicy) {
    Pizzeria *mp = Factory::create("Moscow");
    std::cout << mp->getInfo();
    SpicyPizzaBuilder spicyPizzaBuilder;
    mp->setPizzaBuilder(&spicyPizzaBuilder);
    mp->ConstructPizza();
    mp->BakePizza();
    mp->PackPizza();
    Pizza* pizza = mp->getPizza();
    pizza->ShowPizza();
    std::string s1 = "pan baked";
    std::string s2 = "hot";
    std::string s3 = "pepperoni and salami";
    EXPECT_EQ(s1, pizza->getDough());
    EXPECT_EQ(s2, pizza->getSauce());
    EXPECT_EQ(s3, pizza->getTopping());
    delete mp;
}
TEST(Paris, hawaiian) {
    Pizzeria *pp = Factory::create("Paris");
    std::cout << pp->getInfo();
    HandPizzaBuilder handPizzaBuilder;
    pp->setPizzaBuilder(&handPizzaBuilder);
    pp->ConstructPizza();
    pp->BakePizza();
    pp->PackPizza();
    Pizza* pizza = pp->getPizza();
    pizza->ShowPizza();
    std::string s1 = "cross";
    std::string s2 = "mild";
    std::string s3 = "ham and pineapple";
    EXPECT_EQ(s1, pizza->getDough());
    EXPECT_EQ(s2, pizza->getSauce());
    EXPECT_EQ(s3, pizza->getTopping());
    delete pp;
}
