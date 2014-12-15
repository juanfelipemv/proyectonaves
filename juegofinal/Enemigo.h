#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <allegro.h>
#include <list>

class Enemigo
{
    public:


        Enemigo();
        virtual void logic();
        virtual void render();
        virtual bool fuera();
        virtual int getValorX();
          virtual int getValorY();
            virtual int getValorW();
              virtual int getValorH();
        virtual ~Enemigo();
         virtual bool colision(int r1_x,int r1_y,int r1_w,int r1_h,int r2_x,int r2_y,int r2_w,int r2_h);
    protected:
    private:
};

#endif // ENEMIGO_H
