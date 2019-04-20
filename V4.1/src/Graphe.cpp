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

        sommets = new int[m_ordre];
    }

    std::ifstream ifs2("broadway_weights_0.txt", std::ios::in);
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


/// KRUSKAL /////////////////////////////////////////////////////////////////////

// Cherche le sommet i;
int Graphe::trouver(int i)
{
    while(sommets[i] != i)
    {
        i = sommets[i];
    }
    return i;
}

void Graphe::assemblage(int i, int j)
{
    int a = trouver(i);
    int b = trouver(j);
    sommets[a] = b;
}


void Graphe::kruskal()
{
    int minpoids = 0; // poids minimum
    std::vector<bool> ar_set(m_Arrete2.size(),true);
    // Initialize sets of disjoint sets.
    for (int i = 0; i < m_ordre; i++)
      {
          sommets[i] = i;
      }

    // Include minimum weight edges one by one
    int compte_arrete = 0;

    // verif
    /*std::cout<<m_Arrete2[1].getp1();
    std::cout<<m_Arrete2[0].getp1();
    std::cout<<m_Arrete2[2].getp1();
    std::cout<<m_Arrete2[4].getp1();*/



    while (compte_arrete< m_ordre - 1) {
        float min_poids = INT_MAX;
        int a = -1, b = -1;
        for (int i = 0; i < m_taille; i++) {
                if (m_Arrete2[i].gets1().getID() != m_Arrete2[i].gets2().getID()
                    && m_Arrete2[i].getp1() < min_poids && ar_set[m_Arrete2[i].getID()]) {
                    min_poids = m_Arrete2[i].getp1();
                    a = m_Arrete2[i].gets1().getID();
                    b = m_Arrete2[i].gets2().getID();
                    ar_set[m_Arrete2[i].getID()] = false;
                }
        }
        assemblage(a, b);
        cout<<"Arrete "<< compte_arrete++ <<":("<<a<<", "<<b<<") cost:"<<min_poids<<"\n"<<endl;
        minpoids += min_poids;
    }
    cout<<"\n Poids minimum= "<<minpoids<<" \n"<<endl;
    m_poidskrusk=minpoids;
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
    for(i = 0; i < n; i++) // parcours de la solution
    {
        // Print if the corresponding value is '1'.
        if(code[i] == '1')
        {
            //cout<<arr[i]<<" ";
            taille++;
            solution.push_back(arr[i]);
        }

    }
    //cout<<"}\n";
    solution.push_back(-1);
    return(taille);
    //return solution;
}

// A function to generate subset by binary counting.
int Graphe::BinaryCounting(vector <vector <int>> &filtree, int arr[], int n)
{
    int r, i, l, taille, taille_filtre = 0;
    vector <int> solution;
    char binary[32] = "0000000000000000000000000000000"; // int max
    r = pow(2, n);
    for(i = 0; i < r; i++)
    {
        taille = print(solution, binary, arr, n, 1);/// affichage des solutions + recuperation
        if(taille == m_ordre - 1)/// //////////////////////////////////////////////////////////////////////pour mettre = ou superieur au nb de sol min
        {
            taille_filtre++;

            filtree.push_back(solution);
        }
        l=n-1;

        // Incrementing the binary value with each iteration.
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

void Graphe::bruteforce(BITMAP* fond)
{
    int p = 0, k, i, n, taille, add;
    float poid = 0, poid1 = 0, poid2 = 0;// i parmi n , n le nb de combinaison totale
    vector<vector<int>> filtre1,tmp,filtre_som,solution_finale;
    vector<int> /*list_sommet,*/ selection;
    vector <float> poids1, poids2, poids;
    n=m_taille;
    i=m_ordre-1;

    int arr[n];
    cout<<"\n";

    for(int z=0;z<m_ordre;z++)
    {
        //list_sommet.push_back(z);
        selection.push_back(0);
    }
    // Take the input of the array.
    for(i = 0; i < n; i++)
    {
        arr[i]=i;
    }
    //taille =(BinaryCounting(filtre1, arr, n,0,0));
    taille = BinaryCounting(filtre1, arr, n);
    for(k=0; k<taille ; k++)
    {
        //cout<<"solu "<<k <<"\t";
        for(int j = 0; filtre1[k][j] > -1; j++)
        {
            //m_voisins_id[filtre1[k][j]*3];
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

    //cout << "moyenne des pds"<<endl;
    for(int i=0;i<p;i++)
    {
        //for(int j = 0; solution_finale[i][j] > -1; j++)
          //  cout<<solution_finale[i][j]<<"\t";
        //cout<<endl<<poids1[i] <<"\t";
        //cout<<poids2[i] <<"\t";
        //cout<<poids[i] <<endl;
        affichept(fond,poids1[i],poids2[i]);

    }
}

void Graphe::affichept(BITMAP* fond,float p1, float p2)
{
    line(fond,600,400,600,100,makecol(255,255,255));//axe
    line(fond,600,100,1000,100,makecol(255,255,255));//axe
    circlefill(fond,p1*100+600,p2*100+100,1,makecol(255,0,0));//modif ici les valeurs pour modifier l'ecartement et positionement des pts

    cout << m_poidskrusk << " edede " << m_poidskrusk+(5%m_poidskrusk)<<endl;
    cout << m_poidskrusk << " edede " << m_poidskrusk+(0.05*m_poidskrusk)<<endl;
    if((p1+p2)>=m_poidskrusk && (p1+p2)<=(m_poidskrusk+(0.05*m_poidskrusk)))
       {
           circlefill(fond,p1*100+600,p2*100+100,1,makecol(0,255,0));
       }
}


