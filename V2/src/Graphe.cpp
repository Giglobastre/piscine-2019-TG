#include "Graphe.h"
using namespace std;


Graphe::Graphe()
{
    std::ifstream ifs("manhattan.txt", std::ios::in);
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x,y;
    //lecture des sommets
    for (int i=0; i<m_ordre; ++i)
    {
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture donn�es sommet");
        ifs>>x;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture donn�es sommet");
        ifs>>y;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture donn�es sommet");

        m_Sommets.push_back(Sommet{id,x,y});
    }
    std::cout << "lecture sommets terminee" << std::endl;


    int numarrete;
    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;

    //lecture des aretes
    for (int i=0; i<m_taille; ++i)
    {
        //lecture numarrete
        ifs>>numarrete;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture numarrete");
        //lecture des ids des deux extr�mit�s
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extr�mit� � la liste des voisins de l'autre (graphe non orient�)
        /*(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orient�*/
                //m_voisins_som[i][j] = new Sommet{id};//tableau de sommet jsp si utile

        m_voisins_id.push_back(numarrete);//tableau de id, pour faire les arretes on vas chercher ds le vecteur de sommet les coord
        m_voisins_id.push_back(id);//tableau de id, pour faire les arretes on vas chercher ds le vecteur de sommet les coord

        id=stoi(id_voisin); //string to int
        m_voisins_id.push_back(id);


    }
}

Graphe::~Graphe()
{
    //dtor
}


void Graphe::remplissage(BITMAP *fond) const
{
    int x,y,id;
    for(int i=0; i<m_ordre; i++)
    {
        x=m_Sommets[i].getX() ;
        y=m_Sommets[i].getY();
        id=m_Sommets[i].getID();
        circlefill(fond,x,y,10,makecol(255,255,255));
    }
}

void Graphe::remplissage_arrete(BITMAP *fond) const
{
    int narrete;
    int x1,y1,x2,y2;
    for(int i=0; i<m_taille*3; i+=3)
    {
        narrete=m_voisins_id[i];

        for(int k=0; k<m_ordre; k++)
        {
            if(m_Sommets[k].getID()==m_voisins_id[i+1])
            {
                x1=m_Sommets[k].getX();
                y1=m_Sommets[k].getY();
                break;
            }
        }
            for(int k=0; k<m_ordre; k++)
            {
                if(m_Sommets[k].getID()==m_voisins_id[i+2])
                {
                    x2=m_Sommets[k].getX();
                    y2=m_Sommets[k].getY();
                    break;
                }
            }

        cout << endl;
        cout<<"--------------"<<endl;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        line(fond,x1,y1,x2,y2,makecol(255,255,255));
    }
}

void Graphe::affiche_vect()
{
    for(int i=0; i<m_ordre; i++)
    {
        m_Sommets[i].affiche();
    }

}

void Graphe::affiche_tab()
{
    int i=0;
    cout << "voisins " <<endl;
    for(int j=0;j<m_taille*3;j++)
    {
        if(i==3){
            cout<<endl;
            i=0;
        }
        i++;
        cout<<m_voisins_id[j]<<" ";
        //j++;
    }
}

int Graphe::getOrdre()
{
    return m_ordre;
}



