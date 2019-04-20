#include <iostream>
#include "Sommet.h"
#include <vector>
#include <fstream>
#include "Graphe.h"
#include <allegro.h>

using namespace std;

/*#define HEIGHT 480*2
#define WIDTH 640*2*/
#define HEIGHT 576
#define WIDTH 720

void ini_alleg()///routine d'initialisation allegro
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
    ini_alleg();
    Graphe g;

    BITMAP* fond;
    fond=create_bitmap(WIDTH,HEIGHT);
    int quit=0;
    cout<<"test"<<endl;
    while(quit!=4)
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
            g.kruskal_prof();
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


    }
    return 0;
}
END_OF_MAIN();
