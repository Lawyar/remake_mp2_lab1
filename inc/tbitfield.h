#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TBitField
{
private:

    vector<char> vec_mem;

public:
    explicit TBitField(int len = 1);                           //+
    TBitField(const TBitField &bf);               //+

    // доступ к битам
    int GetLength() const;                        //+   получить длину (к-во битов)
    void SetBit(int pos);                   //+   установить бит
    void ClrBit(int pos);                   //+   очистить бит
    int  GetBit(int pos) const;             //+   получить значение бита

    void set_number10(ulong number10);            //+
    void set_string2(string str2);                //+

    ulong to_ulong10();                           //+
    string to_string2();                          //+

    bool operator==(const TBitField &bf) const;   //+
    bool operator!=(const TBitField &bf) const;   //+
    TBitField& operator=(const TBitField &bf);    //+
    TBitField  operator|(const TBitField &bf);    //+   операция "или"
    TBitField  operator&(const TBitField &bf);    //+   операция "и"
    TBitField  operator~();                       //+   отрицание
    TBitField operator>>(int n);                  //+
    TBitField operator<<(int n);                  //+

    void print();                                 //+

};

#endif