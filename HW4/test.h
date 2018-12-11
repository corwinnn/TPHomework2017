//
// Created by mike on 07.04.18.
//

#ifndef UNIVERSALCARD_TEST_H
#define UNIVERSALCARD_TEST_H
#include <gtest/gtest.h>
#include "Card.h"

TEST(init, first) {
    MyCard* card = new MyCard(5);
    int id = card->getId();
    EXPECT_EQ(5, id);
    Builder *b = new Builder(card);
    b->setName(3);
    EXPECT_EQ(3, card->getName());
    delete b;
    delete card;
}

TEST(init, second) {
    MyCard* card = new MyCard(10);
    Builder *b = new Builder(card);
    b->setName(7);
    b->setSurname(8);
    card->getInfo();
    EXPECT_EQ(7, card->getName());
    EXPECT_EQ(8, card->getSurname());
    EXPECT_EQ(10, card->getId());
    card->changeSurname(33);
    EXPECT_EQ(33, card->getSurname());
    delete card;
    delete b;
}

TEST(transfer, first){
    MyCard* card1 = new MyCard(10);
    Builder *b1 = new Builder(card1);
    MyCard* card2 = new MyCard(10);
    Builder *b2 = new Builder(card2);
    b1->setMoney(100);
    b2->setMoney(200);
    BankDecorator* bd = new BankDecorator(card1);
    bd->transfer(card2, 60);
    EXPECT_EQ(40, card1->getMoney());
    EXPECT_EQ(260, card2->getMoney());
    bd->transfer(card2, 60);
    EXPECT_EQ(40, card1->getMoney());
    EXPECT_EQ(260, card2->getMoney());
    delete card1;
    delete card2;
    delete b1;
    delete b2;
    delete bd;

}

TEST(insurance, newTime){
    MyCard* card = new MyCard(10);
    Builder *b = new Builder(card);
    b->setMoney(100);
    b->setTimeEnd(10);
    b->setDealNumber(3);
    EXPECT_EQ(3, card->getDealNumber());
    EXPECT_EQ(10, card->getTimeEnd());
    InsuranceDecorator* id = new InsuranceDecorator(card);
    id->setNewTime(15);
    EXPECT_EQ(15, card->getTimeEnd());
    EXPECT_EQ(95, card->getMoney());
    id->setNewTime(14);
    EXPECT_EQ(15, card->getTimeEnd());
    EXPECT_EQ(95, card->getMoney());
    id->setNewTime(1555);
    EXPECT_EQ(15, card->getTimeEnd());
    EXPECT_EQ(95, card->getMoney());

}



#endif //UNIVERSALCARD_TEST_H
