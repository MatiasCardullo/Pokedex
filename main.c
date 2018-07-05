#include <stdio.h>
#include <stdlib.h>
#include "Pokedex.h"
#include "ArrayList.h"
#include "Parser.h"
#define ESC 27

int main(){
    system("color 0a");
    ArrayList* listaPokedex = al_newArrayList();
    if(parser_pokedex("pokedex.csv",listaPokedex)){
        //printf("Archivo leido\n");getchar();system("cls");
        menuListas(listaPokedex);
        listaPokedex->deleteArrayList(listaPokedex);
    }
    else
        {printf("Error leyendo pokedex\n");system("pause");}
    return 0;
}
