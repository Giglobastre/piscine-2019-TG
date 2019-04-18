#include "Arrete.h"
#include "Sommet.h"

using namespace std;

Arrete::Arrete(Sommet S1,Sommet S2, int P1, int P2)
{
    S1=m_S1;
    S2=m_S2;
    P1=m_P1;
    P2=m_P2;

    //ctor
}

Arrete::~Arrete()
{
    //dtor
}

void Arrete::SetP1(int P1)
{
    int i;
    m_P1=m_poids[i];

}

void Arrete::SetP2(int P2)
{
    int i;
    m_P2=m_poids[i];

}
void Arrete::SetS1(Sommet S1)
{
    int i;
    m_S1=m_voisins_id[i];

}
void Arrete::SetS2(Sommet S2)
{
    int i;
    m_S2=m_voisins_id[i];

}
void Arrete::remplissageA()
{
    for (int i=1;i<m_taille*3;i+=3)
    {
        m_Arrete.push_back(Arrete(m_voisins_id[i],m_voisins_id[i+1],m_poids[i],m_poids[i+1]));

    }

    std::cout << m_Arrete <<std::end1;
}
