#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "Pokedex.h"
#define ESC 27

char menuListas(){
    char seguir=0;
    system("mode con cols=52 lines=11");
    printf("____________________________________________________\n");
    printf("  A-Listar todos los Pokemons\n");
    printf("  B-Listar las Mega evoluciones\n\t(o evoluciones Primales)\n");
    printf("  C-Listar Pokemons Legendarios\n");
    printf("  D-Listar Pokemons segun generacion\n");
    printf("____________________________________________________\n");
    printf(">");
    do{
        fflush(stdin);
        seguir=getch();
    }while(seguir!=ESC&&!(seguir>='A'&&seguir<='D')&&!(seguir>='a'&&seguir<='d'));
    return seguir;
}

Pokemon* pkmn_new(void){
    Pokemon* this = (Pokemon*) malloc(sizeof(Pokemon));
    return this;
}
void mostrarPokemon(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%8s|",pkmn_getType1(this));
    printf("%8s|",pkmn_getType2(this));
    printf(" %3d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
    printf("     %d    |",pkmn_getGeneration(this));
    printf("  %5s",pkmn_getLegendary(this));
    printf("\n");
}
void mostrarPokemonSinGeneracion(Pokemon* this){
    printf(" %03d|",pkmn_getIdPokedex(this));
    printf("%28s|",pkmn_getName(this));
    printf("%8s|",pkmn_getType1(this));
    printf("%8s|",pkmn_getType2(this));
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
    printf("%8s|",pkmn_getType1(this));
    printf("%8s|",pkmn_getType2(this));
    printf(" %3d |",pkmn_getStatsTotal(this));
    printf("%3d |",pkmn_getHP(this));
    printf("%3d|",pkmn_getAttack(this));
    printf("%3d|",pkmn_getDefense(this));
    printf(" %3d  |",pkmn_getSpAtk(this));
    printf(" %3d  |",pkmn_getSpDef(this));
    printf("%3d|",pkmn_getSpeed(this));
    printf("     %d",pkmn_getGeneration(this));
    printf("\n");
}

void pkmn_setIndex(Pokemon* this, int index){
    if(index > 0)
        this->index = index;
}
void pkmn_setIdPokedex(Pokemon* this, int idPokedex){
    if(idPokedex > 0)
        this->idPokedex = idPokedex;
}
void pkmn_setName(Pokemon* this, char* name){
    if(strlen(name)<50)
        strcpy(this->name, name);
}
void pkmn_setType1(Pokemon* this, char* type1){
    if(strlen(type1)<10)
        strcpy(this->type1, type1);
}
void pkmn_setType2(Pokemon* this, char* type2){
    if(strlen(type2)<10)
        strcpy(this->type2, type2);
}
void pkmn_setStatsTotal(Pokemon* this, int statsTotal){
    if(statsTotal > 0)
        this->statsTotal=statsTotal;
}
void pkmn_setHP(Pokemon* this, int HP){
    if(HP > 0)
        this->HP=HP;
}
void pkmn_setAttack(Pokemon* this, int attack){
    if(attack > 0)
        this->attack=attack;
}
void pkmn_setDefense(Pokemon* this, int defense){
    if(defense > 0)
        this->defense=defense;
}
void pkmn_setSpAtk(Pokemon* this, int spAtk){
    if(spAtk > 0)
        this->spAtk=spAtk;
}
void pkmn_setSpDef(Pokemon* this, int spDef){
    if(spDef > 0)
        this->spDef=spDef;
}
void pkmn_setSpeed(Pokemon* this, int speed){
    if(speed > 0)
        this->speed=speed;
}
void pkmn_setGeneration(Pokemon* this, int generation){
    if(generation > 0)
        this->generation=generation;
}
void pkmn_setLegendary(Pokemon* this, char* legendary){
    if(strcmp(legendary,"True")||strcmp(legendary,"False"))
        strcpy(this->legendary, legendary);
}
void pkmn_setMegaOrPrimal(Pokemon* this, char* megaOrPrimal){
    if(strcmp(megaOrPrimal,"True")||strcmp(megaOrPrimal,"False"))
        strcpy(this->megaOrPrimal, megaOrPrimal);
}


int pkmn_getIndex(Pokemon* this){
    return this->index;
}
int pkmn_getIdPokedex(Pokemon* this){
    return this->idPokedex;
}
char* pkmn_getName(Pokemon* this){
    return this->name;
}
char* pkmn_getType1(Pokemon* this){
    return this->type1;
}
char* pkmn_getType2(Pokemon* this){
    return this->type2;
}
int pkmn_getStatsTotal(Pokemon* this){
    return this->statsTotal;
}
int pkmn_getHP(Pokemon* this){
    return this->HP;
}
int pkmn_getAttack(Pokemon* this){
    return this->attack;
}
int pkmn_getDefense(Pokemon* this){
    return this->defense;
}
int pkmn_getSpAtk(Pokemon* this){
    return this->spAtk;
}
int pkmn_getSpDef(Pokemon* this){
    return this->spDef;
}
int pkmn_getSpeed(Pokemon* this){
    return this->speed;
}
int pkmn_getGeneration(Pokemon* this){
    return this->generation;
}
char* pkmn_getLegendary(Pokemon* this){
    return this->legendary;
}
char* pkmn_getMegaOrPrimal(Pokemon* this){
    return this->megaOrPrimal;
}

int isLegendary(Pokemon* this){
    return strcmp("False",pkmn_getLegendary(this));
}
int isMegaOrPrimal(Pokemon* this){
    return strcmp("False",pkmn_getMegaOrPrimal(this));
}
char* isGeneration(Pokemon* this){
    char aux[21]={""};
    switch(this->generation){
        case 1: sprintf(aux,"Primera");break;
        case 2: sprintf(aux,"Segunda");break;
        case 3: sprintf(aux,"Tercera");break;
        case 4: sprintf(aux,"Cuarta");break;
        case 5: sprintf(aux,"Quinta");break;
        case 6: sprintf(aux,"Sexta");break;
    }
    return aux;
}


