#include "Graphe.h"

using namespace std;


/** \brief constructeur de la classe Graphe
 *\param string nomfichier
 *\param string nomfichierpoids
 *
 * lecture des fichiers et remplissage des vecteurs
 */
Graphe::Graphe(string nomfichier, string nomfichierpoids)
{
    std::ifstream ifs(nomfichier, std::ios::in);
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

        sommets = new int[m_ordre];
    }

    std::ifstream ifs2(nomfichierpoids, std::ios::in);
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


/** \brief destructeur de la classe Arrete
 *
 */
Graphe::~Graphe()
{
    //dtor
}

/** \brief fonction qui permet de dessiner des cercles qui representent les sommets
 *
 * \param BITMAP *fond
 *
 */
void Graphe::remplissage(BITMAP *fond) const
{
    int x,y,id;
    for(int i=0; i<m_ordre; i++)
    {
        x=m_Sommets[i].getX() ;
        y=m_Sommets[i].getY();
        id=m_Sommets[i].getID();
        circlefill(fond,x,y,10,makecol(255,255,255)); /**< cette ligne permet de dessiner les cercles representant les sommets sur la bitmap */
    }
}

/** \brief dessine les arretes sur la BITMAP
 *
 * \param  : BITMAP *fond
 *
 */
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


/** \brief affiche le poids des arretes sur la bitmap
 *
 * \param : BITMAP *fond
 *
 */
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
        sstr<< p1 <<" ; "<<p2; /**<  concatenation des poids */
        x=(x1+x2)/2;
        y=(y1+y2)/2;/**< x et y dont le mileu de l'arrete */

        string str=sstr.str();/**< transformation du sstream en string */
        const char *c=str.c_str();/**< transformation du string en char pour la prise en charge allegro */
        textout_centre_ex(fond,font,c,x,y,makecol(255,255,255),-1);
    }
}


/** \brief fonction qui affiche le vecteur sommet
 *
 *
 */
void Graphe::affiche_vect()
{
    cout << "Liste des sommets\n";
    for(int i=0; i<m_ordre; i++)
    {
        m_Sommets[i].affiche();
    }

}


/** \brief fonction qui affiche les Arretes du graphe
 *
 */
void Graphe::affiche_tab()
{
    int i=0;
    cout << "Liste des arretes" <<endl;
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



/** \brief fonction qui affiche les poids des arretes
 *
 *
 */
void Graphe::affiche_poids()
{
    int i=0;
    cout <<endl<< "Liste des poids " <<endl;
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

/** \brief renvoie un entier i
 *
 * \
 * \param  : int i
 * \return : int i
 *
 */
int Graphe::trouver(int i)
{
    while(sommets[i] != i)
    {
        i = sommets[i];
    }
    return i;
}

/** \brief renvoie un entier i
 *
 * \
 * \param  : int i
 * \return : int i
 *
 */
void Graphe::assemblage(int i, int j)
{
    int a = trouver(i);
    int b = trouver(j);
    sommets[a] = b;
}


/** \brief fonction qui affiche l'arbre couvrant de poids minimum en fonction du poids : Kruskal
 *
 *
 */
void Graphe::kruskal()
{
    int minpoids = 0; // poids minimum
    //std::vector<bool> ar_set(m_Arrete2.size(),true);
    // Initialize sets of disjoint sets.
    for (int i = 0; i < m_ordre; i++)
      {
          sommets[i] = i;
      }

    // Include minimum weight edges one by one
    int compte_arrete = 0;
//    std::cout<<m_Arrete2[1].getp1();
//    std::cout<<m_Arrete2[0].getp1();
//    std::cout<<m_Arrete2[2].getp1();
//    std::cout<<m_Arrete2[4].getp1();



    while (compte_arrete < m_ordre - 1)
        {
        float min_poids = INT_MAX;
        int a = -1, b = -1;
        //cout<<m_taille<<m_Arrete2.size()<<endl;
        for (int i = 0; i < m_ordre; i++)
        {
            for(int j = 0; j < m_ordre; j++) {


                /*if (m_Arrete2[i].gets1().getID() != m_Arrete2[i].gets2().getID()
                    && m_Arrete2[i].getp1() < min_poids ) //&& ar_set[m_Arrete2[i].getID()]*/
                if (trouver(i) != trouver(j) && m_Arrete2[i].getp1() < min_poids)
                {
                    //cout<<"H1"<<endl;
                    min_poids = m_Arrete2[i].getp1();
                    //cout<<"H2"<<endl;
                    a = m_Arrete2[i].gets1().getID();
                    //cout<<"H3"<<endl;
                    b = m_Arrete2[i].gets2().getID();
                    //cout<<"H4"<<endl;
                    //ar_set[m_Arrete2[i].getID()] = false;
                    //cout<<"H5"<<endl;
                }
            }
        }
        assemblage(a, b);

        cout<<"Arrete "<< compte_arrete++ <<":("<<a<<", "<<b<<") cost:"<<min_poids<<"\n"<<endl;

        minpoids += min_poids;

    }

    cout<<"\n Poids minimum= "<<minpoids<<" \n"<<endl;
}


/** \brief Fonction qui permet d'acceder au nombre de sommets du graphe ( ordre )
 *
 * \return int m_ordre
 */
int Graphe::getOrdre()
{

    return m_ordre;
}

/** \brief Fonction qui permet d'acceder au vecteur m_Arrete2
 *
 * \return std::vector<Arrete> m_Arrete2
 */
std::vector<Arrete> Graphe::getVectArrete()
{
    return m_Arrete2;
}

/////////////////////////////////////////ARRETE///////////////////////////////////////////////////////////:


/** \brief Fonction qui permet de remplir le vecteur m_Arrete2 avec les arretes du graphes
 *
 *
 */
void Graphe::remplissage_vectArrete()
{
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

        //m_s[ns1].affiche();
        //m_Sommets[ns2].affiche();
        ///  cout<<p1<<" "<<p2<<" "<<id_a<<endl;
        ///m_Arrete2.push_back(Arrete{S1,S2,p1,p2,id_a});
        m_Arrete2.push_back(Arrete{m_Sommets[ns1],m_Sommets[ns2],p1,p2,id_a});
    }

}



/// ALGO DE COMPTAGE /////////////////////////////////////////////////////////////////////

/**
* algorithme de comptage binaire pour enumeration des solutions
* source : https://www.sanfoundry.com/cpp-program-generate-subsets-using-binary-counting/
*
*/

int Graphe::print(vector <int> &solution, char code[], int arr[], int n, int k)
{
    int i,taille=0;
    //vector<int> solution;
    //cout<<"{ ";
    for(i = 0; i < n; i++) /**< parcours de la solution */
    {

        if(code[i] == '1')
        {
            taille++;
            solution.push_back(arr[i]);
        }

    }
    //cout<<"}\n";
    solution.push_back(-1);
    return(taille);/**< return solution */

}

/** \brief fonction qui génère les sous ensembles par comptage binaire.
 *
 * \param : vector <vector <int>> &filtree
 * \param : int arr[]
 * \param : int n
 * \return  int taille_filtre
 *
 */
int Graphe::BinaryCounting(vector <vector <int>> &filtree, int arr[], int n)
{
    int r, i, l, taille, taille_filtre = 0;
    vector <int> solution;
    char binary[32] = "0000000000000000000000000000000"; // int max
    r = pow(2, n);
    for(i = 0; i < r; i++)
    {
        taille = print(solution, binary, arr, n, 1); /**< affichage des solutions + recuperation */
        if(taille == m_ordre - 1) /**< pour mettre = ou superieur au nb de sol  */
        {
            taille_filtre++;

            filtree.push_back(solution);
        }
        l=n-1;

        /**< incremente les valeurs en bnaires avec chaque itération. */
        h:
        if(binary[l] == '0')
            binary[l] = '1';
        else
        {
            binary[l] = '0';
            l--;
            goto h;
        }
        solution.clear();
    }
    cout<<"nb de solutions trouvees : "<<i<<endl;
    return taille_filtre;
}



/** procédure qui affiche l'énumeration des solutions viables pour les arbres couvrants
 *
 * \param : BITMAP* fond
 *
 */
void Graphe::bruteforce(BITMAP* fond)
{
    int p = 0, k, i, n, taille, add;
    float poid = 0, poid1 = 0, poid2 = 0;
    vector<vector<int>> filtre1,tmp,filtre_som,solution_finale;
    vector<int> /*list_sommet,*/ selection;
    vector <float> poids1, poids2, poids;
    n=m_taille;
    i=m_ordre-1;

    int arr[n];
    cout<<"\n";

    for(int z=0;z<m_ordre;z++)
    {

        selection.push_back(0);
    }

    for(i = 0; i < n; i++)
    {
        arr[i]=i;
    }

    taille = BinaryCounting(filtre1, arr, n);
    for(k=0; k<taille ; k++)
    {

        for(int j = 0; filtre1[k][j] > -1; j++)
        {
            selection[m_voisins_id[filtre1[k][j]*3 + 1]] = 1;
            selection[m_voisins_id[filtre1[k][j]*3 + 2]] = 1;
        }
        for (i = 0; i < m_ordre; i++)
        {
            if (selection[i] == 0)
                break ;
        }
        if (i == m_ordre)
        {
            p++;
            solution_finale.push_back(filtre1[k]);
        }

        for(i = 0; i < m_ordre; i++)
        {
            selection[i] = 0;
        }
    }

    cout<<"solution viable "<<p <<"\t";

    for(k=0; k<p ; k++)
    {
        poid = 0.0;
        poid1 = 0.0;
        poid2 = 0.0;
        add = 0;
        for(int j = 0; solution_finale[k][j] > -1; j++)
        {
            poid1 += m_poids[solution_finale[k][j]*3+1];
            poid2 += m_poids[solution_finale[k][j]*3+2];
            poid = poid1 + poid2;
            add += 1;
        }
        poids1.push_back(poid1 / add);
        poids2.push_back(poid2 / add);
        poids.push_back(poid / (add*2));
    }


    for(int i=0;i<p;i++)
    {
        affichept(fond,poids1[i],poids2[i]);
    }


    /// ///////////////////////////////////////////
    int s1,s2,cpt=0,cpt2=0,cpt3=0,tmp2;
vector<vector<int>> solution_finale2;
vector<int>connex;
    //solution_finale2.resize(10000);

    for(int i=0; i<p; i++)
    {
        cpt2=0;
        for(int ik=0; ik<m_ordre; ik++) /**< remplissage du tableau de 0 a m_ordre */
        {
            connex.push_back(ik);
        }
        for(int j=0; j<m_ordre-1; j++)
        {
            tmp2=connex[m_Arrete2[solution_finale[i][j]].gets1().getID()];
            s1=m_Arrete2[solution_finale[i][j]].gets1().getID();
            s2=m_Arrete2[solution_finale[i][j]].gets2().getID();
            connex[s1]=connex[s2];
            for(int z=0; z<m_ordre; z++)
            {
                if(connex[z]==tmp2)
                {
                    //connex[z]=s2;
                    connex[z]=connex[s2];
                }
            }
        }

        /// stockage
        for(int o=0; o<m_ordre-1; o++)
        {
            if(connex[o]==connex[o+1])
                cpt2++;
        }
        if(cpt2==m_ordre-1)// si toute les cases soont egales on push la solution
        {
            //compte le nb de solution valide pr remplir le vecteur
            cpt++; //nombre de solutions connexe
                solution_finale2.push_back(solution_finale[i]);

                //cout<< solution_finale2[i][k] << " ";
            cpt3++;
        }
    }
    /// /aff des derniere solutions
    cout<<endl<< "solutions viables apres deuxieme filtrage " <<cpt<<endl;

    /// ////////////////////////////////////////////
}

/** \brief
 *
 * \param : BITMAP* fond
 * \param : float p1
 * \param : float p2
 *
 */
void Graphe::affichept(BITMAP* fond,float p1, float p2)
{
    line(fond,500,400,500,100,makecol(255,255,255));
    line(fond,500,100,1000,100,makecol(255,255,255));
    circlefill(fond,p1*100+200,p2*100-150,1,makecol(255,0,0));
}



/** \brief : Foonction qui affiche l'arbre couvrant de poids minimum en fonction du poids : Kruskal
 *
 * \return : vector<Arrete> : arbre
 *
 * source : cours Mr.fercoq
 *
 *
 */
vector<Arrete> Graphe::kruskal_prof()
{

    cout<<"--->> Kruskal:"<<endl;
    // Variables locales


    vector<Arrete> tmp_mArrete2;
    vector<Arrete> arbre; /**< tableau d’arêtes de poids minimum à retourner */
    arbre.reserve(m_taille);
    int connexe[m_ordre]; /**< tableau dynamique des numéros de sommets connexes de l’arbre */
    int indiceA = 0, indiceG = 0; /**< indices de l’arbre et du graphe initialisés à 0 */
    int x, s1, s2; /**< numéros de sommets intermédiaires */
    Arrete u; /**< arête reliant 2 sommets x1 et x2 */
    // Allouer l’arbre de « ordre - 1 » arêtes
    //…
    // Allouer le tableau connexe de « ordre » sommets
    //…
    // Initialiser les connexités indicées sur les numéros de sommets
    for (x=0 ; x < m_ordre ; x++)
        connexe[x] = x ;
    // Trier le graphe par ordre croissant des poids de ses « n » arêtes
    for (x=0 ; x < m_taille ; x++)
        tmp_mArrete2.push_back(m_Arrete2[x]);
    sort(tmp_mArrete2.begin(), tmp_mArrete2.end());

    while (indiceA < m_ordre - 1 && indiceG < m_taille) /**< tant que les arêtes de l’arbre et du graphe ne sont pas toutes traitées */
    {
        u = tmp_mArrete2[indiceG]; /**< retourne l’arête u numéro indiceG du graphe */
        s1 = connexe[u.gets1().getID()];
        s2 = connexe[u.gets2().getID()]; // les sommets s1, s2 de l’arête u
        /**< Teste si les sommets s1 et s2 de l’arête u forment un cycle dans l’arbre */
        if (s1 == s2)
        {
            indiceG++ ; /**< passe à l’arête suivante du graphe */
        }
        else
        {

            arbre[indiceA] = u ; /**< insére l’arrête u à la position « indiceA » de l’arbre */
            indiceA++ ;
            indiceG++ ; /**< passe à l’arête suivante de l’arbre et du graphe */

            for (x=0 ; x < m_ordre ; x++)
            {
                if (connexe[x] == s1)
                {
                    connexe[x] = s2 ;
                }
            }/**< Indique que les sommets s1 et s2 sont connexes */

        }
    }

    if (indiceA < m_ordre - 1) /**< Le graphe est non connexe si le nombre d’arêtes de l’arbre < nombre de sommets-1 */
    {
        cout<<"Le graphe n'est pas connexe\n"<<endl;
    }
    for (x=0 ; x < m_ordre-1 ; x++)
    {
        arbre[x].affiche();
    }

    return arbre; /**< retourner l’arbre de poids minimum */
}
