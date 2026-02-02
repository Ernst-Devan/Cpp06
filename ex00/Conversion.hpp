#ifndef CONVERSION_HPP
#define CONVERSION_HPP

class Conversion
{
    private:
        int     type_;
        char    c_;
        int     i_;
        float   f_;
        double  d_;
    public:
        Conversion();
        Conversion(Conversion const& c);
        Conversion& operator=(Conversion const& c);
        ~Conversion();

        void    setType(int val);
        void    setC(char val);
        void    setI(int val);
        void    setF(float val);
        void    setD(double val);

        int     getType() const;
        char    getC() const;
        int     getI() const;
        float   getF() const;
        double  getD() const;
};

#endif
