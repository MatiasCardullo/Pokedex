#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "SetGetBool.h"
#include "Pokedex.h"

int getPositiveNumber(int limit){
    char* aux;
    int digits,cont=limit;
    for(digits=1;cont>0;digits++)
        {cont=cont/10;}
    aux=(char *)malloc(sizeof(char)*(digits));
    int number=NULL;
    while(1){
        getString(digits,aux);
        number=atoi(aux);
        if(number>0&&number<limit)
            {free(aux);break;}
        else
            {printf("%c",7);}
    }return number;
}
char* getString(int large,char* aux){
    fflush(stdin);
    fgets(aux,large,stdin);
      if (aux[strlen(aux)-1] == '\n')
      {aux[strlen(aux)-1] = '\0';}
    return aux;
}
char* getTrueOrFalse(char* output){
    if(trueOrFalse())
        {strcpy(output,"True");}
    else
        {strcpy(output,"False");}
    return output;
}
int trueOrFalse(){
    int aux;
    while(1){
        aux=getch();
        if(aux=='T'||aux=='t'||aux=='V'||aux=='v'||aux=='S'||aux=='s')
            {aux=1;break;}
        else if(aux=='F'||aux=='f'||aux=='N'||aux=='n')
            {aux=0;break;}
        else
            {printf("%c",7);}
    }
    return aux;
}

void pkmn_setIdPokedex(Pokemon* this, int idPokedex){
    if(idPokedex > 0)
        {this->idPokedex = idPokedex;}
}
void pkmn_setName(Pokemon* this, char* name){
    if(strlen(name)<50)
        {strcpy(this->name, name);}
}
void pkmn_setType1(Pokemon* this, char* type1){
    if(strlen(type1)<10)
        {strcpy(this->type1, type1);}
}
void pkmn_setType2(Pokemon* this, char* type2){
    if(strlen(type2)<10)
        {strcpy(this->type2, type2);}
}
void pkmn_setStatsTotal(Pokemon* this, int statsTotal){
    if(statsTotal > 0)
        {this->statsTotal=statsTotal;}
}
void pkmn_setHP(Pokemon* this, int HP){
    if(HP > 0)
        {this->HP=HP;}
}
void pkmn_setAttack(Pokemon* this, int attack){
    if(attack > 0)
        {this->attack=attack;}
}
void pkmn_setDefense(Pokemon* this, int defense){
    if(defense > 0)
        {this->defense=defense;}
}
void pkmn_setSpAtk(Pokemon* this, int spAtk){
    if(spAtk > 0)
        {this->spAtk=spAtk;}
}
void pkmn_setSpDef(Pokemon* this, int spDef){
    if(spDef > 0)
        {this->spDef=spDef;}
}
void pkmn_setSpeed(Pokemon* this, int speed){
    if(speed > 0)
        {this->speed=speed;}
}
void pkmn_setGeneration(Pokemon* this, int generation){
    if(generation > 0)
        {this->generation=generation;}
}
void pkmn_setLegendary(Pokemon* this, char* legendary){
    if(strcmp(legendary,"True")||strcmp(legendary,"False"))
        {strcpy(this->legendary, legendary);}
}
void pkmn_setMegaOrPrimal(Pokemon* this, char* megaOrPrimal){
    if(strcmp(megaOrPrimal,"Mega")||strcmp(megaOrPrimal,"Primal")||strcmp(megaOrPrimal,"False"))
        {strcpy(this->megaOrPrimal, megaOrPrimal);}
}
void pkmn_setAlola(Pokemon* this, char* alola){
    if(strcmp(alola,"True")||strcmp(alola,"False"))
        {strcpy(this->alola, alola);}
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
char* pkmn_getAlola(Pokemon* this){
    return this->alola;
}

int isLegendary(Pokemon* this){
    return strcmp("False",pkmn_getLegendary(this));
}
int isMegaOrPrimal(Pokemon* this){
    return strcmp("False",pkmn_getMegaOrPrimal(this));
}
int isAlola(Pokemon* this){
    return strcmp("False",pkmn_getAlola(this));
}
int isGeneration1(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==1)
        {isXGeneration=1;}
    return isXGeneration;
}
int isGeneration2(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==2)
        {isXGeneration=1;}
    return isXGeneration;
}
int isGeneration3(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==3)
        {isXGeneration=1;}
    return isXGeneration;
}
int isGeneration4(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==4)
        {isXGeneration=1;}
    return isXGeneration;
}
int isGeneration5(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==5)
        {isXGeneration=1;}
    return isXGeneration;
}
int isGeneration6(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==6)
        {isXGeneration=1;}
    return isXGeneration;
}
int isGeneration7(Pokemon* this){
    int isXGeneration=0;
    if(this->generation==7)
        {isXGeneration=1;}
    return isXGeneration;
}

int tipoAcero(Pokemon* this){
    int tipo=0;
    if(strcmp("Acero",pkmn_getType1(this))==0||strcmp("Acero",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoAgua(Pokemon* this){
    int tipo=0;
    if(strcmp("Agua",pkmn_getType1(this))==0||strcmp("Agua",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoBicho(Pokemon* this){
    int tipo=0;
    if(strcmp("Bicho",pkmn_getType1(this))==0||strcmp("Bicho",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoDragon(Pokemon* this){
    int tipo=0;
    if(strcmp("Dragon",pkmn_getType1(this))==0||strcmp("Dragon",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoElectrico(Pokemon* this){
    int tipo=0;
    if(strcmp("Electrico",pkmn_getType1(this))==0||strcmp("Electrico",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoFantasma(Pokemon* this){
    int tipo=0;
    if(strcmp("Fantasma",pkmn_getType1(this))==0||strcmp("Fantasma",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoFuego(Pokemon* this){
    int tipo=0;
    if(strcmp("Fuego",pkmn_getType1(this))==0||strcmp("Fuego",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoHada(Pokemon* this){
    int tipo=0;
    if(strcmp("Hada",pkmn_getType1(this))==0||strcmp("Hada",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoHielo(Pokemon* this){
    int tipo=0;
    if(strcmp("Hielo",pkmn_getType1(this))==0||strcmp("Hielo",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoLucha(Pokemon* this){
    int tipo=0;
    if(strcmp("Lucha",pkmn_getType1(this))==0||strcmp("Lucha",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoNormal(Pokemon* this){
    int tipo=0;
    if(strcmp("Normal",pkmn_getType1(this))==0||strcmp("Normal",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoPlanta(Pokemon* this){
    int tipo=0;
    if(strcmp("Planta",pkmn_getType1(this))==0||strcmp("Planta",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoPsiquico(Pokemon* this){
    int tipo=0;
    if(strcmp("Psiquico",pkmn_getType1(this))==0||strcmp("Psiquico",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoRoca(Pokemon* this){
    int tipo=0;
    if(strcmp("Roca",pkmn_getType1(this))==0||strcmp("Roca",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoSiniestro(Pokemon* this){
    int tipo=0;
    if(strcmp("Siniestro",pkmn_getType1(this))==0||strcmp("Siniestro",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoTierra(Pokemon* this){
    int tipo=0;
    if(strcmp("Tierra",pkmn_getType1(this))==0||strcmp("Tierra",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoVeneno(Pokemon* this){
    int tipo=0;
    if(strcmp("Veneno",pkmn_getType1(this))==0||strcmp("Veneno",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}
int tipoVolador(Pokemon* this){
    int tipo=0;
    if(strcmp("Volador",pkmn_getType1(this))==0||strcmp("Volador",pkmn_getType2(this))==0)
        {tipo=1;}
    return tipo;
}

