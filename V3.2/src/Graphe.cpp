#include "Graphe.h"

using namespace std;


Graphe::Graphe()
{
    std::ifstream ifs("broadway.txt", std::ios::in);
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
            throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");

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
        //lecture des ids des deux extrémités
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        /*(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté*/
        //m_voisins_som[i][j] = new Sommet{id};//tableau de sommet jsp si utile

        m_voisins_id.push_back(numarrete);//tableau de id, pour faire les arretes on vas chercher ds le vecteur de sommet les coord
        m_voisins_id.push_back(id);//tableau de id, pour faire les arretes on vas chercher ds le vecteur de sommet les coord

        id=stoi(id_voisin); //string to int
        m_voisins_id.push_back(id);


    }

    std::ifstream ifs2("Broadway_weights_0.txt", std::ios::in);
    int taille,nbpoids,id2;
    float p1,p2;
    ifs2>>taille;
    ifs2>>nbpoids;

    for(int k=0; k<taille; k++)
    {
        ifs2>>id2;
        ifs2>>p1;
        ifs2>>p2;
        m_poids.push_back(id2);
        m_poids.push_back(p1);
        m_poids.push_back(p2);
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

void Graphe::remplissage_poids(BITMAP *fond) const
{
    int narrete,tmp;
    int x1,y1,x2,y2,x,y;
    float p1,p2;
    for(int i=0; i<m_taille*3; i+=3)
    {
        narrete=m_voisins_id[i];
        tmp=m_poids[i];

        for(int k=0; k<m_ordre; k++)
        {
            if(m_Sommets[k].getID()==m_voisins_id[i+1])
            {
                x1=m_Sommets[k].getX();
                y1=m_Sommets[k].getY();
                p1=m_poids[i+1];
                break;

            }
        }
        for(int k=0; k<m_ordre; k++)
        {
            if(m_Sommets[k].getID()==m_voisins_id[i+2])
            {
                x2=m_Sommets[k].getX();
                y2=m_Sommets[k].getY();
                p2=m_poids[i+2];
                break;
            }
        }

        stringstream sstr;
        sstr<< p1 <<" ; "<<p2; // concatenation des poids
        //x et y dont le mileu de l'arrete
        x=(x1+x2)/2;
        y=(y1+y2)/2;

        string str=sstr.str();//transformation du sstream en string
        const char *c=str.c_str();//transformation du string en char pour la prise en charge allegro
        textout_centre_ex(fond,font,c,x,y,makecol(255,255,255),-1);
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
    cout << "Arretes " <<endl;
    for(int j=0; j<m_taille*3; j++)
    {
        if(i==3)
        {
            cout<<endl;
            i=0;
        }
        i++;
        cout<<m_voisins_id[j]<<" ";
        //j++;
    }
}

void Graphe::affiche_poids()
{
    int i=0;
    cout <<endl<< "Poids " <<endl;
    for(int j=0; j<m_taille*3; j++)
    {
        if(i==3)
        {
            cout<<endl;
            i=0;
        }
        i++;
        cout<<m_poids[j]<<" ";
        //j++;
    }
}


void Graphe::kruskal()
{

}

int Graphe::getOrdre()
{

    return m_ordre;
}

std::vector<Arrete> Graphe::getVectArrete()
{
    return m_Arrete2;
}

/////////////////////////////////////////ARRETE///////////////////////////////////////////////////////////:


void Graphe::remplissage_vectArrete()
{
    //int p1,p2,id,x,y,id2,x2,y2,k,id_a;


    int ns1,ns2,id_a;
    float p1,p2;


    for(int i=0; i<m_taille*3; i+=3)
    {
        id_a=m_voisins_id[i];
        ns1=m_voisins_id[i+1];
        ns2=m_voisins_id[i+2];
        p1=m_poids[i+1];
        p2=m_poids[i+2];

        //Sommet S1(id,x,y), S2(id2,x2,y2);

        //m_Sommets[ns1].affiche();
        //m_Sommets[ns2].affiche();
      ///  cout<<p1<<" "<<p2<<" "<<id_a<<endl;
        ///m_Arrete2.push_back(Arrete{S1,S2,p1,p2,id_a});
        m_Arrete2.push_back(Arrete{m_Sommets[ns1],m_Sommets[ns2],p1,p2,id_a});
    }

}




