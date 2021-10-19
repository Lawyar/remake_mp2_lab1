#include "tset.h"

TSet::TSet(int max_power)
{
    BitField = TBitField(max_power);
    MaxPower = max_power;
}

// конструктор копирования
TSet::TSet(const TSet &s)
{
    BitField = s.BitField;
    MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf)
{
    TSet(bf.GetLength());
}

TSet::operator TBitField()
{
    return (TBitField)*this;
}

int TSet::GetMaxPower() const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if(Elem < 0 || Elem >= MaxPower)
    {
        throw std::logic_error("INCORRECT ELEMENT");
    }
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if(Elem < 0 || Elem >= MaxPower)
    {
        throw std::logic_error("INCORRECT ELEMENT");
    }
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if(Elem < 0 || Elem >= MaxPower)
    {
        throw std::logic_error("INCORRECT ELEMENT");
    }
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    if (this != &s)
    {
        MaxPower = s.GetMaxPower();
        BitField = s.BitField;
    }
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return (BitField != s.BitField);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    int len = MaxPower;
    if (s.MaxPower > MaxPower)
    {
        len = s.MaxPower;
    }
    TSet temp(len);

    temp.BitField = BitField | s.BitField;
    return temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem < 0 || Elem >= MaxPower)
    {
        throw std::logic_error("INCORRECT ELEMENT");
    }

    BitField.SetBit(Elem);
    return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem < 0 || Elem >= MaxPower)
    {
        throw std::logic_error("INCORRECT ELEMENT");
    }

    BitField.ClrBit(Elem);
    return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    int len = MaxPower;
    if (s.MaxPower > MaxPower)
    {
        len = s.MaxPower;
    }
    TSet temp(len);
    temp = BitField & s.BitField;
    return temp;
}

TSet TSet::operator~() // дополнение
{
    BitField = ~BitField;
    return *this;
}