#ifndef __SET_H__
#define __SET_H__

#include "tbitfield.h"

class TSet
{
private:
    int MaxPower;                         // максимальная мощность множества
    TBitField BitField;                   // битовое поле для хранения характеристического вектора
public:
    TSet(int max_power);
    TSet(const TSet &s);                  // конструктор копирования
    TSet(const TBitField &bf);            // конструктор преобразования типа
    operator TBitField();                 // преобразование типа к битовому полю
    // доступ к битам
    int GetMaxPower() const;          // максимальная мощность множества
    void InsElem(int Elem);         // включить элемент в множество
    void DelElem(int Elem);         // удалить элемент из множества
    int IsMember(int Elem) const;   // проверить наличие элемента в множестве
    // теоретико-множественные операции
    int operator== (const TSet &s) const; // сравнение
    int operator!= (const TSet &s) const; // сравнение
    TSet& operator=(const TSet &s);       // присваивание
    TSet operator+ (int Elem);      // объединение с элементом
    // элемент должен быть из того же универса
    TSet operator- (int Elem);      // разность с элементом
    // элемент должен быть из того же универса
    TSet operator+ (const TSet &s);       // объединение
    TSet operator* (const TSet &s);       // пересечение
    TSet operator~ ();                // дополнение

};
#endif