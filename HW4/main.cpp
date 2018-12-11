//
// Created by Mike on 07.04.18.
//

#include "Card.h"
using std::cin;
int main() {
    MyCard *Mike = new MyCard(0);
    Builder *b = new Builder(Mike);
    b->setName(0);
    b->setSurname(0);
    b->setMoney(0);
    b->setCardNumber(0);
    b->setDealNumber(0);
    b->setTimeEnd(0);
    MyCard *you = new MyCard(1);
    Builder *b2 = new Builder(you);
    int name, surname;
    cout << "Say the name" << endl;
    cin >> name;
    cout << "Say the surname" << endl;
    cin >> surname;
    b2->setSurname(surname);
    b2->setName(name);
    you->getInfo();
    b2->setCardNumber(1003);
    b2->setMoney(100);
    cout << "If you want to give me 1$, say '1', else '0'" << endl;
    int ans;
    cin >> ans;
    if (ans == 1) {
        BankDecorator *bd = new BankDecorator(you);
        bd->transfer(Mike, 1);
        delete bd;
    }
    cout << "If you want to prolong your insurance om 1 day, say '1', else '0'" << endl;
    cin >> ans;
    if (ans == 1) {
        InsuranceDecorator *id = new InsuranceDecorator(you);
        id->setNewTime(1);
        delete id;
    }
    cout << "Money: " << you->getMoney() << endl;
    delete Mike;
    delete you;
}

