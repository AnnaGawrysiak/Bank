// w banku mozemy byc zwyklym klientem lub VIP. zwyklu klient moze wyplacac gotowke tyle ile ma
// kazdt klient moze wplacac
// VIP moze z debetem 2000 wypalcic. ma oprocentowanie na ten debet
// niektorzy klienci maja lepsze oprocentowanie VIP VIP

#include <iostream>

using namespace std;

class Klient
{
 private:

    int saldo;

 public:

    Klient ()
    { // konstruktor domyœlny
      saldo = 1000;
    }

    Klient (int saldo_)
    {
        saldo = saldo_;
    }

    void set_saldo(int &saldo_)
    {
        saldo = saldo_;
    }

    get_saldo()
    {
        return saldo;
    }

    virtual int wplac(int wplata)
    {
       return saldo + wplata;
    }

    virtual int wyplac(int wyplata) // ile wyplacamy
    {
        if (wyplata > saldo)
        return saldo;

        else
            return wyplata;
    }

    virtual ~Klient(){};

};

class VIP : public Klient
{
 private:

    int saldo;

    float oprocentowanie;

 public:


    VIP() : Klient()
    { // konstruktor domyœlny
      saldo = 1000;
      oprocentowanie = 0.08;
    };

    virtual ~VIP(){};

     virtual void set_saldo(int& saldo_)
     {
         saldo = saldo_;
     }

     virtual float get_saldo()
     {
         return saldo; // BUZIACZEK :)
     }

    virtual float nalicz_oprocentowanie(float debet)
    {
        return debet * oprocentowanie;
    };

     virtual int wyplac(int wyplata) override // ile wyplacamy
    {
        if (wyplata > get_saldo()+2000)
        return get_saldo() +2000;

        else
            return wyplata;
    }

};

class Extra_VIP : public  VIP
{
 private:

    int saldo;

    float oprocentowanie;

public:

    Extra_VIP() : VIP()
    { // konstruktor domyœlny
      saldo = 100000;
      oprocentowanie = 0.06;
    };

    virtual ~Extra_VIP(){};

    void set_saldo(int& saldo_)
    {
        saldo = saldo_;
    }

    float get_saldo()
    {
        return saldo;
    }

    float nalicz_oprocentowanie(float debet)
    {
        return debet * oprocentowanie;
    }; // ewentualne zrob getter

    int wyplac(int wyplata) override
    {
        if (wyplata > (saldo + 2000))
            return saldo + 2000;

        else
            return wyplata;
    }

};


int main()
{
Klient nowy_klient;

Klient* wsk_nowy_klient = &nowy_klient;

VIP bogaty;

Klient* wsk_bogaty = &bogaty;

Extra_VIP obrzydliwie_bogaty;

Klient* wsk_obrzydliwie_bogaty = &obrzydliwie_bogaty;

Klient* zestaw_klientow [3];

zestaw_klientow[0] = wsk_nowy_klient;

zestaw_klientow[1] = wsk_bogaty;

zestaw_klientow[2] = wsk_obrzydliwie_bogaty;

int wyplata = 1100;

for (int i = 0; i < 3; i++)
    {
       cout << zestaw_klientow[i]->wyplac(wyplata) << endl;
    }

    return 0;
}
