#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <list>

#define ARRIBA 'i'
#define IZQUIERDA 'j'
#define DERECHA 'l'
#define ABAJO 'k'
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

char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

   ReadConsoleA (ih, &c, 1, &contador, NULL);

   if (c == 0)
   {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }

   SetConsoleMode (ih, modo); // Devolvemos control normal

   return c;
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
         tecla = getch2();
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


        gotoxy(18,15); cout << "DEFENDER ES UN JUEGO DE DESPLAZAMIENTO VERTICAL, EN EL CUAL DEBEMOS ABATIR A LOS ENEMIGOS" << endl;
        gotoxy(18,16); cout << "QUE APARECEN EN PANTALLA, DISPARANDO DESDE NUESTRA NAVE, LA CUAL CONTROLAMOS."<< endl;
        gotoxy(18,17); cout << endl;
        gotoxy(18,18); cout << "USA LAS TECLAS J (IZQUIERDA) I (ARRIBA) K (ABAJO) L (DERECHA) PARA MOVER LA NAVE."<< endl;
        gotoxy(18,19); cout << endl;
        gotoxy(18,20); cout << "PARA DISPARAR USA LA BARRA ESPACIADORA."<< endl;

        gotoxy(18, 24+ opcionSeleccionada); cout << "==>" << endl;
        gotoxy(24,26); cout << " MENU"<< endl;

        do {
            tecla = getch2();
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
         tecla = getch2();
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


class ENEMIGO
{
private:
    int x,y;
public:
    ENEMIGO(int _x, int _y):x(_x),y(_y){}

    int X(){return x;}
    int Y(){return y;}

    void pintar();
    void mover();
    void choque(class NAVE &N);

};

void ENEMIGO::pintar()
{
    gotoxy(x,y);printf("%c",184);
}

void ENEMIGO::mover()
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

void ENEMIGO::choque(class NAVE &N)
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
        tecla = getch2();

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
        tecla = getch2();

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


        NAVE N(55,20,3);
        N.pintar();
        N.pintar_vidas();

        list<ENEMIGO*> E;
        list<ENEMIGO*>:: iterator itE;

        for(int i=0;i<5;i++)
        {
            E.push_back(new ENEMIGO(rand()%110+5, rand()%5+4));

        }

        list<BALA*>B; //Lista de punteros
        list<BALA*>::iterator it;

        bool game_over=false;
        int puntos=0;

        while(game_over==false) //JUEGO
        {
            gotoxy(10,1);printf("PUNTOS %d",puntos);

            N.mover();
            N.morir();

            //DISPAROS
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


            for(itE=E.begin(); itE!=E.end(); itE++)
            {
                (*itE)->mover();
                (*itE)->choque(N);
            }


            //COLISION BALA-ENEMIGO
            for(itE=E.begin();itE!=E.end();itE++) //Enemigo
            {
                for(it=B.begin();it!=B.end();it++)//Balas
                {
                    if((*itE)->X()==(*it)->X() && ( (*itE)->Y()+1 ==(*it)->Y() || (*itE)->Y()==(*it)->Y() ))
                    {
                        gotoxy( (*it)->X(),(*it)->Y() ); printf(" ");
                        delete(*it);
                        it=B.erase(it);

                        E.push_back(new ENEMIGO(rand()%110+5,4));
                        gotoxy((*itE)->X(),(*itE)->Y()); printf(" ");
                        delete(*itE);
                        itE=E.erase(itE);

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
                exit(0);
            }

            if(puntos==10)
            {
                game_over=true;
                system("cls");
                winner();
                exit(0);
            }

            Sleep(40);

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



