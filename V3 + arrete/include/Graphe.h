#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <allegro.h>
#include "Sommet.h"
#include <string>
#include <sstream>
#include <algorithm>

class Graphe//:public Sommet
{
    public:
        Graphe();
        virtual ~Graphe();
        void remplissage(BITMAP *fond) const;
        void remplissage_arrete(BITMAP *fond) const;
        void remplissage_poids(BITMAP *fond) const;
        void affiche_vect();
        void affiche_tab();
        void affiche_poids();
        void Kruskal();
        int getOrdre();
        std::vector <int>  m_voisins_id;// narrete s1 s2 ....
        std::vector <float> m_poids;// narrette p1 p2....
        std::vector<Sommet> m_Sommets;//id x y ....
        int m_ordre,m_taille;
    protected:

    private:


        Sommet *m_voisins_som[2][sizeof(m_Sommets)]; //new sommet... pr completer
        //int m_voisins_id[3][sizeof(m_Sommets)];
        //std::vector <std::vector<int>> m_voisins_id; //vect a 2 dim mais c mieux de lineariser

};

#endif // GRAPHE_H
