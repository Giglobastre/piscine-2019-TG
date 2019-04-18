#include "Sommet.h"

Sommet::Sommet(int id,int x,int y)
{
    m_est_marque=false;
    m_id=id;
    m_x=x;
    m_y=y;
}
Sommet::Sommet()
{
    m_est_marque=false;
    m_id=0;
    m_x=0;
    m_y=0;
}
Sommet::Sommet(int id)
{
    m_id=id; // if m_x==NULL ?
}

Sommet::~Sommet()
{
    //dtor
}

void Sommet::affiche()
{
    std::cout<<m_id<<" "<<m_x<<" "<<m_y<<std::endl;
}

int Sommet::getX() const
{
    return m_x;
}

int Sommet::getY() const
{
    return m_y;
}

int Sommet::getID() const
{
    return m_id;
}
