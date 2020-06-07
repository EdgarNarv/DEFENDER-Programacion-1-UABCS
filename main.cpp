#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <list>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define DISPARO 32
#define ENTER 13

using namespace std;


void ocultarCursor()
{
    HANDLE hCon;

    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=50; //Controla tamaño del cursor
    cci.bVisible=FALSE; //Controla la visibilidad del cursor

    SetConsoleCursorInfo(hCon,&cci);
}



int gotoxy(USHORT x,USHORT y)
{
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
 }



void jugar();
int titulo();
int creditos();
int instrucciones();
void salir();
bool repite = true;
int tecla;
int opcion;
int n = 4;
int opcionSeleccionada = 1;
const char *opciones[] = {"JUGAR","INSTRUCIONES","CREDITOS","SALIR"};



void menu_principal()
{

    repite = true;

    do{
    opcion =titulo();
    switch (opcion)
    {
        case 1:
            jugar();
            break;

         case 2:
            instrucciones();
            break;

         case 3:
            creditos();
            break;

         case 4:
            salir();
            repite = false;
            break;
      }
    }while(repite);

}


void marco()
{
     for (int i=4;i<=115;i++)//HORIZONTAL
    {
        gotoxy(i, 1); printf("%c",205);
        gotoxy(i, 28); printf("%c",205);
    }

    for(int i=2;i<=27;i++) //VERTICAL
    {
        gotoxy(4, i);printf("%c",186);
        gotoxy(115, i);printf("%c",186);
    }
    gotoxy(4,1);printf("%c",201); //ESQUINA 1
    gotoxy(115,1);printf("%c",187); //ESQUINA 2
    gotoxy(4, 28);printf("%c",200);//ESQUINA 3
    gotoxy(115, 28);printf("%c",188);//ESQUINA 4

}


int creditos()
{
    repite = true;
    system("cls");
    do{
        system("color 0c");

        marco();

        gotoxy(25, 2);cout << " ______  _______ _______ _______ _______ ______  _______ ______  " << endl ;
        gotoxy(25, 3);cout << "(______)(_______|_______|_______|_______|______)(_______|_____ \   " << endl ;
        gotoxy(25, 4);cout << " _     _ _____   _____   _____   _     _ _     _ _____   _____) )  " <<endl ;
        gotoxy(25, 5);cout << "| |   | |  ___) |  ___) |  ___) | |   | | |   | |  ___) |  __  /   " << endl ;
        gotoxy(25, 6);cout <<"| |__/ /| |_____| |     | |_____| |   | | |__/ /| |_____| |  \ \ " << endl;
        gotoxy(25, 7);cout <<"|_____/ |_______)_|     |_______)_|   |_|_____/ |_______)_|  |_|" << endl;


        gotoxy(50,12); cout << "C R E D I T O S" << endl;


        gotoxy(47, 15);cout<< "ALVAREZ LUGO DARA" << endl;
        gotoxy(47, 16);cout<< "AVILES RAMOS ARISBETH" << endl;
        gotoxy(47, 17);cout<< "NARVAEZ MARICHE EDGAR" << endl;

        gotoxy(18, 23+ opcionSeleccionada); cout << "==>" << endl;
        gotoxy(24,26); cout << " MENU"<< endl;


        do {
         tecla = getch();
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

       switch (tecla) {
            case ENTER:
                repite = false;
                menu_principal();
                break;
       }

        }while(repite);
    return creditos();
}



int instrucciones()
{
    repite = true;
    system("cls");
    do{
        system("color 0b");

        marco();

        gotoxy(25, 2);cout << " ______  _______ _______ _______ _______ ______  _______ ______  " << endl ;
        gotoxy(25, 3);cout << "(______)(_______|_______|_______|_______|______)(_______|_____ \   " << endl ;
        gotoxy(25, 4);cout << " _     _ _____   _____   _____   _     _ _     _ _____   _____) )  " <<endl ;
        gotoxy(25, 5);cout << "| |   | |  ___) |  ___) |  ___) | |   | | |   | |  ___) |  __  /   " << endl ;
        gotoxy(25, 6);cout <<"| |__/ /| |_____| |     | |_____| |   | | |__/ /| |_____| |  \ \ " << endl;
        gotoxy(25, 7);cout <<"|_____/ |_______)_|     |_______)_|   |_|_____/ |_______)_|  |_|" << endl;


        gotoxy(48,12); cout << "I N T R U C C I O N E S" << endl;


        gotoxy(18,15); cout << "DEFENDER ES UN JUEGO DE DESPLAZAMIENTO HORIZONTAL, EN EL CUAL DEBEMOS ABATIR A LOS ENEMIGOS" << endl;
        gotoxy(18,16); cout << "QUE APARECEN EN PANTALLA, DISPARANDO DESDE NUESTRA NAVE, LA CUAL CONTROLAMOS."<< endl;
        gotoxy(18,17); cout << endl;
        gotoxy(18,18); cout << "USA LAS TECLAS DIRECCIONALES PARA MOVER LA NAVE."<< endl;
        gotoxy(18,19); cout << endl;
        gotoxy(18,20); cout << "PARA DISPARAR USA LA BARRA ESPACIADORA."<< endl;

        gotoxy(18, 24+ opcionSeleccionada); cout << "==>" << endl;
        gotoxy(24,26); cout << " MENU"<< endl;

        do {
            tecla = getch();
       } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

       switch (tecla) {
            case ENTER:
                repite = false;
                menu_principal();
                break;
            }

    }while(repite);
    return instrucciones();
}


void salir(){
    exit(0);
}

int titulo()
{

    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
    n =4;
    do{
    //limpia pantalla
    system("cls");
    //color letra y consola
    system("color 0e");
    gotoxy(45, 14 + opcionSeleccionada); cout << "==>" << endl;


    marco();

        gotoxy(25, 4);cout << " ______  _______ _______ _______ _______ ______  _______ ______  " << endl ;
        gotoxy(25, 5);cout << "(______)(_______|_______|_______|_______|______)(_______|_____ \   " << endl ;
        gotoxy(25, 6);cout << " _     _ _____   _____   _____   _     _ _     _ _____   _____) )  " <<endl ;
        gotoxy(25, 7);cout << "| |   | |  ___) |  ___) |  ___) | |   | | |   | |  ___) |  __  /   " << endl ;
        gotoxy(25, 8);cout <<"| |__/ /| |_____| |     | |_____| |   | | |__/ /| |_____| |  \ \ " << endl;
        gotoxy(25, 9);cout <<"|_____/ |_______)_|     |_______)_|   |_|_____/ |_______)_|  |_|" << endl;



      // Imprime las opciones del menú
        for (int i = 0; i < n; ++i) {
            gotoxy(50, 15+ i); cout << i + 1 << ") " << opciones[i];
      }
      do {
         tecla = getch();
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

      switch (tecla)
      {

         case ARRIBA:   // En caso que se presione ARRIBA

            opcionSeleccionada--;

            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }

            break;

         case ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }

            break;

         case ENTER:
            repite = false;
            break;
        }
      }while (repite);

   return opcionSeleccionada;
}


//CLASES Y FUNCIONES DEL JUEGO


bool colision=false;

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
    gotoxy(x, y); printf(" %c", 62);
    gotoxy(x, y + 1); printf("%c%c%c%c%c",175,91, 207, 93,62);
    gotoxy(x, y + 2); printf(" %c", 62);
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
        if(tecla==DERECHA && x+5<112) x++;
        if(tecla==ARRIBA && y>3) y--;
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

        gotoxy(x,y);    printf("**  ");
        gotoxy(x,y+1);  printf(" **** ");
        gotoxy(x,y+2);  printf("**  ");
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


class LANDER
{
private:
    int x,y;
public:
    LANDER(int _x, int _y):x(_x),y(_y){}

    int X(){return x;}
    int Y(){return y;}

    void pintar();
    void mover();
    void choque(class NAVE &N);

};

void LANDER::pintar()
{
    gotoxy(x,y);printf("%c",184);
}

void LANDER::mover()
{
    gotoxy(x,y);printf(" ");

    x--;


    if(x<5)
    {
        y=rand()%20+5;
        x=110;

    }


    pintar();
}

void LANDER::choque(class NAVE &N)
{
    if(x>=N.X() && x<N.X()+6 && y>=N.Y() && y<=N.Y()+2)
    {
        N.vidas_menos();
        N.borrar();
        N.pintar();

        y=rand()%20+5;
        x=110;

        colision=true;
    }

}


class MUTANT
{
private:
    int x,y;
public:
    MUTANT(int _x, int _y):x(_x),y(_y){}

    int X(){return x;}
    int Y(){return y;}

    void pintar();
    void mover();
    void choque(class NAVE &N);

};

void MUTANT::pintar()
{
    gotoxy(x,y);printf("%c",220);
}

void MUTANT::mover()
{
    gotoxy(x,y);printf(" ");

    x--;


    if(x<5)
    {
        y=rand()%20+5;
        x=110;

    }

    pintar();
}

void MUTANT::choque(class NAVE &N)
{
    if(x>=N.X() && x<N.X()+6 && y>=N.Y() && y<=N.Y()+2)
    {
        N.vidas_menos();
        N.borrar();
        N.pintar();

        y=rand()%20+5;
        x=110;

        colision=true;
    }

}


class BRITER
{
private:
    int x,y;
public:
    BRITER(int _x, int _y):x(_x),y(_y){}

    int X(){return x;}
    int Y(){return y;}

    void pintar();
    void mover();
    void choque(class NAVE &N);

};

void BRITER::pintar()
{
    gotoxy(x,y);printf("%c",190);
}

void BRITER::mover()
{
    gotoxy(x,y);printf(" ");

    x--;


    if(x<5)
    {
        y=rand()%20+5;
        x=110;

    }

    pintar();
}

void BRITER::choque(class NAVE &N)
{
    if(x>=N.X() && x<N.X()+6 && y>=N.Y() && y<=N.Y()+2)
    {
        N.vidas_menos();
        N.borrar();
        N.pintar();

        y=rand()%20+5;
        x=110;

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
    x++;
    gotoxy(x,y);printf("*");

}

bool BALA::fuera()
{
    if(x==110)
    {
        return true;
    }
    return false;
}



void winner()
{
    marco();

    gotoxy(25, 2);cout << " ______  _______ _______ _______ _______ ______  _______ ______  " << endl ;
    gotoxy(25, 3);cout << "(______)(_______|_______|_______|_______|______)(_______|_____ \   " << endl ;
    gotoxy(25, 4);cout << " _     _ _____   _____   _____   _     _ _     _ _____   _____) )  " <<endl ;
    gotoxy(25, 5);cout << "| |   | |  ___) |  ___) |  ___) | |   | | |   | |  ___) |  __  /   " << endl ;
    gotoxy(25, 6);cout <<"| |__/ /| |_____| |     | |_____| |   | | |__/ /| |_____| |  \ \ " << endl;
    gotoxy(25, 7);cout <<"|_____/ |_______)_|     |_______)_|   |_|_____/ |_______)_|  |_|" << endl;

    gotoxy(32, 12);cout << " _     _  ___   __    _  __    _  _______  ______   " << endl ;
    gotoxy(32, 13);cout << "| | _ | ||   | |  |  | ||  |  | ||       ||    _ |  " << endl ;
    gotoxy(32, 14);cout << "| || || ||   | |   |_| ||   |_| ||    ___||   | ||  " <<endl ;
    gotoxy(32, 15);cout << "|       ||   | |       ||       ||   |___ |   |_||_ " << endl ;
    gotoxy(32, 16);cout <<"|       ||   | |  _    ||  _    ||    ___||    __  |" << endl;
    gotoxy(32, 17);cout <<"|   _   ||   | | | |   || | |   ||   |___ |   |  | |" << endl;
    gotoxy(32, 18);cout <<"|__| |__||___| |_|  |__||_|  |__||_______||___|  |_|" << endl;

    //OPCION REGRESAR MENU
    gotoxy(18, 24+ opcionSeleccionada); cout << "==>" << endl;
    gotoxy(24,25); cout << " MENU"<< endl;

    do
    {
        tecla = getch();

    } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

    switch (tecla)
    {
        case ENTER:
        repite = false;
        menu_principal();
        break;
    }
}

void GameOver()
{
    marco();

    gotoxy(25, 2);cout << " ______  _______ _______ _______ _______ ______  _______ ______  " << endl ;
    gotoxy(25, 3);cout << "(______)(_______|_______|_______|_______|______)(_______|_____ \   " << endl ;
    gotoxy(25, 4);cout << " _     _ _____   _____   _____   _     _ _     _ _____   _____) )  " <<endl ;
    gotoxy(25, 5);cout << "| |   | |  ___) |  ___) |  ___) | |   | | |   | |  ___) |  __  /   " << endl ;
    gotoxy(25, 6);cout <<"| |__/ /| |_____| |     | |_____| |   | | |__/ /| |_____| |  \ \ " << endl;
    gotoxy(25, 7);cout <<"|_____/ |_______)_|     |_______)_|   |_|_____/ |_______)_|  |_|" << endl;


    gotoxy(22, 12);cout << " _______  _______  __   __  _______    _______  __   __  _______  ______   " << endl ;
    gotoxy(22, 13);cout << "|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  " << endl ;
    gotoxy(22, 14);cout << "|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  " <<endl ;
    gotoxy(22, 15);cout << "|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ " << endl ;
    gotoxy(22, 16);cout <<"|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |" << endl;
    gotoxy(22, 17);cout <<"|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |" << endl;
    gotoxy(22, 18);cout <<"|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|" << endl;


    //OPCION REGRESAR MENU
    gotoxy(18, 24+ opcionSeleccionada); cout << "==>" << endl;
    gotoxy(24,25); cout << " MENU"<< endl;

    do
    {
        tecla = getch();

    } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

    switch (tecla)
    {
        case ENTER:
        repite = false;
        menu_principal();
        break;
    }

}



void jugar()
{
    repite = true;
    system("cls");

    do
    {
        system("color 0a");

        pintar_limites();


        NAVE N(15,15,3);
        N.pintar();
        N.pintar_vidas();

        list<LANDER*> L; //Lista de punteros
        list<LANDER*>:: iterator itL;

        list<MUTANT*> M; //Lista de punteros
        list<MUTANT*>:: iterator itM;

        list<BRITER*> T; //Lista de punteros
        list<BRITER*>:: iterator itT;

        for(int i=0;i<2;i++)
        {
            L.push_back(new LANDER(110, rand()%20+5));
        }

        for(int i=0;i<2;i++)
        {
            M.push_back(new MUTANT(110, rand()%20+5));
        }

        for(int i=0;i<1;i++)
        {
            T.push_back(new BRITER(110, rand()%20+5));
        }

        list<BALA*>B;//Lista de punteros
        list<BALA*>::iterator it;

        bool game_over=false;
        int puntos=0;

        while(game_over==false) //JUEGO
        {
            gotoxy(10,1);printf("PUNTOS %d",puntos);

            //DISPAROS
            if(kbhit())
            {
                char tecla=getch();

                if(tecla ==DISPARO)
                {
                    B.push_back(new BALA(N.X()+5,N.Y()+1));
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
            //DISPAROS


            //ENEMIGOS
            for(itL=L.begin(); itL!=L.end(); itL++)
            {
                (*itL)->mover();
                (*itL)->choque(N);
            }

            for(itM=M.begin(); itM!=M.end(); itM++)
            {
                (*itM)->mover();
                (*itM)->choque(N);
            }

            for(itT=T.begin(); itT!=T.end(); itT++)
            {
                (*itT)->mover();
                (*itT)->choque(N);
            }
            //ENEMIGOS



            //COLISION BALA-LANDER
            for(itL=L.begin();itL!=L.end();itL++) //Enemigo
            {
                for(it=B.begin();it!=B.end();it++)//Balas
                {
                    if((*itL)->X()==(*it)->X() && ( (*itL)->Y()+1 ==(*it)->Y() || (*itL)->Y()==(*it)->Y() ))
                    {
                        gotoxy( (*it)->X(),(*it)->Y() ); printf(" ");
                        delete(*it);
                        it=B.erase(it);

                        L.push_back(new LANDER(110, rand()%20+5));
                        gotoxy((*itL)->X(),(*itL)->Y()); printf(" ");
                        delete(*itL);
                        itL=L.erase(itL);

                        puntos+=150;
                    }
                }

            }


            //COLISION BALA-MUTANT
            for(itM=M.begin();itM!=M.end();itM++) //Enemigo
            {
                for(it=B.begin();it!=B.end();it++)//Balas
                {
                    if((*itM)->X()==(*it)->X() && ( (*itM)->Y()+1 ==(*it)->Y() || (*itM)->Y()==(*it)->Y() ))
                    {
                        gotoxy( (*it)->X(),(*it)->Y() ); printf(" ");
                        delete(*it);
                        it=B.erase(it);

                        M.push_back(new MUTANT(110, rand()%20+5));
                        gotoxy((*itM)->X(),(*itM)->Y()); printf(" ");
                        delete(*itM);
                        itM=M.erase(itM);

                        puntos+=150;
                    }
                }

            }


            //COLISION BALA-BRITER
            for(itT=T.begin();itT!=T.end();itT++) //Enemigo
            {
                for(it=B.begin();it!=B.end();it++)//Balas
                {
                    if((*itT)->X()==(*it)->X() && ( (*itT)->Y()+1 ==(*it)->Y() || (*itT)->Y()==(*it)->Y() ))
                    {
                        gotoxy( (*it)->X(),(*it)->Y() ); printf(" ");
                        delete(*it);
                        it=B.erase(it);

                        T.push_back(new BRITER(110, rand()%20+5));
                        gotoxy((*itT)->X(),(*itT)->Y()); printf(" ");
                        delete(*itT);
                        itT=T.erase(itT);

                        puntos+=200;
                    }
                }

            }



            N.mover();
            N.morir();


            //FINALIZAR EL JUEGO
            if(N.VID()==0)
            {
                game_over=true;
                system("cls");
                GameOver();
                exit(0);
            }

            if(puntos>=1000)
            {
                game_over=true;
                system("cls");
                winner();
                exit(0);
            }

            Sleep(30);

        }


    }while(repite);


}



int main()
{
    ocultarCursor();
    titulo();
    menu_principal();

    return 0;
}



