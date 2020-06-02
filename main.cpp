#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>

using namespace std;

#define ARRIBA 'i'
#define IZQUIERDA 'j'
#define DERECHA 'l'
#define ABAJO 'k'
#define DISPARO 'a'

bool colision=false;

void gotoxy(int x,int y)
{
    HANDLE hCon;

    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;

    SetConsoleCursorPosition(hCon,dwPos);

}

void ocultarCursor()
{
    HANDLE hCon;

    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=50; //Controla tamaño del cursor
    cci.bVisible=FALSE; //Controla la visibilidad del cursor

    SetConsoleCursorInfo(hCon,&cci);

}

void pintar_limites() //void marco();
{

    for (int i=4;i<=115;i++)//HORIZONTAL
    {
        gotoxy(i, 2); printf("%c",205);
        gotoxy(i, 28); printf("%c",205);
    }

    for(int i=2;i<=27;i++) //VERTICAL
    {
        gotoxy(4, i);printf("%c",186);
        gotoxy(115, i);printf("%c",186);
    }
    gotoxy(4,2);printf("%c",201); //ESQUINA 1
    gotoxy(115,2);printf("%c",187); //ESQUINA 2
    gotoxy(4, 28);printf("%c",200);//ESQUINA 3
    gotoxy(115, 28);printf("%c",188);//ESQUINA 4

}





class NAVE
{
private:
    int x,y;
    int vidas;
public:
    NAVE(int _x, int _y, int _vidas): x(_x), y(_y),vidas(_vidas){}

    int X(){return x;}
    int Y(){return y;}
    int VID(){return vidas;}

    void vidas_menos(){vidas--;}
    void pintar();
    void borrar();
    void mover();
    void pintar_vidas();
    void morir();

};


void NAVE::pintar()
{
    //NAVE VERTICAL
    gotoxy(x, y); printf("  %c", 94);
    gotoxy(x, y + 1); printf(" %c%c%c", 40, 207, 41);
    gotoxy(x, y + 2); printf("%c   %c", 94, 94);

    /*
    NAVE HORIZONTAL
    gotoxy(x, y); printf(" %c", 62);
    gotoxy(x, y + 1); printf("%c%c%c%c%",40, 207, 41,62);
    gotoxy(x, y + 2); printf(" %c", 62);
    */

}

void NAVE::borrar()
{
    gotoxy(x, y); printf("        ");
    gotoxy(x, y+1); printf("       ");
    gotoxy(x, y+2); printf("       ");
}

void NAVE::mover()
{
    if(kbhit())
    {
        char tecla=getch();

        borrar();

        if(tecla== IZQUIERDA && x>5) x--;
        if(tecla==DERECHA && x+5<115) x++;
        if(tecla==ARRIBA && y>2) y--;
        if(tecla==ABAJO && y+3<28) y++;

        pintar();
    }
}

void NAVE::pintar_vidas()
{
    gotoxy(100,1);printf("VIDAS %d",vidas);
}


void NAVE::morir()
{
    if(colision==true)
    {
        borrar();
        gotoxy(x,y);    printf("  **  ");
        gotoxy(x,y+1);  printf(" **** ");
        gotoxy(x,y+2);  printf("  **  ");
        Sleep(200);

        borrar();
        gotoxy(x,y);   printf(" * ** *");
        gotoxy(x,y+1); printf("  **** ");
        gotoxy(x,y+2); printf(" * ** *");
        Sleep(200);

        borrar();

        pintar_vidas();
        pintar();

        colision=false;

    }
}





class AST
{
private:
    int x,y;
public:
    AST(int _x, int _y):x(_x),y(_y){}

    int X(){return x;}
    int Y(){return y;}

    void pintar();
    void mover();
    void choque(class NAVE &N);

};

void AST::pintar()
{
    gotoxy(x,y);printf("%c",184);
}

void AST::mover()
{
    gotoxy(x,y);printf(" ");
    y++;

    if(y>26)
    {
        x=rand()%110+5;
        y=4;
    }
    pintar();
}

void AST::choque(class NAVE &N)
{
    if(x>=N.X() && x<N.X()+6 && y>=N.Y() && y<=N.Y()+2)
    {
        N.vidas_menos();
        N.borrar();
        N.pintar();
        x=rand()%110+5;
        y=4;
        colision=true;
    }

}





class BALA
{
private:
    int x,y;
public:
    BALA(int _x,int _y):x(_x),y(_y){}

    int X(){return x;}
    int Y(){return y;}

    void mover();
    bool fuera();
};



void BALA::mover()
{
    gotoxy(x,y);printf(" ");
    y--;
    gotoxy(x,y);printf("*");

}

bool BALA::fuera()
{
    if(y==4)
    {
        return true;
    }
    return false;
}


void winner()
{
    gotoxy(50,9);printf("                  ");
    gotoxy(53,14);printf("W I N N E R");
    for (int i=15;i<30;i++)
    {
        gotoxy(50,i);printf("                  ");
    }
}

void GameOver()
{
    gotoxy(50,9);printf("                  ");
    gotoxy(52,14);printf("G A M E   O V E R ");
    for (int i=15;i<30;i++)
    {
        gotoxy(50,i);printf("                  ");
    }
}





int main()
{
    ocultarCursor();
    pintar_limites();


    NAVE N(50,20,3);
    N.pintar();
    N.pintar_vidas();



    list<AST*> A;
    list<AST*>:: iterator itA;

    for(int i=0;i<5;i++)
    {
        A.push_back(new AST(rand()%110+5, rand()%5+4));

    }

    list<BALA*>B; //Lista de punteros
    list<BALA*>::iterator it;


    bool game_over=false;
    int puntos=0;

    while(game_over==false)
    {
        gotoxy(10,1);printf("PUNTOS %d",puntos);

        N.mover();
        N.morir();


        if(kbhit())
        {
            char tecla=getch();
            if(tecla ==DISPARO)
            {
                B.push_back(new BALA(N.X()+2,N.Y()-1));
            }

        }


        for(it = B.begin(); it != B.end();)
		{
		    (*it)->mover();
			if((*it)->fuera())
            {
				gotoxy((*it)->X(),(*it)->Y());	printf(" ");
				delete (*it);
				it = B.erase(it);
			}else
			{

			    it++;
			}
		}


        for(itA=A.begin(); itA!=A.end(); itA++)
        {
            (*itA)->mover();
            (*itA)->choque(N);
        }


        //COLISION BALA-ASTEROIDE
        for(itA=A.begin();itA!=A.end();itA++) //Asteroides
        {
            for(it=B.begin();it!=B.end();it++)//Balas
            {
                if((*itA)->X()==(*it)->X() && ( (*itA)->Y()+1 ==(*it)->Y() || (*itA)->Y()==(*it)->Y() ))
                {
                    gotoxy( (*it)->X(),(*it)->Y() ); printf(" ");
                    delete(*it);
                    it=B.erase(it);

                    A.push_back(new AST(rand()%110+5,4));
                    gotoxy((*itA)->X(),(*itA)->Y()); printf(" ");
                    delete(*itA);
                    itA=A.erase(itA);

                    puntos+=5;
                }
            }

        }


        //FINALIZAR EL JUEGO
        if(N.VID()==0)
        {
            game_over=true;
            system("cls");
            GameOver();
        }

        if(puntos==50)
        {
            game_over=true;
            system("cls");
            winner();
        }

        Sleep(40);

    }

    return 0;
}
