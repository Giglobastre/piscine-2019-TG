#include "Sommet.h"

/** \brief Constructeur de la classe Sommet
 *
 * \param : int id
 * \param : int x
 * \param : int y
 *
 */

Sommet::Sommet(int id,int x,int y)
{
    m_est_marque=false;
    m_id=id;
    m_x=x;
    m_y=y;
}

/** \brief Constructeur par défaut de la classe Sommet
 *
 *
 */
Sommet::Sommet()
{
    m_est_marque=false;
    m_id=0;
    m_x=0;
    m_y=0;
}

Sommet::~Sommet()
{
    //dtor
}

/** \brief Fonction qui affiche le numéro du sommet et ses coordonnées.
 *
 *
 */
void Sommet::affiche()
{
    std::cout<<m_id<<" "<<m_x<<" "<<m_y<<std::endl;
}

/** \brief Fonction qui modifie le boolean "est marqué".
 *
 * \param : bool est marqué
 */
void Sommet::setmarque(bool estmarque)
{
    m_est_marque = estmarque;

}

/** \brief Fonction qui permet d'acceder à la coordonée d'abscisse du sommet
 *
 *
 * \return int m_x
 *
 */

int Sommet::getX() const
{
    return m_x;
}

/** \brief Fonction qui permet d'acceder à la coordonée d'ordonnée du sommet
 *
 *
 * \return int m_y
 *
 */
int Sommet::getY() const
{
    return m_y;
}

/** \brief Fonction qui permet d'acceder au numéro du sommet
 *
 *
 * \return int m_id
 *
 */
int Sommet::getID() const
{
    return m_id;
}
