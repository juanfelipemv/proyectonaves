#ifndef ASTEROIDE2_H
#define ASTEROIDE2_H

#include <allegro.h>
#include <list>
#include "Enemigo.h"
class Enemigo;

using namespace std;
class Asteroide2 : public Enemigo
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
        Asteroide2( int pintar,int c,int f,int v,int num,BITMAP *asteroide,BITMAP *buffer,list<Enemigo*>*enemigos);
         void logic();
         bool fuera();
        int getValorX();
        int getValorY();
        int getValorW();
        int getValorH();
        virtual ~Asteroide2();
    protected:
    private:
};

#endif // ASTEROIDE_H
