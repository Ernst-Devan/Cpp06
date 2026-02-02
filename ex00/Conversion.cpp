#include "Conversion.hpp"

Conversion::Conversion() :
type_(-1), c_('\0'), i_(0), f_(0.0f), d_(0.0)
{};

Conversion::Conversion(Conversion const& c) :
type_(c.type_), c_(c.c_), i_(c.i_), f_(c.f_), d_(c.d_)
{};

Conversion& Conversion::operator=(Conversion const& c)
{
    if (&c == this)
        return (*this);
    type_ = c.type_;
    c_ = c.c_;
    i_ = c.i_;
    f_ = c.f_;
    d_ = c.d_;
    return (*this);
}

Conversion::~Conversion() {};

void Conversion::setType(int val)
{
    type_ = val;
}

void Conversion::setC(char val)
{
    c_ = val;
}

void Conversion::setI(int val)
{
    i_ = val;
}

void Conversion::setF(float val)
{
    f_ = val;
}

void Conversion::setD(double val)
{
    d_ = val;
}

int Conversion::getType() const
{
    return (type_);
}

char Conversion::getC() const
{
    return (c_);
}

int Conversion::getI() const
{
    return (i_);
}

float Conversion::getF() const
{
    return (f_);
}

double Conversion::getD() const
{
    return (d_);
}
