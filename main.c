#include <stdio.h>
#include <stdlib.h>
#include "Pokedex.h"
#include "ArrayList.h"
#include "Parser.h"
#define ESC 27

int main(){
    ArrayList* auxPokedex1 = al_newArrayList();
    if(parser_pokedex("pokedex.csv",auxPokedex1)){
        ArrayList* auxPokedex2 = al_newArrayList();
        auxPokedex2 = al_clone(auxPokedex1);
        int seguir=0;
        while(seguir!=ESC){
            switch(menu()){
                case '1':
                    addPokemon(auxPokedex2);
                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    menuListas(auxPokedex2);
                    break;
                case '5':
                    searchPokemon(auxPokedex2);
                    break;
                case ESC:
                    seguir=ESC;
            }
        }
        if(auxPokedex2->containsAll(auxPokedex1,auxPokedex2)){
            auxPokedex1->deleteArrayList(auxPokedex1);
            auxPokedex2->deleteArrayList(auxPokedex2);
        }else{
            crear_pokedex("prueba.csv",auxPokedex2);
            auxPokedex1->deleteArrayList(auxPokedex1);
        }
    }
    else
        {printf("Error leyendo pokedex\n");system("pause");}
    return 0;
}
