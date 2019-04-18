#ifndef Arrete_H
#define Arrete_H

#include <vector>
#include <fstream>
#include <iostream>
#include <allegro.h>
#include "Sommet.h"
#include <string>
#include <sstream>
#include <algorithm>
#include "Graphe.h"

class Arrete :public Graphe
{
    public:
        Arrete(Sommet S1,Sommet S2, int P1, int P2);
        void SetP1(int P1);
        void SetP2(int P2);
        void SetS1(Sommet S1);
        void SetS2(Sommet S2);
        void remplissageA();
        virtual ~Arrete();

    protected:

    private:
        std::vector<Arrete> m_Arrete;
        Sommet m_S1;
        Sommet m_S2;
        int m_P1;
        int m_P2;
};

#endif // Arrete_H
