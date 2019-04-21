#ifndef ARRETE_H
#define ARRETE_H
#include "Sommet.h"


class Arrete
{
    public:
        Arrete();
        Arrete(Sommet S1, Sommet S2, float p1, float p2,int id);
        virtual ~Arrete();

        float getp1() const;
        float getp2() const;
        void setS1(Sommet S1);
        void setS2(Sommet S2);
        void setp1(float p1);
        void setp2(float p2);
        void affiche();
        Sommet gets2() {return m_S2;}
        int getID() {return m_id;}
        Sommet gets1() {return m_S1;}
        bool operator <(const Arrete& a) const;

    protected:

    private:

        Sommet m_S1;
        Sommet m_S2;
        float m_p1, m_p2;
        int m_id;



};

#endif // ARRETE_H
