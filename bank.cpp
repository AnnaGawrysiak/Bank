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
    { // konstruktor domyslny
      saldo = 1000;
    }

    Klient (int saldo_)
    {
        saldo = saldo_;
    }

    virtual void set_saldo(int &saldo_)
    {
        saldo = saldo_;
    }

    virtual int get_saldo()
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

    VIP(int saldo_) : Klient(saldo_)
    { // konstruktor domyslny
      saldo = saldo_;
      oprocentowanie = 0.08;
    };

    virtual ~VIP(){};

    int get_saldo() override
    {
        return saldo;
    }

     virtual void set_saldo(int& saldo_)
     {
         saldo = saldo_;
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
    { // konstruktor domyslny
      saldo = 100000;
      oprocentowanie = 0.06;
    };

    Extra_VIP(int saldo_, float oprocentowanie_) : VIP(saldo_)
    { // konstruktor domyslny
      saldo = saldo_;
      oprocentowanie = oprocentowanie_;
    };

    virtual ~Extra_VIP(){};

    int get_saldo() override
    {
        return saldo;
    }

    void set_saldo(int& saldo_)
    {
        saldo = saldo_;
    }

    float nalicz_oprocentowanie(float debet)
    {
        return debet * oprocentowanie;
    }; // ewentualne zrob getter


};


int main()
{
/*Klient nowy_klient;

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
*/

Klient* zestaw_klientow [3];

zestaw_klientow[0] = new Klient(1000);

zestaw_klientow[1] = new VIP(2000);

zestaw_klientow[2] = new Extra_VIP(90, 0.09);

int wyplata = 5000;

for (int i = 0; i < 3; i++)
    {
       cout << zestaw_klientow[i]->wyplac(wyplata) << endl;
    }

    return 0;
}
