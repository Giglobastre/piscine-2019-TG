#include "Arrete.h"



/** constructeur de la classe Arrete
 *
 * \
 * \param
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

Arrete::Arrete()
{


}

/** Destructeur de la classe Arrete
 *
 * \
 * \param
 * \return
 *
 */
Arrete::~Arrete()
{
    //dtor
}

/** Fonction qui permet d'acceder au poids 1
 *
 * \param
 * \param
 * \return
 *
 */
float Arrete::getp1() const
{
    return m_p1;
}

/** Fonction qui permet d'acceder au poids 2
 *
 * \param
 * \param
 * \return
 *
 */
float Arrete::getp2() const
{
    return m_p2;
}

/** Fonction qui permet de modifier le sommet 1
 *
 * \sommet
 * \param
 * \return
 *
 */
void Arrete::setS1(Sommet S1)
{
    m_S1=S1;
}

/** Fonction qui permet de modifier le sommet 2
 *
 * \sommet
 * \param
 * \return
 *
 */
void Arrete::setS2(Sommet S2)
{
    m_S2=S2;
}

/** Fonction qui permet de modifier le poids 1
 *
 * \float
 * \param
 * \return
 *
 */
void Arrete::setp1(float p1)
{
    m_p1=p1;
}

/** Fonction qui permet de modifier le poids 2
 *
 * \param
 * \param
 * \return
 *
 */

void Arrete::setp2(float p2)
{
    m_p2=p2;
}

/** Fonction qui permet d'afficher le numero de l'arrete, ses sommets et ses poids
 *
 * \param
 * \param
 * \return
 *
 */

void Arrete::affiche()
{
   // std::cout<<"YOLO"<<std::endl;
    std::cout<<"id : "<<m_id<<std::endl;
    std::cout<<"sommet1 : "<<std::endl;
    m_S1.affiche();
    std::cout<<"sommet2 : "<<std::endl;
    m_S2.affiche();
    std::cout<<"poids 1 et 2 : "<<m_p1<<" ,"<<m_p2<<std::endl;
}


/** Fonction qui permet de comparer le poids
 *
 * \param
 * \param
 * \return
 *
 */
bool Arrete::operator <(const Arrete& a) const
{
    return this->m_p1 < a.getp1();
}
