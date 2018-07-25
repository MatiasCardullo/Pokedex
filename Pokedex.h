#ifndef Pokemon_H_INCLUDED
#define Pokemon_H_INCLUDED
#include "ArrayList.h"

struct S_Pokemon{
  int index,idPokedex;
  char name[50],type1[10],type2[10];
  int statsTotal,HP,attack,defense,spAtk,spDef,speed,generation;
  char legendary[6],alola[6],megaOrPrimal[7];
};
typedef struct S_Pokemon Pokemon;

Pokemon* pkmn_new(void);

int menu();
int menuListas(ArrayList*);
int menuTipos(ArrayList*);
int menuGeneracion(ArrayList*);

int addPokemon(ArrayList*);
//int modifyPokemon(ArrayList*);
//int removePokemon(ArrayList*);

int isGeneration(Pokemon*);
void listStats(Pokemon*);
void listStatsPokemon(Pokemon*);
void listStatsPokemonSinGeneracion(Pokemon*);
void listStatsPokemonSinLegendario(Pokemon*);
void listBiologic(Pokemon*);
void listBiologicPokemon(Pokemon*);
void listBiologicPokemonSinGeneracion(Pokemon*);
void listBiologicPokemonSinLegendario(Pokemon*);

int searchPokemon(ArrayList*);

char* chooseType(char*);

int chooseGeneration();

#endif // Pokemon_H_INCLUDED
