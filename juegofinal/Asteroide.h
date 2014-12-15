#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include <allegro.h>
#include <list>
#include "Enemigo.h"
class Enemigo;

using namespace std;
class Asteroide : public Enemigo
{
    public:
          int pintar;
        int c;
        int f;
        int v;
        int num;

         BITMAP *asteroide;
            BITMAP *buffer;
  list<Enemigo*> *enemigos;
        Asteroide( int pintar,int c,int f,int v,int num,BITMAP *asteroide,BITMAP *buffer,list<Enemigo*>*enemigos);
         void logic();
         bool fuera();
        int getValorX();
        int getValorY();
        int getValorW();
        int getValorH();
        virtual ~Asteroide();
    protected:
    private:
};

#endif // ASTEROIDE_H
