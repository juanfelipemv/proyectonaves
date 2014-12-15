#include "Enemigo.h"

Enemigo::Enemigo()
{
    //ctor
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::render(){
//...
}

void Enemigo::logic(){
//..
}
bool Enemigo::fuera(){
//..
}
int Enemigo::getValorX(){
//..
}
int Enemigo::getValorY(){
//..
}
int Enemigo::getValorW(){
//..
}
int Enemigo::getValorH(){
//..
}
bool Enemigo::colision(int r1_x,int r1_y,int r1_w,int r1_h,int r2_x,int r2_y,int r2_w,int r2_h)
{
    return r1_x + r1_w > r2_x && r1_x < r1_x + r1_w
            && r1_y + r1_h > r1_y && r1_y < r1_y + r1_h;
}
