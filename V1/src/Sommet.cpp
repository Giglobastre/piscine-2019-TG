#include "Sommet.h"

Sommet::Sommet(int id,int x,int y)
{
    m_est_marque=false;
    m_id=id;
    m_x=x;
    m_y=y;
}

Sommet::~Sommet()
{
    //dtor
}

void Sommet::affiche()
{
    std::cout<<m_id<<" "<<m_x<<" "<<m_y<<std::endl;
}
