#include <iostream>
#include <math.h>

using namespace std;

class triunghi
{
    double l1,l2,l3;
    bool dreptunghic();
    bool isoscel();
    bool echilateral();
public:
    triunghi()
    {
        l1=0;
        l2=0;
        l3=0;
    }
    triunghi(double x,double y=0,double z=0)
    {
        l1=x;
        l2=y;
        l3=z;
    }
    bool verificare();
    string tip();
    double perimetru();
    double arie();
};
bool triunghi::verificare()
{
    if((l1+l2)<=l3)
        return true;
    if((l1+l3)<=l2)
        return true;
    if((l2+l3)<=l1)
        return true;
    return false;
}
bool triunghi::echilateral()
{
    if((l1==l2)==l3)
        return true;
    return false;
}
bool triunghi::isoscel()
{
    if(l1==l2)
        return true;
    if(l2==l3)
        return true;
    if(l1==l3)
        return true;
    return false;
}
bool triunghi::dreptunghic()
{
    if((l1*l1)+(l2*l2)==(l3*l3))
        return true;
    if((l3*l3)+(l2*l2)==(l1*l1))
        return true;
    if((l1*l1)+(l3*l3)==(l2*l2))
        return true;
    return false;
}
string triunghi::tip()
{
    if(this->echilateral())
        return "echilateral";
    if(this->isoscel())
    {
        if(this->dreptunghic())
            return "dreptunghic isoscel";
        else return "isoscel";
    }
    if(this->dreptunghic())
        return "dreptunghic";
    return "oarecare";
}
double triunghi::perimetru()
{
    return l1+l2+l3;
}
double triunghi::arie()
{
    if(this->dreptunghic())
    {
        if(l1>l2)
        {
            if(l2>l3)
            {
                cout<<l1;
                return (l2*l3)/2;
            }
            else
                if(l3>l1)
                {
                    cout<<l3;
                    return (l1*l2)/2;
                }

        }
        else
            if(l2>l3)
            {
                cout<<l2;
                return (l1*l3)/2;
            }
            else {cout<<l3; return (l1*l2)/2; }
    }
    if(this->echilateral())
    return (l1*l1*sqrt(3))/4;
    double p;
    p=this->perimetru()/2;
    return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}

class dreptunghi
{
    double l,L;

public:
    dreptunghi()
    {
        l=0;
        L=0;
    }
    dreptunghi(double x,double y=0)
    {
        l=x;
        L=y;
    }
    double perimetru()
    {
        return (2*(L+l));
    }
    bool patrat()
    {
        if(l==L)
            return true;
        else return false;
    }
    double arie()
    {
        return l*L;
    }
};

class prisma
{
    protected:
    double h;
public:
    prisma()
    {
        h=0;
    }
    prisma(double x)
    {
        h=x;
    }
    virtual double volum()=0;
    virtual double aria_l()=0;
    virtual double aria_t()=0;
};
class p_dreptunghi:public prisma,public dreptunghi
{
public:
    p_dreptunghi():prisma(),dreptunghi() { }
    p_dreptunghi(double x,double y=0,double z=0):prisma(x),dreptunghi(y,z){ }
    double aria_l()
    {
        return perimetru()*h;
    }
    double aria_t()
    {
        double y=aria_l();
        double z=2*arie();
        return y+z;
    }
    double volum()
    {
        return arie()*h;
    }
};
class p_triunghi:public prisma,public triunghi
{
public:
    p_triunghi():prisma(),triunghi(){}
    p_triunghi(double w,double x,double y,double z):prisma(w),triunghi(x, y, z){ }
    double aria_l()
    {
        return perimetru()*h;
    }
    double aria_t()
    {
        double y=aria_l();
        double z=2*arie();
        return y+z;
    }
    double volum()
    {
        return arie()*h;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
