#include "Arrete.h"

Arrete::Arrete(Sommet S1, Sommet S2, int p1, int p2, int id)
{
   m_S1=S1;
   m_S2=S2;
   m_p1=p1;
   m_p2=p2;
   m_id=id;

}

Arrete::~Arrete()
{
    //dtor
}

void Arrete::setS1(Sommet S1)
{
    m_S1=S1;
}
void Arrete::setS2(Sommet S2)
{
    m_S2=S2;
}
void Arrete::setp1(int p1)
{
    m_p1=p1;
}
void Arrete::setp2(int p2)
{
    m_p2=p2;
}
void Arrete::affiche()
{
    std::cout<<"id : "<<m_id<<std::endl;
    std::cout<<"sommet1 : "<<std::endl;
    m_S1.affiche();
    std::cout<<"sommet2 : "<<std::endl;
    m_S2.affiche();
    std::cout<<"poids 1 et 2 "<<m_p1<<" ; "<<m_p2<<std::endl;
}
