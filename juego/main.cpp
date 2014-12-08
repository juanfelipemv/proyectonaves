#include <allegro.h>
#include "inicia.h"




volatile int speed_counter = 0;
struct NAVE{
    int x,y;
    int dir;
}nav = {250,300,1};

void pintar_nave(BITMAP *nave,BITMAP *buffer,struct NAVE nav){
     masked_blit( nave, buffer, 40*nav.dir, 0, nav.x, nav.y, 40, 47);

}
void inc_speed_counter()
{
    speed_counter++;
}
END_OF_FUNCTION(inc_speed_conuter)
int main()
{
    inicia_allegro(500,450);
    inicia_audio(70,70);

    BITMAP *nave = load_bitmap("nave.bmp",NULL);
    BITMAP *nube = load_tga("Galaxy2.tga",NULL);
    BITMAP *bala = load_bitmap("Bala2.bmp", NULL);  // otra cosa
    BITMAP *buffer = create_bitmap(500,450);

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(inc_speed_counter);

    install_int_ex(inc_speed_counter, BPS_TO_TIMER(30));

    int i = 450 , dsw = 0 , cont = 0;
    while(!key[KEY_ESC]){
        blit(nube,buffer,0,--i,0,0,500,450);
        if(i == 0)
        i=450;
        pintar_nave(nave,buffer,nav);

       if(key[KEY_UP]){
       nav.dir = 1;
       nav.y -= 1;
       }
       else if(key[KEY_DOWN]) {
       nav.dir = 1;
       nav.y += 2;
       }
       if(key[KEY_RIGHT]){
       nav.dir = 2;
       nav.x += 1;
       }
       else if(key[KEY_LEFT]){
       nav.dir = 0;
        nav.x -= 1;
        }
       else nav.dir = 1;

       blit(buffer,screen,0,0,0,0,500,450);
       rest(5);

    }

    destroy_bitmap(buffer);
    destroy_bitmap(nave);
    destroy_bitmap(nube);

    return 0;
}
END_OF_MAIN();
