#include "Arrete.h"



/** constructeur de la classe Arrete
 *
 * \param : Sommet S1
 * \param : Sommet S2
 * \param : float p1
 * \param : float p2
 * \param : int id
 * \return
 *
 */
Arrete::Arrete(Sommet S1, Sommet S2, float p1, float p2, int id)
{
   m_S1=S1;
   m_S2=S2;
   m_p1=p1;
   m_p2=p2;
   m_id=id;

}

/** constructeur par defaut de la classe Arrete
 */
Arrete::Arrete()
{


}

/** Destructeur de la classe Arrete
 */
Arrete::~Arrete()
{
    //dtor
}

/** Fonction qui permet d'acceder au poids 1
 *
 * \return float m_p1
 *
 */
float Arrete::getp1() const
{
    return m_p1;
}

/** Fonction qui permet d'acceder au poids 2
 *
 * \return  float m_p2
 *
 */
float Arrete::getp2() const
{
    return m_p2;
}

/** Fonction qui permet de modifier le sommet 1
 *
 * \param : sommet S1
 */
void Arrete::setS1(Sommet S1)
{
    m_S1=S1;
}

/** Fonction qui permet de modifier le sommet 2
 *
 * \param : sommet S2
 *
 */
void Arrete::setS2(Sommet S2)
{
    m_S2=S2;
}

/** Fonction qui permet de modifier le poids 1
 *
 * \param : float p1
 *
 */
void Arrete::setp1(float p1)
{
    m_p1=p1;
}

/** Fonction qui permet de modifier le poids 2
 *
 * \param : float p2
 */

void Arrete::setp2(float p2)
{
    m_p2=p2;
}

/** Procédure qui permet d'afficher le numero de l'arrete, ses sommets et ses poids
 *
 *
 */

void Arrete::affiche()
{
    std::cout<<std::endl;
   // std::cout<<"YOLO"<<std::endl;
    std::cout<<"id : "<<m_id<<std::endl;
    std::cout<<"sommet1 : ";
    m_S1.affiche();
    std::cout<<std::endl;
    std::cout<<"sommet2 : ";
    m_S2.affiche();
    std::cout<<std::endl;
    std::cout<<"poids 1 et 2 : "<<m_p1<<" , "<<m_p2<<std::endl;
}


/** Fonction operator
 *
 * \param : const Arrete& a
 * \return comparaison
 *
 */
bool Arrete::operator <(const Arrete& a) const
{
    return this->m_p1 < a.getp1();
}
