#include "Asteroide.h"
#include <allegro.h>
#include<iostream>
#include<list>
using namespace std;

Asteroide::Asteroide( int pintar,int c,int f,int v,int num,BITMAP *asteroide,BITMAP *buffer,list<Enemigo*>*enemigos)
{
         this->pintar=pintar;
           this->c = c;
            this->f = f;
            this->v = v;
            this->num = num;
        this->asteroide = asteroide;
        this->buffer = buffer;
        this->enemigos=enemigos;




    //ctor
}

Asteroide::~Asteroide()
{
    //dtor
}

int Asteroide::getValorX(){
return num;
}
int Asteroide::getValorY(){
return v;
}
int Asteroide::getValorW(){
return 0;
}
int Asteroide::getValorH(){
return 0;
}

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

int numero(int t){
  srand(rdtsc());
return rand() % t;
}

bool Asteroide::fuera(){
if(v==450){
return true;
}
}
void Asteroide::logic()
{

    if(pintar==0){
           if(c==8){
            c=1;
            f+=1;
        }
        if(f==8)
            f=1;
        if(v>=450){
            v=0;

           num = numero(450);
        }




        masked_blit(asteroide,buffer,64*c,64*f,num,v,64,64);
        c+=1;
        v+=5;

}

}
