#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include <stdio.h>

#define ARRIBA 'i'
#define ABAJO 'k'
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



int jugar();
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


int jugar()
{
    //:(

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


        gotoxy(50, 15);cout<< "ALVAREZ LUGO DARA" << endl;
        gotoxy(50, 16);cout<< "AVILES RAMOS ARISBETH" << endl;
        gotoxy(50, 17);cout<< "NARVAEZ MARICHE EDGAR" << endl;

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


        gotoxy(18,15); cout << "DEFENDER ES UN JUEGO DE DESPLAZAMIENTO HORIZONTAL, EN EL CUAL DEBEMOS ABATIR A LOS ENEMIGOS" << endl;
        gotoxy(18,16); cout << "QUE APARECEN EN PANTALLA, DISPARANDO DESDE NUESTRA NAVE, LA CUAL CONTROLAMOS."<< endl;
        gotoxy(18,17); cout << endl;
        gotoxy(18,18); cout << "USA LAS TECLAS DIRECCIONALES PARA MOVER LA NAVE A TRAVES DE LA PANTALLA <== ==>"<< endl;
        gotoxy(18,19); cout << endl;
        gotoxy(18,20); cout << "PARA DISPARAR USA LAS BARRA ESPACIADORA"<< endl;

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


int main()
{
   ocultarCursor();
   titulo();
   menu_principal();

   return 0;
}
