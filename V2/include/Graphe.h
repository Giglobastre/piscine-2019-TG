#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <allegro.h>
#include "Sommet.h"

class Graphe//:public Sommet
{
    public:
        Graphe();
        virtual ~Graphe();
        void remplissage(BITMAP *fond) const;
        void remplissage_arrete(BITMAP * fond) const;
        void affiche_vect();
        void affiche_tab();
        int getOrdre();

    protected:

    private:
        std::vector<Sommet> m_Sommets;
        int m_ordre,m_taille;
        Sommet *m_voisins_som[2][sizeof(m_Sommets)]; //new sommet... pr completer
        //int m_voisins_id[3][sizeof(m_Sommets)];
        //std::vector <std::vector<int>> m_voisins_id; //vect a 2 dim mais c mieux de lineariser
        std::vector <int>  m_voisins_id;
};

#endif // GRAPHE_H
