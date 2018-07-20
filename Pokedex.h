#ifndef Pokemon_H_INCLUDED
#define Pokemon_H_INCLUDED
#include "ArrayList.h"

struct S_Pokemon{
  int index,idPokedex;
  char name[50],type1[10],type2[10];
  int statsTotal,HP,attack,defense,spAtk,spDef,speed,generation;
  char legendary[6],megaOrPrimal[7];
};
typedef struct S_Pokemon Pokemon;

Pokemon* pkmn_new(void);

void menuListas(ArrayList*);

void menuTipos(ArrayList*);

void menuGeneracion(ArrayList*);

int isGeneration(Pokemon*);

void mostrarPokemon(Pokemon*);

void mostrarPokemonSinGeneracion(Pokemon*);

void mostrarPokemonSinLegendario(Pokemon*);

#endif // Pokemon_H_INCLUDED
