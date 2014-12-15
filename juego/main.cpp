#include <allegro.h>
#include "inicia.h"
#include<iostream>
#include<list>
#include "Enemigo.h"
#include "Asteroide.h"
#include "Asteroide2.h"


using namespace std;
const int maxdisp = 2 , ANCHO = 500, ALTO = 450;
string texto = "Presione Cualquier Tecla Para Salir";
void juego();
void cargarGameover();
void cargarVictoria();
void pintar_nave(BITMAP *nave,BITMAP *buffer,struct NAVE nav);
bool izq=true;
bool der=true;
bool level1=true;
bool level2=false;
bool level3=false;
bool finallevel=false;
int m=0, n=0, p=0, l=0;
struct NAVE{
    int x,y;
    int dir;
    int ndisparos;
}nav = {250,300,1,0};

struct NAVEMALA{
    int x,y;
    int dir;
    int ndisparos;
}navmal = {250,300,1,0};

struct BalasMala{
    int x,y;
    int dx,dy; //incrementos de las variables  x,y

}disparosMala[maxdisp];

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

bool colision(int bala_x, int bala_y, int bala_w, int bala_h, int asteroid_x, int asteroid_y,int asteroid_w,int asteroid_h)
{
return bala_x + bala_w > asteroid_x && bala_x < asteroid_x + asteroid_w
&& bala_y + bala_h > asteroid_y && bala_y < asteroid_y + asteroid_h;
}



void juego()
{
    BITMAP *nave = load_bitmap("nave.bmp",NULL);
     BITMAP *boss = load_bitmap("boss.bmp",NULL);
    BITMAP *vida = load_bitmap("vida.bmp",NULL);
    BITMAP *explo = load_bitmap("explosion.bmp",NULL);
    BITMAP *naveEnemiga = load_bitmap("spaceship.bmp",NULL);
    BITMAP *naveEnemiga2 = load_bitmap("nave_2.bmp",NULL);
    BITMAP *naveEnemiga3 = load_bitmap("nave_3.bmp",NULL);
    BITMAP *nube = load_tga("Galaxy2.tga",NULL);
     BITMAP *asteroide = load_bitmap("asteroid.bmp",NULL);
    BITMAP *bala = load_bitmap("Bala2.bmp", NULL);  // otra cosa
    BITMAP *stage1 = load_bitmap("STAGE1.bmp",NULL);
    BITMAP *stage2 = load_bitmap("STAGE2.bmp",NULL);
    BITMAP *stage3 = load_bitmap("STAGE3.bmp",NULL);
     BITMAP *finalstage = load_bitmap("FINALSTAGE.bmp",NULL);

    BITMAP *buffer = create_bitmap(500,450);

    bool activar=true;

    int NavesEnemigas = 3;
    int vidas = 3;
    int destroyed =0;
    int pintar=0;
   int c=1;
    int f=1;
    int v=0;
    int i = 450 , dsw = 0 , contt = 0;


    int colum=1;
    int fil=1;

      int movX=0;
        int movY=0;
   // int num = rand() % 500;
      list<Enemigo*>enemigos;
    enemigos.push_back(new Asteroide(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
    enemigos.push_back(new Asteroide2(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
//    if(level3==true){
//    enemigos.push_back(new Asteroide(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
//    enemigos.push_back(new Asteroide(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
//    enemigos.push_back(new Asteroide(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
//    enemigos.push_back(new Asteroide(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
//    }
// masked_blit(asteroide,buffer,64*c,64*f,num,v,64,64);

    while(!key[KEY_ESC]){
        if(finallevel==true && activar==true){
  enemigos.push_back(new Asteroide(pintar,c,f,v,rand() % 500,asteroide,buffer,&enemigos));
   activar=false;
        }
        blit(nube,buffer,0,--i,0,0,500,450);  if(i == 0) i=450;
        pintar_nave(nave,buffer,nav);
int prueba=0;
        for(list<Enemigo*>::iterator i = enemigos.begin();
i!=enemigos.end();
i++){

//    cout<<(*i)->getValorY()<<" ";
//    cout<<(*i)->getValorX()<<endl;
(*i)->logic();

if(colision((*i)->getValorX(),(*i)->getValorY(),64,64,nav.x,nav.y,40,47)){
     masked_blit(explo,buffer,64,64,nav.x,nav.y,64,64);
   cargarGameover();
 //  vidas=-1;
   cout<<"Colision"<<endl;
}
prueba+=1;
}


//         if(pintar==0){
//           if(c==8){
//            c=1;
//            f+=1;
//        }
//        if(f==8)
//            f=1;
//        if(v==450){
//            v=0;
//            num = rand() % 500;
//        }
//
//        masked_blit(asteroide,buffer,64*c,64*f,num,v,64,64);
//        c+=1;
//        v+=3;
//    }







        if(nav.x>0 && nav.x<450){
       if(key[KEY_UP])        { nav.dir = 1; nav.y -= 3; }
       else if(key[KEY_DOWN]) { nav.dir = 1; nav.y += 3; }
       if(key[KEY_RIGHT])     { nav.dir = 2; nav.x += 3; }
       else if(key[KEY_LEFT]) { nav.dir = 0; nav.x -= 3; }
       else nav.dir = 1;
        }else if(nav.x>=450){
        nav.x=nav.x-5;
        }else if(nav.x<=0){
        nav.x=nav.x+5;
        }


       ///rutina disparos///


        if(destroyed==0&&dsw==0){
            if(navmal.ndisparos<maxdisp){
                navmal.ndisparos++;
                disparosMala[navmal.ndisparos].x = movX + 45;
                disparosMala[navmal.ndisparos].y = movY;
                disparosMala[navmal.ndisparos].dx = 0;
                disparosMala[navmal.ndisparos].dy = +8;
                dsw = 1;

            }


       }

        if(navmal.ndisparos>0){
        for(int cont=1;cont<=navmal.ndisparos;cont++){
            disparosMala[cont].x += disparosMala[cont].dx;
            disparosMala[cont].y += disparosMala[cont].dy;
            if(destroyed==0)
            masked_blit(bala,buffer,0,0, disparosMala[cont].x,disparosMala[cont].y,4,7);

            if(disparosMala[cont].y>ALTO || disparosMala[cont].y <0 ||
                disparosMala[cont].x>ANCHO || disparosMala[cont].x<0){

                    disparosMala[cont]=disparosMala[navmal.ndisparos];
                    navmal.ndisparos--;
                    if(navmal.ndisparos<0){
                        navmal.ndisparos =0;
                    }
                }
                //colision Disparo A NAVE principal
                if(colision(disparosMala[cont].x,disparosMala[cont].y,4,7,nav.x,nav.y,40,47)){
                    disparosMala[cont]=disparosMala[navmal.ndisparos];
                    navmal.ndisparos--;
                    // masked_blit(explo,buffer,64,64,movX,movY,64,64);
                      masked_blit(explo,buffer,64,64,nav.x,nav.y,64,64);
                      vidas-=1;
                    cout<<"Colision Principal";
//                    movX=-5;
//                    movY=-5;
//                    destroyed=1;
                  //  pintar=1;

                }
        }

       }

        if(contt++ >20){
                dsw=0;
                contt=0;
            }

           if(key[KEY_SPACE]&&dsw==0){
            if(nav.ndisparos<maxdisp){
                nav.ndisparos++;
                disparos[nav.ndisparos].x = nav.x + 20;
                disparos[nav.ndisparos].y = nav.y;
                disparos[nav.ndisparos].dx = 0;
                disparos[nav.ndisparos].dy = -8;
                dsw = 1;

            }


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
                //colision Disparo A NAVE enemiga
                if(colision(disparos[cont].x,disparos[cont].y,4,7,movX,movY,59,48)){
                    if(destroyed==0)
                     masked_blit(explo,buffer,64,64,movX,movY,64,64);
                    cout<<"Colision";
                    if(level1){
                        level1=false;
                        level2=true;
                    }else if(level2){
                    level2=false;
                    level3=true;
                    }else if(level3){
                    level3=false;
                    finallevel=true;
                     activar=true;
                    }else if(finallevel){
                    cargarVictoria();

                    }

                    movX=0;
                    movY=0;
                   // movX=-5;
                    //movY=-5;
                    //destroyed=1;
                  //  pintar=1;

                }
        }

       }
        //MOVIMIENTOs NAVEs ENEMIGAs
        if(level1==true){
        if(destroyed==0){
        masked_blit(stage1,buffer,0,0,375,400,128,47);
        masked_blit(naveEnemiga,buffer,0,0,movX,movY,59,48);
        movX+=5;
        if(movX>=500){
           movX=0;
           movY+=20;
        }
        if(movY>=100){
            movY=0;
        }
        }
    }else if(level2==true){
        masked_blit(stage2,buffer,0,0,375,400,128,47);
           masked_blit(naveEnemiga2,buffer,0,0,movX,movY,59,48);
        if(der){
            movX+=5;
        }
        if(movX>=450){
        der=false;
        movY+=5;
        izq=true;
        }
        if(movY>=80 && izq==true){
            movX-=5;
            if(movX<=5){
                izq=false;
                der=true;
            }

        }
//        if(movX<=5){
//            izq=false;
//
//        }

    }else if(level3){
        masked_blit(stage3,buffer,0,0,375,400,128,47);
     masked_blit(naveEnemiga3,buffer,0,0,movX,movY,59,48);

        movX+=5;
        if(movX>=500){
         movX=0;
        }
     if(movY<80 && m==0){
        movY+=5;
    }else{
        m=1;
    n=1;

    }
    if(movY<=80 && n==1){
        movY-=5;
        if(movY<=0)
            m=0;
            n=0;
    }else{
    m=0;
    n=0;
    }


    }else if(finallevel){
    masked_blit(finalstage,buffer,0,0,375,400,128,47);
     masked_blit(boss,buffer,0,0,movX,movY,59,48);
     if(movX<450 && p==0){
    movX+=5;
        if(movX==450){
            p=1;
            l=1;
        }
     }
     if(movX<=450 && l==1){
    movX-=5;
          if(movX<=0){
            l=0;
            p=0;
          }
     }
    }

//        if(colum==4){
//     colum=1;
//            fil+=1;
//       }
//       if(fil==4)
//           fil=1;
//
//
//                    masked_blit(explo,buffer,64*fil,64*colum,50,50,64,64);
//        colum+=1;


        if(vidas==3){
        masked_blit(vida,buffer,0,0,-10,0,59,48);
        masked_blit(vida,buffer,0,0,20,0,59,48);
        masked_blit(vida,buffer,0,0,50,0,59,48);
        }else if(vidas==2){
        masked_blit(vida,buffer,0,0,-10,0,59,48);
        masked_blit(vida,buffer,0,0,20,0,59,48);
        }else{
         masked_blit(vida,buffer,0,0,-10,0,59,48);
        }
        //PARA PERDER
        if(vidas==0){
          cargarGameover();
        }


       blit(buffer,screen,0,0,0,0,500,450);
       rest(16.66);

    }

    destroy_bitmap(buffer);
    destroy_bitmap(nave);
    destroy_bitmap(nube);
    destroy_bitmap(vida);
    destroy_bitmap(naveEnemiga2);
    destroy_bitmap(naveEnemiga3);
    destroy_bitmap(asteroide);
     destroy_bitmap(explo);
     destroy_bitmap(bala);










}



void cargarVictoria()
{
                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("win.tga",NULL);
    while(!key[KEY_ESC]){

                        blit(menu,buffer,0,0,0,0,500,450);
                        blit(buffer,screen,0,0,0,0,500,450);
                        rest(5);


                         }

}

void cargarGameover()
{
                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("gameover.tga",NULL);
    while(!key[KEY_ESC]){

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

                        BITMAP *buffer = create_bitmap(500,450);
                        BITMAP *menu = load_tga("menu3.tga",NULL);
    //menu
     while(!key[KEY_ESC]){

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

