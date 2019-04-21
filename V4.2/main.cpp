#include <iostream>
#include "Sommet.h"
#include <vector>
#include <fstream>
#include "Graphe.h"
#include <allegro.h>

using namespace std;

/*#define HEIGHT 480*2
#define WIDTH 640*2*/
#define HEIGHT 768
#define WIDTH 1024

void ini_alleg()/**< routine d'initialisation allegro */
{
    allegro_init();
    set_display_switch_mode(SWITCH_BACKGROUND);
    install_keyboard();
    install_mouse();


    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WIDTH,HEIGHT,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


}

int main()
{
    //ini_alleg();
    //Graphe g;

    //BITMAP* fond;
    //fond=create_bitmap(WIDTH,HEIGHT);
    //int quit=0;
    /*while(quit!=4)
    {
        //menu
        cout<<"1 pr allegro 4 quit"<<endl;
        cin>>quit;
        switch(quit)
        {
        case 1:

            g.affiche_vect();
            cout<<"/////////////////////////"<<endl;
            g.affiche_tab();
            cout<<"/////////////////////////"<<endl;
            g.affiche_poids();
            cout<<"/////////////////////////"<<endl;
            cout<<"/////////vect"<<endl;
            g.remplissage_vectArrete();
            for(int i=0; i < g.getVectArrete().size(); i++) {
                    cout<<"HELLO"<<endl;
                g.getVectArrete()[i].affiche();
            }

            cout<<"KRUSKAL-------"<<endl;
            g.kruskal_prof();ini_alleg();
    //Graphe g;

    BITMAP* fond;
    fond=create_bitmap(WIDTH,HEIGHT);
            cout<<"FIN KRUSKAL-------"<<endl;

            while (!key[KEY_ESC])
            {
                show_mouse(fond);
                clear_bitmap(fond);
                g.remplissage(fond);
                g.remplissage_arrete(fond);
                g.remplissage_poids(fond);


                /// bruteforce
                g.bruteforce(fond);

                blit(fond,screen,0,0,0,0,WIDTH,HEIGHT);
            }

            break;

        case 4:
            return 0;
        }


    }*/

    ini_alleg();

    BITMAP* fond;
    fond=create_bitmap(WIDTH,HEIGHT);
    std::string graphe_,graphe_poids;
    int i=1;
          //Graphe g("broadway.txt","broadway_weights_0.txt");


    while(i!=0)
    {
        i://sortie du 2eme while

        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"saisir nom du graphe sous la forme ville.txt"<<endl;
        cin>>graphe_;
        cout<<"saisir nom du fichier de poids sous la forme ville_weights_x.txt"<<endl;
        cin>>graphe_poids;
        Graphe g(graphe_,graphe_poids);

        clear_bitmap(fond);

        g.remplissage(fond);
        g.remplissage_arrete(fond);
        g.remplissage_poids(fond);
        g.remplissage_vectArrete();
        g.bruteforce(fond);

        while (!key[KEY_ESC])
        {

            // cadres
            //        x1,y1,x2,y2
            rect(fond,0,718,100,768,makecol(255,255,255));
            rect(fond,0+100,718,100+100,768,makecol(255,255,255));
            rect(fond,0+200,718,100+200,768,makecol(255,255,255));
            rect(fond,0+300,718,100+300,768,makecol(255,255,255));
            rect(fond,0+400,718,100+400,768,makecol(255,255,255));
            rect(fond,0+500,718,100+500,768,makecol(255,255,255));
            rect(fond,0+600,718,100+600,768,makecol(255,255,255));

            //texte
            textprintf_centre_ex(fond,font,(0+100)/2,(718+768)/2,makecol(255,255,255),-1,"Choix graphe");
            textprintf_centre_ex(fond,font,(0+100+200)/2,(718+768)/2,makecol(255,255,255),-1,"Aff_vect");
            textprintf_centre_ex(fond,font,(0+100+400)/2,(718+768)/2,makecol(255,255,255),-1,"Aff_tab");
            textprintf_centre_ex(fond,font,(0+100+600)/2,(718+768)/2,makecol(255,255,255),-1,"Aff_poids");
            textprintf_centre_ex(fond,font,(0+100+800)/2,(718+768)/2,makecol(255,255,255),-1,"Aff_arrete");
            textprintf_centre_ex(fond,font,(0+100+1000)/2,(718+768)/2,makecol(255,255,255),-1,"Kruskal");
            textprintf_centre_ex(fond,font,(0+100+1200)/2,(718+768)/2,makecol(255,255,255),-1,"Quitter");

            //hitbox sur clic
            if(mouse_b & 1)
            {
                if(mouse_x>0 && mouse_x<100 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;

                    goto i;// pour sortir de la boucle

                }

                if(mouse_x>0+100 && mouse_x<100+100 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;
                    cout<<endl;
                    cout<<endl;
                    g.affiche_vect();
                }

                if(mouse_x>0+200 && mouse_x<100+200 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;
                    cout<<endl;
                    g.affiche_tab();
                }

                if(mouse_x>0+300 && mouse_x<100+300 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;
                    cout<<endl;
                    g.affiche_poids();
                }

                if(mouse_x>0+400 && mouse_x<100+400 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;

                    cout << "vecteur d'arretes "<<endl;
                    for(int i=0; i < g.getVectArrete().size(); i++)
                    {
                        g.getVectArrete()[i].affiche();
                    }
                }

                if(mouse_x>0+500 && mouse_x<100+500 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;
                    cout<<endl;
                    g.kruskal_prof();
                }

                if(mouse_x>0+600 && mouse_x<100+600 && mouse_y>718 && mouse_y<768)
                {
                    //reset de la position de la souris
                    mouse_x=0;
                    mouse_y=0;

                    return 0;
                }
            }

            show_mouse(fond);
            blit(fond,screen,0,0,0,0,WIDTH,HEIGHT);
        }
    }
}
END_OF_MAIN();
