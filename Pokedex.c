#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "Pokedex.h"
#include "SetGetBool.h"
#define ESC 27

Pokemon* pkmn_new(void){
    Pokemon* this = (Pokemon*) malloc(sizeof(Pokemon));
    return this;
}

int menu(){
    int seguir=0;
        system("mode con cols=52 lines=11");
        printf("____________________________________________________\n");
        printf("  1-Alta Pokemon\n");
        printf("  2-Modificar Pokemon\n");
        printf("  3-Baja Pokemon\n");
        printf("  4-Listar Pokemons\n");
        printf("____________________________________________________\n");
        printf(" >");
        do{
            fflush(stdin);
            seguir=getch();
        }while(seguir!=ESC&&!(seguir>='1'&&seguir<='4'));
    return seguir;
}

int addPokemon(ArrayList*this){
    Pokemon* eAux=pkmn_new();
    char* aux;
    aux=(char*)malloc(sizeof(char)*50);
    printf("\n  Ingrese ID de la Pokedex: ");
    pkmn_setIdPokedex(eAux,getPositiveNumber());
    //this->indexOf(this,)
    printf("\n  Ingrese nombre: ");
    pkmn_setName(eAux,getString(50,aux));
    printf("\n  Que tipo es: ");
    pkmn_setType1(eAux,chooseType(aux));
    printf("\n  Tiene otro tipo? ");
    if(trueOrFalse()){
        printf("\n  Que tipo es: ");
        pkmn_setType2(eAux,chooseType(aux));
    }else{
        pkmn_setType2(eAux," ");
    }
    printf("\n  Ingrese puntos de vida(HP): ");
    pkmn_setHP(eAux,getPositiveNumber());
    printf("\n  Ingrese puntos de ataque: ");
    pkmn_setAttack(eAux,getPositiveNumber());
    printf("\n  Ingrese puntos de defensa: ");
    pkmn_setDefense(eAux,getPositiveNumber());
    printf("\n  Ingrese puntos de ataque especial: ");
    pkmn_setSpAtk(eAux,getPositiveNumber());
    printf("\n  Ingrese puntos de defensa especial: ");
    pkmn_setSpDef(eAux,getPositiveNumber());
    printf("\n  Ingrese puntos de velocidad: ");
    pkmn_setSpeed(eAux,getPositiveNumber());
    pkmn_setStatsTotal(eAux,(pkmn_getHP(eAux)+pkmn_getAttack(eAux)+pkmn_getDefense(eAux)+pkmn_getSpAtk(eAux)+pkmn_getSpDef(eAux)+pkmn_getSpeed(eAux)));
    printf("\n  Que generacion es?: ");
    pkmn_setGeneration(eAux,chooseGeneration());
    printf("\n  Es legendario?: ");
    pkmn_setLegendary(eAux,getTrueOrFalse(aux));
    //pkmn_setMegaOrPrimal(eAux,mega_o_primal);
    this->add(this,eAux);
}

int menuListas(ArrayList*this){
    int seguir=0;
    while(seguir!=ESC){
        system("mode con cols=52 lines=11");
        printf("____________________________________________________\n");
        printf("  1-Listar todas las evoluciones\n");
        printf("  2-Listar las Mega evoluciones\n\t(o evoluciones Primales)\n");
        printf("  3-Listar Pokemons Legendarios\n");
        printf("  4-Listar Pokemons por tipo\n");
        printf("  5-Listar Pokemons por generacion\n");
        printf("____________________________________________________\n");
        printf(" >");
        do{
            fflush(stdin);
            seguir=getch();
        }while(seguir!=ESC&&!(seguir>='1'&&seguir<='5'));
        char* topText1={"  # |\t\tNombre\t\t |  Tipo 1 | Tipo 2  |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion|Legendario\n"};
        char* topText2={"  # |\t\tNombre\t\t |  Tipo 1 | Tipo 2  |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion\n"};
        switch(seguir){
            case '1':
                system("mode con cols=120 lines=52");
                this->mapBool(this,mostrarPokemon,pkmn_getIndex,topText1);
                break;
            case '2':
                system("mode con cols=120 lines=52");
                this->mapBool(this,mostrarPokemon,isMegaOrPrimal,topText1);
                break;
            case '3':
                system("mode con cols=102 lines=52");
                this->mapBool(this,mostrarPokemonSinLegendario,isLegendary,topText2);
                break;
            case '4':
                menuTipos(this);
                break;
            case '5':
                menuGeneracion(this);
                break;
        }
    }return seguir;
}

int menuTipos(ArrayList*this){
    int seguir=0;
    while(seguir!=ESC){
        system("mode con cols=52 lines=25");
        printf("____________________________________________________\n");
        printf("  A-Listar los de tipo Acero\n");
        printf("  B-Listar los de tipo Agua\n");
        printf("  C-Listar los de tipo Bicho\n");
        printf("  D-Listar los de tipo Dragon\n");
        printf("  E-Listar los de tipo Electrico\n");
        printf("  F-Listar los de tipo Fantasma\n");
        printf("  G-Listar los de tipo Fuego\n");
        printf("  H-Listar los de tipo Hada\n");
        printf("  I-Listar los de tipo Hielo\n");
        printf("  J-Listar los de tipo Lucha\n");
        printf("  K-Listar los de tipo Normal\n");
        printf("  L-Listar los de tipo Planta\n");
        printf("  M-Listar los de tipo Psiquico\n");
        printf("  N-Listar los de tipo Roca\n");
        printf("  O-Listar los de tipo Siniestro\n");
        printf("  P-Listar los de tipo Tierra\n");
        printf("  Q-Listar los de tipo Veneno\n");
        printf("  R-Listar los de tipo Volador\n");
        printf("____________________________________________________\n");
        printf(" >");
        do{
            fflush(stdin);
            seguir=getch();
        }while(seguir!=ESC&&!(seguir>='A'&&seguir<='R')&&!(seguir>='a'&&seguir<='r'));
        char* topText={"  # |\t\tNombre\t\t |  Tipo 1 | Tipo 2  |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion|Legendario\n"};
        if(seguir!=ESC)
            {system("mode con cols=120 lines=52");}
        switch(seguir){
            case 'A':   case 'a':
                this->mapBool(this,mostrarPokemon,tipoAcero,topText);
                break;
            case 'B':   case 'b':
                this->mapBool(this,mostrarPokemon,tipoAgua,topText);
                break;
            case 'C':   case 'c':
                this->mapBool(this,mostrarPokemon,tipoBicho,topText);
                break;
            case 'D':   case 'd':
                this->mapBool(this,mostrarPokemon,tipoDragon,topText);
                break;
            case 'E':   case 'e':
                this->mapBool(this,mostrarPokemon,tipoElectrico,topText);
                break;
            case 'F':   case 'f':
                this->mapBool(this,mostrarPokemon,tipoFantasma,topText);
                break;
            case 'G':   case 'g':
                this->mapBool(this,mostrarPokemon,tipoFuego,topText);
                break;
            case 'H':   case 'h':
                this->mapBool(this,mostrarPokemon,tipoHada,topText);
                break;
            case 'I':   case 'i':
                this->mapBool(this,mostrarPokemon,tipoHielo,topText);
                break;
            case 'J':   case 'j':
                this->mapBool(this,mostrarPokemon,tipoLucha,topText);
                break;
            case 'K':   case 'k':
                this->mapBool(this,mostrarPokemon,tipoNormal,topText);
                break;
            case 'L':   case 'l':
                this->mapBool(this,mostrarPokemon,tipoPlanta,topText);
                break;
            case 'M':   case 'm':
                this->mapBool(this,mostrarPokemon,tipoPsiquico,topText);
                break;
            case 'N':   case 'n':
                this->mapBool(this,mostrarPokemon,tipoRoca,topText);
                break;
            case 'O':   case 'o':
                this->mapBool(this,mostrarPokemon,tipoSiniestro,topText);
                break;
            case 'P':   case 'p':
                this->mapBool(this,mostrarPokemon,tipoTierra,topText);
                break;
            case 'Q':   case 'q':
                this->mapBool(this,mostrarPokemon,tipoVeneno,topText);
                break;
            case 'R':   case 'r':
                this->mapBool(this,mostrarPokemon,tipoVolador,topText);
                break;
        }
    }return seguir;
}

int menuGeneracion(ArrayList*this){
    int seguir=0;
    while(seguir!=ESC){
        system("mode con cols=52 lines=15");
        printf("____________________________________________________\n");
        printf("  1-Listar Primera Generacion\n");
        printf("  2-Listar Segunda Generacion\n");
        printf("  3-Listar Tercera Generacion\n");
        printf("  4-Listar Cuarta Generacion\n");
        printf("  5-Listar Quinta Generacion\n");
        printf("  6-Listar Sexta Generacion\n");
        printf("  7-Listar Septima Generacion\n");
        printf("  8-Listar por Generacion\n");
        printf("____________________________________________________\n");
        printf(" >");
        do{
            fflush(stdin);
            seguir=getch();
        }while(seguir!=ESC&&!(seguir>='1'&&seguir<='8'));
        char* topText={"  # |\t\tNombre\t\t |  Tipo 1 | Tipo 2  |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Legendario\n"};
        if(seguir!=ESC)
            {system("mode con cols=102 lines=52");}
        switch(seguir){
            case '1':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration1,topText);
                break;
            case '2':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration2,topText);
                break;
            case '3':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration3,topText);
                break;
            case '4':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration4,topText);
                break;
            case '5':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration5,topText);
                break;
            case '6':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration6,topText);
                break;
            case '7':
                this->mapBool(this,mostrarPokemonSinGeneracion,isGeneration7,topText);
                break;
            case '8':
                this->mapGroup(this,mostrarPokemonSinGeneracion,pkmn_getGeneration,"Generacion",topText);
                break;
        }
    }return seguir;
}

int isGeneration(Pokemon* this){
    switch(this->generation){
        case 1: printf(" Primera  ");break;
        case 2: printf(" Segunda  ");break;
        case 3: printf(" Tercera  ");break;
        case 4: printf("  Cuarta  ");break;
        case 5: printf("  Quinta  ");break;
        case 6: printf("  Sexta   ");break;
        case 7: printf(" Septima  ");break;
    }return this->generation;
}

void mostrarPokemon(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    printf(" %3d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
    isGeneration(this);
    printf("|  %5s",pkmn_getLegendary(this));
    printf("\n");
}

void mostrarPokemonSinGeneracion(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    printf(" %3d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
    printf("  %5s",pkmn_getLegendary(this));
    printf("\n");
}

void mostrarPokemonSinLegendario(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    printf(" %3d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
    isGeneration(this);
    printf("\n");
}

char* chooseType(char* output){
    printf("\n A-Tipo Acero");
    printf("\n B-Tipo Agua");
    printf("\n C-Tipo Bicho");
    printf("\n D-Tipo Dragon");
    printf("\n E-Tipo Electrico");
    printf("\n F-Tipo Fantasma");
    printf("\n G-Tipo Fuego");
    printf("\n H-Tipo Hada");
    printf("\n I-Tipo Hielo");
    printf("\n J-Tipo Lucha");
    printf("\n K-Tipo Normal");
    printf("\n L-Tipo Planta");
    printf("\n M-Tipo Psiquico");
    printf("\n N-Tipo Roca");
    printf("\n O-Tipo Siniestro");
    printf("\n P-Tipo Tierra");
    printf("\n Q-Tipo Veneno");
    printf("\n R-Tipo Volador\n");
    int opcion;
    int seguir=1;
    while(seguir){
        seguir=0;
        fflush(stdin);
        opcion=getch();
        switch(opcion){
            case 'A':   case 'a':
                strcpy(output,"Acero");
                break;
            case 'B':   case 'b':
                strcpy(output,"Agua");
                break;
            case 'C':   case 'c':
                strcpy(output,"Bicho");
                break;
            case 'D':   case 'd':
                strcpy(output,"Dragon");
                break;
            case 'E':   case 'e':
                strcpy(output,"Electrico");
                break;
            case 'F':   case 'f':
                strcpy(output,"Fantasma");
                break;
            case 'G':   case 'g':
                strcpy(output,"Fuego");
                break;
            case 'H':   case 'h':
                strcpy(output,"Hada");
                break;
            case 'I':   case 'i':
                strcpy(output,"Hielo");
                break;
            case 'J':   case 'j':
                strcpy(output,"Lucha");
                break;
            case 'K':   case 'k':
                strcpy(output,"Normal");
                break;
            case 'L':   case 'l':
                strcpy(output,"Planta");
                break;
            case 'M':   case 'm':
                strcpy(output,"Psiquico");
                break;
            case 'N':   case 'n':
                strcpy(output,"Roca");
                break;
            case 'O':   case 'o':
                strcpy(output,"Siniestro");
                break;
            case 'P':   case 'p':
                strcpy(output,"Tierra");
                break;
            case 'Q':   case 'q':
                strcpy(output,"Veneno");
                break;
            case 'R':   case 'r':
                strcpy(output,"Volador");
                break;
            default:
                printf("%c",7);
                seguir=1;
        }
    }return output;
}

int chooseGeneration(){
    int number;
    while(1){
        number=getPositiveNumber();
        if(number>7)
            {printf("%c",7);}
        else
            {break;}
    }return number;
}

