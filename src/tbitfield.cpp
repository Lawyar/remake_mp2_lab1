#include "tbitfield.h"


TBitField::TBitField(int len)
{
    if(len <= 0)
    {
        throw std::logic_error("LENGTH SHOULD BE GREATER THAN ZERO");
    }
    vec_mem.resize(len);
    for(auto &it : vec_mem)
    {
        it = '0';
    }
}

TBitField::TBitField(const TBitField &bf)
{
    vec_mem = bf.vec_mem;
}

int TBitField::GetLength() const
{
    return vec_mem.size();
}

void TBitField::SetBit(const int pos)
{
    if(pos < 0 || pos >= vec_mem.size())
    {
        throw std::logic_error("INCORRECT POSITION");
    }
    vec_mem[pos] = '1';
}

void TBitField::ClrBit(const int pos)
{
    if(pos < 0 || pos >= vec_mem.size())
    {
        throw std::logic_error("INCORRECT POSITION");
    }
    vec_mem[pos] = '0';
}

int TBitField::GetBit(const int pos) const
{
    if(pos < 0 || pos >= vec_mem.size())
    {
        throw "ANY";
    }
    return vec_mem[pos] - '0';
}

void TBitField::set_number10(ulong number10)
{
    if(number10 > INT32_MAX)
    {
        vec_mem.resize(64, '0');
    }
    else if(number10 > INT16_MAX)
    {
        vec_mem.resize(32, '0');
    }
    else if(number10 > INT8_MAX)
    {
        vec_mem.resize(16, '0');
    }
    else
    {
        vec_mem.resize(8, '0');
    }
    for(auto it = vec_mem.rbegin(); it != vec_mem.rend(), number10 > 0; it++)
    {
        *it = number10 % 2 + '0';
        number10 /= 2;
    }
}

void TBitField::set_string2(string str2)
{
    vec_mem.resize(str2.length());
    for(auto &it : vec_mem)
    {
        it = '0';
    }
    for(int i = 0; i < str2.length(); i++)
    {
        vec_mem[i] = str2[i];
    }
}


ulong TBitField::to_ulong10()
{
    int dvoika = 1;
    ulong res = 0;
    for(auto it = vec_mem.rbegin(); it != vec_mem.rend(); it++)
    {
        res = res + dvoika * (*(it) - '0');
        dvoika *= 2;
    }
    return res;
}

string TBitField::to_string2()
{
    std::string res;

    for(int i = 0; i < vec_mem.size(); i++)
    {
        res.push_back(vec_mem[i]);
    }
    return res;
}
TBitField& TBitField::operator=(const TBitField &bf)
{
    vec_mem = bf.vec_mem;

    return *this;
}

bool TBitField::operator==(const TBitField &bf) const
{
    if(vec_mem == bf.vec_mem)
    {
        return true;
    }
    return false;
}

bool TBitField::operator!=(const TBitField &bf) const
{
    if(vec_mem == bf.vec_mem)
    {
        return false;
    }
    return true;
}

TBitField TBitField::operator|(const TBitField &bf)
{
    int maxsize = 0;
    if(this->GetLength() > bf.GetLength())
    {
        maxsize = this->GetLength();
    }
    else
    {
        maxsize = bf.GetLength();
    }
    TBitField tmpbit(bf);
    TBitField ress(maxsize);
    ulong tmp = this->to_ulong10() | tmpbit.to_ulong10();
    ress.set_number10(tmp);

    return ress;
}

TBitField TBitField::operator&(const TBitField &bf)
{
    int maxsize = 0;
    if(this->GetLength() > bf.GetLength())
    {
        maxsize = this->GetLength();
    }
    else
    {
        maxsize = bf.GetLength();
    }
    TBitField tmpbit(bf);
    TBitField ress(maxsize);
    ulong tmp = this->to_ulong10() & tmpbit.to_ulong10();
    ress.set_number10(tmp);
    return ress;
}

TBitField TBitField::operator~()
{
    for(auto &it : vec_mem)
    {
        if(it == '0')
        {
            it = '1';
        }
        else
        {
            it = '0';
        }
    }
    return *this;
}

TBitField TBitField::operator>>(int n)
{
    for(int i = 0; i < n; i++)
    {
        vec_mem[i] = '0';
    }
    return *this;
}

TBitField TBitField::operator<<(int n)
{
    for(int i = 0; i < n; i++)
    {
        vec_mem.push_back('0');
        vec_mem.erase(vec_mem.begin());
    }
    return *this;
}

void TBitField::print()
{
    for(auto it : vec_mem)
    {
        cout << it << " ";
    }
    cout << "\n";
}

