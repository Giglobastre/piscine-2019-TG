#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <allegro.h>
#include "Sommet.h"
#include <string>
#include <sstream>
#include "Arrete.h"

class Graphe//:public Sommet
{
    public:
        Graphe();
        virtual ~Graphe();
        void remplissage(BITMAP *fond) const;
        void remplissage_arrete(BITMAP *fond) const;
        void remplissage_poids(BITMAP *fond) const;
        void remplissage_vectArrete();
        void affiche_vect();
        void affiche_tab();
        void affiche_poids();
        void kruskal();
        int getOrdre();
        void affiche_Arrete();
        std::vector<Arrete> getVectArrete();

    protected:

    private:
        std::vector<Sommet> m_Sommets;
        std::vector<int> m_Arrete;
        std::vector<Arrete> m_Arrete2;


        int m_ordre,m_taille, *sommets;
        Sommet *m_voisins_som[2][sizeof(m_Sommets)]; //new sommet... pr completer
        //int m_voisins_id[3][sizeof(m_Sommets)];
        //std::vector <std::vector<int>> m_voisins_id; //vect a 2 dim mais c mieux de lineariser
        std::vector <int>  m_voisins_id;
        std::vector <float> m_poids;
        int find(int i);
        void union1(int i, int j);
};

#endif // GRAPHE_H
