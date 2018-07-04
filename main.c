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
        int seguir=1;
        char* topText1={"  # |\t\t\tNombre\t |  Tipo1 |  Tipo2 |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion|Legendario\n"};
        char* topText2={"  # |\t\t\tNombre\t |  Tipo1 |  Tipo2 |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion\n"};
        char* topText3={"  # |\t\t\tNombre\t |  Tipo1 |  Tipo2 |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Legendario\n"};
        //printf("%d",strlen(topText));system("pause");
        //printf("%s",topText);system("pause");
        while(seguir){
            switch(menuListas()){
                case 'A':case 'a':
                    system("mode con cols=120 lines=52");
                    listaPokedex->mapTorF(listaPokedex,mostrarPokemon,pkmn_getIndex,topText1);
                    break;
                case 'B':case 'b':
                    system("mode con cols=120 lines=52");
                    listaPokedex->mapTorF(listaPokedex,mostrarPokemon,isMegaOrPrimal,topText1);
                    break;
                case 'C':case 'c':
                    system("mode con cols=101 lines=52");
                    listaPokedex->mapTorF(listaPokedex,mostrarPokemonSinLegendario,isLegendary,topText2);
                    break;
                case 'D':case 'd':
                    system("mode con cols=101 lines=52");
                    listaPokedex->mapGroup(listaPokedex,mostrarPokemonSinGeneracion,pkmn_getGeneration,"Generacion",topText3);
                    break;
                case ESC:
                    seguir=0;
            }
        }
        listaPokedex->deleteArrayList(listaPokedex);
    }
    else
        {printf("Error leyendo pokedex\n");system("pause");}
    return 0;
}
