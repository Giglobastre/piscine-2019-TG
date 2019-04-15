#include <iostream>
#include "Sommet.h"
#include <vector>
#include <fstream>
#include "Graphe.h"-

using namespace std;

void rempl()
{
    std::ifstream ifs("graphe_1.txt", std::ios::in);
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        Sommet s{id,x,y};
        cout << id<<" "<<x<<" "<<y <<endl;
        s.affiche();
    }
}


int main()
{
    rempl();
    Graphe g;
    g.affiche_vect();
    return 0;
}
