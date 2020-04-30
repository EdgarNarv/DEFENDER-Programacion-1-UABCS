#include <allegro.h>
using namespace std;

int main()
{
    allegro_init();
    install_mouse();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640,480, 0, 0);
    //Declaramos el tamaño de la pantalla


    //Creamos el bitmap
    BITMAP*buffer=create_bitmap(640,480);
    //cargamos las imagenes quee estaran de fondo
    BITMAP*fondo1=load_bitmap("fondo_uno.bmp",NULL);
    BITMAP*fondo2=load_bitmap("fondo_seleccion_jugar.bmp",NULL);
    BITMAP*fondo3=load_bitmap("fondo_seleccion_instrucciones.bmp",NULL);
    BITMAP*fondo4=load_bitmap("fondo_seleccion_creditos.bmp",NULL);
    BITMAP*fondo5=load_bitmap("fondo_seleccion_salir.bmp",NULL);
    BITMAP*cursor=load_bitmap("mouse_1.bmp",NULL);
    BITMAP*juego1=load_bitmap("demo.bmp",NULL);
    BITMAP*juego2=load_bitmap("demo_seleccion.bmp",NULL);
    BITMAP*inst1=load_bitmap("instrucciones.bmp",NULL);
    BITMAP*inst2=load_bitmap("instrucciones_seleccion.bmp",NULL);
    BITMAP*credito1=load_bitmap("creditos.bmp",NULL);
    BITMAP*credito2=load_bitmap("creditos_seleccion.bmp",NULL);
    bool juego=false;
    bool instruccion=false;
    bool creditos=false;
    bool salida = false;
    //while que ejecutara el codigo mientras que salida sea falso
    while(!salida)
    {
        //si el mouse se encuentra en esas coordenadas del bitmap
        if (mouse_x>280 && mouse_x<404 &&
            mouse_y>224 && mouse_y<280)
        {
            blit(fondo2,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                juego=true;
                salida= true;
            }
        }else if(mouse_x>180 && mouse_x<498 &&
                mouse_y>286 && mouse_y<340)
        {
            blit(fondo3,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                salida= true;
                instruccion=true;
            }
        }else if(mouse_x>230 && mouse_x<442 &&
                mouse_y>342 && mouse_y<394)
        {
            blit(fondo4,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                salida= true;
                creditos=true;
            }
        }else if(mouse_x>287 && mouse_x<409 &&
                mouse_y>402 && mouse_y<453)
        {
            blit(fondo5,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                salida= true;
                destroy_bitmap(buffer);
            }
        }else
        blit(fondo1,buffer,0,0,0,0,640,480);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,10,10);
        blit(buffer,screen,0,0,0,0,640,480);
    }
    while(juego==true)
    {
        blit(juego1,buffer,0,0,0,0,640,480);
        if (mouse_x>488 && mouse_x<630 &&
            mouse_y>438 && mouse_y<476)
        {
            blit(juego2,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                salida= false;
                juego=false;
            }

        }else
            blit(juego1,buffer,0,0,0,0,640,480);
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,10,10);
            blit(buffer,screen,0,0,0,0,640,480);
    }
    while(instruccion==true)
    {
        blit(inst1,buffer,0,0,0,0,640,480);
        if (mouse_x>488 && mouse_x<630 &&
            mouse_y>438 && mouse_y<476)
        {
            blit(inst2,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                salida= false;
                instruccion=false;
            }

        }else
            blit(inst1,buffer,0,0,0,0,640,480);
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,10,10);
            blit(buffer,screen,0,0,0,0,640,480);
    }
    while(creditos==true)
    {
        blit(credito1,buffer,0,0,0,0,640,480);
        if (mouse_x>488 && mouse_x<630 &&
            mouse_y>438 && mouse_y<476)
        {
            blit(credito2,buffer,0,0,0,0,640,480);
            if(mouse_b & 1)
            {
                salida=false;
                creditos=false;
            }

        }else
            blit(credito1,buffer,0,0,0,0,640,480);
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,10,10);
            blit(buffer,screen,0,0,0,0,640,480);
    }


return 0;
}
END_OF_MAIN();
