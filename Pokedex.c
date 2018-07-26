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
        system("mode con cols=40 lines=24");
        printf("________________________________________\n");
        printf("  1-Alta Pokemon\n");
        printf("  2-Modificar Pokemon\n");
        printf("  3-Baja Pokemon\n");
        printf("  4-Listar Pokemons\n");
        printf("  5-Buscar Pokemon\n");
        printf("________________________________________\n");
        printf(" >");
        do{
            fflush(stdin);
            seguir=getch();
        }while(seguir!=ESC&&!(seguir>='1'&&seguir<='5'));
    return seguir;
}

int addPokemon(ArrayList*this){
    system("mode con cols=120 lines=52");
    Pokemon* eAux=pkmn_new();
    char *aux, *aux2;
    aux=(char*)malloc(sizeof(char)*50);
    printf("\n Ingrese ID de la Pokedex: ");
    pkmn_setIdPokedex(eAux,getPositiveNumber(999));
    int isRepeat=0,index=-1,endIndex;
    index=this->indexInt(this,pkmn_getIdPokedex,pkmn_getIdPokedex(eAux),index+1,this->len(this));
    while(index>=0){
        if(isRepeat==0){
            aux2=(char*)malloc(sizeof(char)*50);strcpy(aux2,"");
            printf("  | # |           Nombre           |  Tipo 1 | Tipo 2  |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion|Legendario|\n");
        }isRepeat++;
        printf("%d>",isRepeat);listStatsPokemon(this->get(this,index));
        endIndex=index;
        index=this->indexInt(this,pkmn_getIdPokedex,pkmn_getIdPokedex(eAux),index+1,this->len(this));
    }index=this->indexInt(this,pkmn_getIdPokedex,pkmn_getIdPokedex(eAux),0,this->len(this));
    if(getch()!=ESC){
        if(isRepeat>0){
            printf("\n Es una forma Alola?\n");
            if(trueOrFalse()){
                pkmn_setAlola(eAux,"True");
                strcpy(aux2,"(Alola) ");
            }else{
                pkmn_setAlola(eAux,"False");
            }
            printf("\n Es una Mega Evolucion?\n");
            if(trueOrFalse()){
                pkmn_setMegaOrPrimal(eAux,"Mega");
                strcpy(aux2,"Mega ");
            }else{
                printf("\n Es una Evolucion Primal?\n");
                if(trueOrFalse()){
                    pkmn_setMegaOrPrimal(eAux,"Primal");
                    strcpy(aux2,"Primal ");
                }else{
                    pkmn_setMegaOrPrimal(eAux,"False");
                }
            }
        }
        printf("\n Nombre: ");
        if(isRepeat>0){
            strcat(aux2,pkmn_getName(this->get(this,index)));
            printf("%s",aux2);
            getString(50-strlen(aux2),aux);
            strcat(aux2,aux);
            pkmn_setName(eAux,aux2);
        }else
            {pkmn_setName(eAux,getString(50,aux));}
        printf("\n Que tipo es:\n");
        pkmn_setType1(eAux,chooseType(aux));
        printf("\n Tiene otro tipo?\n");
        if(trueOrFalse()){
            printf("\n Que tipo es:\n");
            pkmn_setType2(eAux,chooseType(aux));
        }else{
            pkmn_setType2(eAux," ");
        }
        printf("\n Ingrese puntos de vida(HP): ");
        pkmn_setHP(eAux,getPositiveNumber(999));
        printf("\n Ingrese puntos de ataque: ");
        pkmn_setAttack(eAux,getPositiveNumber(999));
        printf("\n Ingrese puntos de defensa: ");
        pkmn_setDefense(eAux,getPositiveNumber(999));
        printf("\n Ingrese puntos de ataque especial: ");
        pkmn_setSpAtk(eAux,getPositiveNumber(999));
        printf("\n Ingrese puntos de defensa especial: ");
        pkmn_setSpDef(eAux,getPositiveNumber(999));
        printf("\n Ingrese puntos de velocidad: ");
        pkmn_setSpeed(eAux,getPositiveNumber(999));
        pkmn_setStatsTotal(eAux,(pkmn_getHP(eAux)+pkmn_getAttack(eAux)+pkmn_getDefense(eAux)+pkmn_getSpAtk(eAux)+pkmn_getSpDef(eAux)+pkmn_getSpeed(eAux)));
        if(isRepeat>0){
            pkmn_setGeneration(eAux,pkmn_getGeneration(this->get(this,index)));
            pkmn_setLegendary(eAux,pkmn_getLegendary(this->get(this,index)));
        }else{
            printf("\n Que generacion es?: N%c",-8);
            pkmn_setGeneration(eAux,chooseGeneration());
            printf("\n\n Es legendario?: ");
            pkmn_setLegendary(eAux,getTrueOrFalse(aux));
        }
        if(index>=0&&isRepeat>0){
            printf("  | # |           Nombre           |  Tipo 1 | Tipo 2  |Total| HP |ATK|DEF|SP.ATK|SP.DEF|VEL|Generacion|Legendario|\n");
            for(int i=1;index>0;i++){
                printf("%d>",i);listStatsPokemon(this->get(this,index));
                endIndex=index;
                index=this->indexInt(this,pkmn_getIdPokedex,pkmn_getIdPokedex(eAux),index+1,this->len(this));
            }
        }index=this->indexInt(this,pkmn_getIdPokedex,pkmn_getIdPokedex(eAux),endIndex-isRepeat,this->len(this));
        getch();
        this->push(this,index+1,eAux);
    }
    free(aux);free(aux2);
    return 1;
}

int menuListas(ArrayList*this){
    int seguir=0;
    while(seguir!=ESC){
        system("mode con cols=40 lines=24");
        printf("________________________________________\n");
        printf("  1-Listar todas las evoluciones\n");
        printf("  2-Listar las Mega evoluciones\n\t(o evoluciones Primales)\n");
        printf("  3-Listar Pokemons Legendarios\n");
        printf("  4-Listar Pokemons por tipo\n");
        printf("  5-Listar Pokemons por generacion\n");
        printf("________________________________________\n");
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
                this->mapBool(this,listStatsPokemon,pkmn_getIdPokedex,topText1);
                break;
            case '2':
                system("mode con cols=120 lines=52");
                this->mapBool(this,listStatsPokemon,isMegaOrPrimal,topText1);
                break;
            case '3':
                system("mode con cols=102 lines=52");
                this->mapBool(this,listStatsPokemonSinLegendario,isLegendary,topText2);
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
        system("mode con cols=40 lines=24");
        printf("________________________________________\n");
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
        printf("________________________________________\n");
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
                this->mapBool(this,listStatsPokemon,tipoAcero,topText);
                break;
            case 'B':   case 'b':
                this->mapBool(this,listStatsPokemon,tipoAgua,topText);
                break;
            case 'C':   case 'c':
                this->mapBool(this,listStatsPokemon,tipoBicho,topText);
                break;
            case 'D':   case 'd':
                this->mapBool(this,listStatsPokemon,tipoDragon,topText);
                break;
            case 'E':   case 'e':
                this->mapBool(this,listStatsPokemon,tipoElectrico,topText);
                break;
            case 'F':   case 'f':
                this->mapBool(this,listStatsPokemon,tipoFantasma,topText);
                break;
            case 'G':   case 'g':
                this->mapBool(this,listStatsPokemon,tipoFuego,topText);
                break;
            case 'H':   case 'h':
                this->mapBool(this,listStatsPokemon,tipoHada,topText);
                break;
            case 'I':   case 'i':
                this->mapBool(this,listStatsPokemon,tipoHielo,topText);
                break;
            case 'J':   case 'j':
                this->mapBool(this,listStatsPokemon,tipoLucha,topText);
                break;
            case 'K':   case 'k':
                this->mapBool(this,listStatsPokemon,tipoNormal,topText);
                break;
            case 'L':   case 'l':
                this->mapBool(this,listStatsPokemon,tipoPlanta,topText);
                break;
            case 'M':   case 'm':
                this->mapBool(this,listStatsPokemon,tipoPsiquico,topText);
                break;
            case 'N':   case 'n':
                this->mapBool(this,listStatsPokemon,tipoRoca,topText);
                break;
            case 'O':   case 'o':
                this->mapBool(this,listStatsPokemon,tipoSiniestro,topText);
                break;
            case 'P':   case 'p':
                this->mapBool(this,listStatsPokemon,tipoTierra,topText);
                break;
            case 'Q':   case 'q':
                this->mapBool(this,listStatsPokemon,tipoVeneno,topText);
                break;
            case 'R':   case 'r':
                this->mapBool(this,listStatsPokemon,tipoVolador,topText);
                break;
        }
    }return seguir;
}

int menuGeneracion(ArrayList*this){
    int seguir=0;
    while(seguir!=ESC){
        system("mode con cols=40 lines=24");
        printf("________________________________________\n");
        printf("  1-Listar Primera Generacion\n");
        printf("  2-Listar Segunda Generacion\n");
        printf("  3-Listar Tercera Generacion\n");
        printf("  4-Listar Cuarta Generacion\n");
        printf("  5-Listar Quinta Generacion\n");
        printf("  6-Listar Sexta Generacion\n");
        printf("  7-Listar Septima Generacion\n");
        printf("  8-Listar por Generacion\n");
        printf("________________________________________\n");
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
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration1,topText);
                break;
            case '2':
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration2,topText);
                break;
            case '3':
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration3,topText);
                break;
            case '4':
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration4,topText);
                break;
            case '5':
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration5,topText);
                break;
            case '6':
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration6,topText);
                break;
            case '7':
                this->mapBool(this,listStatsPokemonSinGeneracion,isGeneration7,topText);
                break;
            case '8':
                this->mapGroup(this,listStatsPokemonSinGeneracion,pkmn_getGeneration,"Generacion",topText);
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
void listStats(Pokemon* this){
    printf("%4d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
}
void listStatsPokemon(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    listStats(this);
    isGeneration(this);
    printf("|  %5s",pkmn_getLegendary(this));
    printf("\n");
}
void listStatsPokemonSinGeneracion(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    listStats(this);
    printf("  %5s",pkmn_getLegendary(this));
    printf("\n");
}
void listStatsPokemonSinLegendario(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    listStats(this);
    isGeneration(this);
    printf("\n");
}
void listBiologic(Pokemon* this){
    printf("%4d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
}
void listBiologicPokemon(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    listBiologic(this);
    isGeneration(this);
    printf("|  %5s",pkmn_getLegendary(this));
    printf("\n");
}
void listBiologicPokemonSinGeneracion(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    listBiologic(this);
    printf("  %5s",pkmn_getLegendary(this));
    printf("\n");
}
void listBiologicPokemonSinLegendario(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%9s|",pkmn_getType1(this));
    printf("%9s|",pkmn_getType2(this));
    listBiologic(this);
    isGeneration(this);
    printf("\n");
}

int searchPokemon(ArrayList* this){
    int Char,hayMayus,lines=0;
    char *pChar,*aux=(char*)malloc(sizeof(char)*50);
    Pokemon* eAux=pkmn_new();
    printf("\n\n Buscar: ");
    getString(50,aux);
    if(atoi(aux)>=0){
        for(int i=0;i<this->len(this);i++){
            eAux=this->get(this,i);
            if(pkmn_getIdPokedex(eAux)==atoi(aux)){
                lines++;
                printf("\n  %3d-%s",pkmn_getIdPokedex(eAux),pkmn_getName(eAux));
            }
        }
    }
    else
        {do{
            for(int i=0;i<this->len(this);i++){
                eAux=this->get(this,i);
                if(strstr(pkmn_getName(eAux),aux)&&!isMegaOrPrimal(eAux)&&!isAlola(eAux)){
                    if(lines==0){
                        system("mode con cols=42 lines=50");
                        printf("__________________________________________\n");
                        printf(" Resultados:");lines=2;
                    }lines++;
                    printf("\n  %3d-%s",pkmn_getIdPokedex(eAux),pkmn_getName(eAux));
                    if(lines%47==0){
                        printf("\n__________________________________________ ");
                        system("pause");system("cls");lines++;
                        printf("__________________________________________");
                    }
                }
            }hayMayus=0;
            for(int j=0;j<strlen(aux);j++){
                pChar=aux+j;
                Char=*pChar;
                if(Char>='A'&&Char<='Z'){
                    *pChar=Char+32;
                    hayMayus=1;
                }
            }
        }while(hayMayus);}
    if(lines==0)
        {printf("\n No se han encontrado resultados\n");}
    getch();free(aux);
    return lines;
}

char* chooseType(char* output){
    printf("\n  A-Tipo Acero");
    printf("\n  B-Tipo Agua");
    printf("\n  C-Tipo Bicho");
    printf("\n  D-Tipo Dragon");
    printf("\n  E-Tipo Electrico");
    printf("\n  F-Tipo Fantasma");
    printf("\n  G-Tipo Fuego");
    printf("\n  H-Tipo Hada");
    printf("\n  I-Tipo Hielo");
    printf("\n  J-Tipo Lucha");
    printf("\n  K-Tipo Normal");
    printf("\n  L-Tipo Planta");
    printf("\n  M-Tipo Psiquico");
    printf("\n  N-Tipo Roca");
    printf("\n  O-Tipo Siniestro");
    printf("\n  P-Tipo Tierra");
    printf("\n  Q-Tipo Veneno");
    printf("\n  R-Tipo Volador\n");
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
        number=getch()-48;
        if(number<1||number>7)
            {printf("%c",7);}
        else
            {printf("%d",number);break;}
    }return number;
}

