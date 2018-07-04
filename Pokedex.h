#ifndef Pokemon_H_INCLUDED
#define Pokemon_H_INCLUDED
#include "ArrayList.h"

struct S_Pokemon
{
  int index,idPokedex;
  char name[50],type1[10],type2[10];
  int statsTotal,HP,attack,defense,spAtk,spDef,speed,generation;
  char legendary[6],megaOrPrimal[6];
};
typedef struct S_Pokemon Pokemon;

char menuListas();
Pokemon* pkmn_new(void);
int isLegendary(Pokemon*);
int isMegaOrPrimal(Pokemon*);
char* isGeneration(Pokemon*);
void mostrarPokemon(Pokemon*);
void mostrarPokemonSinGeneracion(Pokemon*);
void mostrarPokemonSinLegendario(Pokemon*);

void pkmn_setIndex(Pokemon*, int);
void pkmn_setIdPokedex(Pokemon*, int);
void pkmn_setName(Pokemon*, char*);
void pkmn_setType1(Pokemon*, char*);
void pkmn_setType2(Pokemon*, char*);
void pkmn_setStatsTotal(Pokemon*, int);
void pkmn_setHP(Pokemon*, int);
void pkmn_setAttack(Pokemon*, int);
void pkmn_setDefense(Pokemon*, int);
void pkmn_setSpAtk(Pokemon*, int);
void pkmn_setSpDef(Pokemon*, int);
void pkmn_setSpeed(Pokemon*, int);
void pkmn_setGeneration(Pokemon*, int);
void pkmn_setLegendary(Pokemon*, char*);
void pkmn_setMegaOrPrimal(Pokemon*, char*);

int pkmn_getIndex(Pokemon*);
int pkmn_getIdPokedex(Pokemon*);
char* pkmn_getName(Pokemon*);
char* pkmn_getType1(Pokemon*);
char* pkmn_getType2(Pokemon*);
int pkmn_getStatsTotal(Pokemon*);
int pkmn_getHP(Pokemon*);
int pkmn_getAttack(Pokemon*);
int pkmn_getDefense(Pokemon*);
int pkmn_getSpAtk(Pokemon*);
int pkmn_getSpDef(Pokemon*);
int pkmn_getSpeed(Pokemon*);
int pkmn_getGeneration(Pokemon*);
char* pkmn_getLegendary(Pokemon*);
char* pkmn_getMegaOrPrimal(Pokemon*);

#endif // Pokemon_H_INCLUDED
