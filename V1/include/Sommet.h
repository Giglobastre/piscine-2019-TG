#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <vector>


class Sommet
{
    public:
        Sommet(int id,int x,int y);
        virtual ~Sommet();
        void affiche();

    protected:

    private:
        bool m_est_marque;
        int m_id;
        int m_x;
        int m_y;

};

#endif // SOMMET_H
