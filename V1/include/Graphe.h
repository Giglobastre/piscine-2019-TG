#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <fstream>

#include "Sommet.h"

class Graphe//:public Sommet
{
    public:
        Graphe();
        virtual ~Graphe();
        void remplissage();
        void affiche_vect();

    protected:

    private:
        std::vector<Sommet> m_Sommets;
        int m_ordre,m_taille;
};

#endif // GRAPHE_H
