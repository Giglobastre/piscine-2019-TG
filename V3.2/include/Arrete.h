#ifndef ARRETE_H
#define ARRETE_H
#include "Sommet.h"


class Arrete
{
    public:
        Arrete(Sommet S1, Sommet S2, int p1, int p2,int id);
        virtual ~Arrete();

        void setS1(Sommet S1);
        void setS2(Sommet S2);
        void setp1(int p1);
        void setp2(int p2);
        void affiche();

    protected:

    private:

        Sommet m_S1;
        Sommet m_S2;
        int m_p1, m_p2,m_id;


};

#endif // ARRETE_H
