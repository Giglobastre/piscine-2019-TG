#include "Graphe.h"
using namespace std;


Graphe::Graphe()
{
    std::ifstream ifs("graphe_1.txt", std::ios::in);
    int m_ordre;
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x,y;
    //lecture des sommets
    for (int i=0; i<m_ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        //m_Sommets[i]={Sommet{id,x,y}};

        cout << "--------------"<<endl;
        cout << id<<" "<<x<<" "<<y <<endl;
        cout << "--------------"<<endl;
        //m_Sommets[i]={id,Sommet{id,x,y}};
        m_Sommets.push_back(Sommet{id,x,y});//={id,x,y};
    }
    std::cout << "lecture sommets terminée" << std::endl;
/*
    int m_taille;
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    //lecture des aretes
    for (int i=0; i<m_taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
    }*/
}

Graphe::~Graphe()
{
    //dtor
}

void Graphe::remplissage()
{
    /*std::ifstream graphe("graphe_1.txt", std::ios::in);
    int i=0;
    char recup;
        if(graphe)
        {
            getline(graphe,recup);
            m_ordre=atoi(recup);
            while(graphe.eof()!=true)
            {

                m_graphe[i]=recup;
            }
            graphe.close();
        }*/

}


void Graphe::affiche_vect()
{
    for(int i=0;i<sizeof(m_Sommets);i++)
    {
        cout<< "ssssssssssssssssssss"<<endl;
        m_Sommets[i].affiche();
    }

}





