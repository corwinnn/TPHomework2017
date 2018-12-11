//
// Created by Mike on 07.04.18.
//

#ifndef UNIVERSALCARD_CARD_H
#define UNIVERSALCARD_CARD_H


/**
@mainpage
 API для использования <b>паспорта-карты<b>
*/

#include <iostream>
using std::cout;
using std::endl;
/**
 * @class MyCard
 *  Ваш паспорт-карта. Обладает Вашей информацией. Имеет функции, оперирующие с Вашими персональными данными.
 *
 */
class MyCard{
public:
    friend class Builder;
    friend class BankDecorator;
    friend class InsuranceDecorator;
    explicit MyCard(int id){
        this->id = id;
    }
    /**
     *  Возвращает Ваш id
     */
    int getId() const {
        return id;
    }
    /**
     *  Возвращает Ваше имя
     */
    int getName() const {
        return name;
    }
    /**
     *  Печатает Ваши паспортные данные
     */
    void getInfo() {
        cout << "id: " << id << endl << "name: " << name << endl << "surname: " << surname << endl;
    }
    /**
     *  Возвращает Вашу фамилию
     */
    int getSurname() const {
        return surname;
    }
    /**
     *  Возвращает Ваш баланс
     */
    int getMoney() const {
        return money;
    }
    /**
     *  Возвращает Ваш номер карты
     */
    int getCardNumber() const {
        return cardNumber;
    }
    /**
     *  Возвращает Ваш срок страховки
     */
    int getTimeEnd() {
        return timeEnd;
    }
    /**
     *  Возвращает Ваш номер договора
     */
    int getDealNumber() {
        return dealNumber;
    }

    /**
     * Меняет Вашу фамилию на new
     * @param newS
     */
    void changeSurname(int newS) {
        surname = newS;
    }

private:
    //Passport
    int id;
    int name;
    int surname;

    //Bank Card
    int money;
    int cardNumber;

    //Insurance
    int dealNumber;
    int timeEnd;

};

/**
 * Заполняет поля класса MyCard
 */
class Builder {
public:
    MyCard* card;
    Builder(MyCard* card) {
        this->card = card;
    }
    void setName(int x) {
        card->name = x;
    }
    void setSurname(int x) {
        card->surname = x;
    }
    void setMoney(int x) {
        card->money = x;
    }
    void setCardNumber(int x) {
        card->cardNumber = x;
    }
    void setDealNumber(int x) {
        card->dealNumber = x;
    }
    void setTimeEnd(int x) {
        card->timeEnd = x;
    }




};

/**
 * Банковский декоратор, добавляет банковские функции
 */
class BankDecorator {
public:
    MyCard* card;
    BankDecorator(MyCard* card) {
        this->card = card;
    }

    /**
     * При наличии value $ переводит их на счет who
     * @param who
     * @param value
     */
    void transfer(MyCard* who, int value){
        if (value <= card->getMoney()) {
            card->money -= value;
            who->money += value;
            cout << "transfer done" << endl;
        }
        else {
            cout << "Few money" << endl;
        }
    }

};

/**
 * Страховой декоратор, добавляет страховые функции
 */
class InsuranceDecorator {
public:
    MyCard* card;
    InsuranceDecorator(MyCard* card) {
        this->card = card;
    }
    /**
     * продлевает срок страховки, при наличии средств (1$ за день)
     * @param newTime
     */
    void setNewTime(int newTime) {
        if (newTime - card->getTimeEnd() <= card->getMoney() && newTime > card->getTimeEnd()) {
            card->money -= (newTime - card->getTimeEnd());
            card->timeEnd = newTime;
        }

    }
};

#endif //UNIVERSALCARD_CARD_H

/*Вы разрабатываете ПО для обслуживания универсальной электронной карты: она
        имеет функции паспорта, страхового полиса, банковской карты и так далее на ваше
        усмотрение. Ваш заказчик хочет получить от вас библиотеку, написанную на С++, которая в
дальнейшем будет использована в считывателях таких универсальных карт. Таким образом,
        клиенту важно, чтобы вы предоставили простое и задокументированное API.
Задание необходимо выполнить с использованием пройденных структурных паттернов
        (порождающие на ваше усмотрение). Для сборки должен быть написан соответствующий
CMakeLists, который также генерирует doxygen-документацию.
Должна быть возможность собрать проект в следующих режимах:
- с тестами в debug режиме
- с тестами в release режиме
- без тестов в debug режиме
- без тестов в release режиме
        Также, обязательным требованием является соблюдение чистоты кода и следование
        выбранному codestyle. И помните о покрытии тестами. Заказчик хочет получить качественный
код!
*/