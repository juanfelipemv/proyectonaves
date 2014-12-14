#include <allegro.h>
#include "inicia.h"

const int maxdisp = 5 , ANCHO = 500, ALTO = 450;

void juego();
void pintar_nave(BITMAP *nave,BITMAP *buffer,struct NAVE nav);

struct NAVE{
    int x,y;
    int dir;
    int ndisparos;
}nav = {250,300,1,0};

struct Balas{
    int x,y;
    int dx,dy; //incrementos de las variables  x,y

}disparos[maxdisp];

void cargarInstruccion()
{
    while(!key[KEY_ESC]){
                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("instruccion.tga",NULL);
                        blit(menu,buffer,0,0,0,0,500,450);
                        blit(buffer,screen,0,0,0,0,500,450);
                        rest(5);
                        if(key[KEY_BACKSPACE]) {
                        break;
                        }

                         }

}

void juego()
{
    BITMAP *nave = load_bitmap("nave.bmp",NULL);
    BITMAP *nube = load_tga("Galaxy2.tga",NULL);
     BITMAP *asteroide = load_bitmap("asteroid.bmp",NULL);
    BITMAP *bala = load_bitmap("Bala2.bmp", NULL);  // otra cosa
    BITMAP *buffer = create_bitmap(500,450);

    int i = 450 , dsw = 0 , contt = 0;
    while(!key[KEY_ESC]){
        blit(nube,buffer,0,--i,0,0,500,450);  if(i == 0) i=450;
        pintar_nave(nave,buffer,nav);
        if(nav.x>0 && nav.x<450){
       if(key[KEY_UP])        { nav.dir = 1; nav.y -= 1; }
       else if(key[KEY_DOWN]) { nav.dir = 1; nav.y += 2; }
       if(key[KEY_RIGHT])     { nav.dir = 2; nav.x += 1; }
       else if(key[KEY_LEFT]) { nav.dir = 0; nav.x -= 1; }
       else nav.dir = 1;
        }else if(nav.x>=450){
        nav.x=nav.x-5;
        }else if(nav.x<=0){
        nav.x=nav.x+5;
        }
       ///rutina disparos///

       if(key[KEY_SPACE]&&dsw==0){
            if(nav.ndisparos<maxdisp){
                nav.ndisparos++;
                disparos[nav.ndisparos].x = nav.x + 20;
                disparos[nav.ndisparos].y = nav.y;
                disparos[nav.ndisparos].dx = 0;
                disparos[nav.ndisparos].dy = -3;
                dsw = 1;

            }


       }

        if(contt++ >20){
                dsw=0;
                contt=0;
            }


       if(nav.ndisparos>0){
        for(int cont=1;cont<=nav.ndisparos;cont++){
            disparos[cont].x += disparos[cont].dx;
            disparos[cont].y += disparos[cont].dy;
            masked_blit(bala,buffer,0,0, disparos[cont].x,disparos[cont].y,4,7);

            if(disparos[cont].y>ALTO || disparos[cont].y <0 ||
                disparos[cont].x>ANCHO || disparos[cont].x<0){

                    disparos[cont]=disparos[nav.ndisparos];
                    nav.ndisparos--;
                    if(nav.ndisparos<0){
                        nav.ndisparos =0;
                    }
                }
        }

       }

       blit(buffer,screen,0,0,0,0,500,450);
       rest(5);

    }

    destroy_bitmap(buffer);
    destroy_bitmap(nave);
    destroy_bitmap(nube);







}



void cargarVictoria()
{

    while(!key[KEY_ESC]){
                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("win.tga",NULL);
                        blit(menu,buffer,0,0,0,0,500,450);
                        blit(buffer,screen,0,0,0,0,500,450);
                        rest(5);


                         }

}

void cargarGameover()
{
    while(!key[KEY_ESC]){
                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("gameover.tga",NULL);
                        blit(menu,buffer,0,0,0,0,500,450);
                        blit(buffer,screen,0,0,0,0,500,450);
                        rest(5);
                         }

}



void pintar_nave(BITMAP *nave,BITMAP *buffer,struct NAVE nav){
     masked_blit( nave, buffer, 40*nav.dir, 0, nav.x, nav.y, 40, 47);

}



int main()
{
     inicia_allegro(500,450);
    inicia_audio(70,70);


    //menu
     while(!key[KEY_ESC]){
                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("menu3.tga",NULL);
                        blit(menu,buffer,0,0,0,0,500,450);
                        blit(buffer,screen,0,0,0,0,500,450);
                        rest(5);

                         if(key[KEY_2]) {
                        cargarInstruccion();
                        }
                         if(key[KEY_1]) {
                        juego();
                        }
                         if(key[KEY_4]) {

                       return 0;
                        }
                        }


}
END_OF_MAIN();

