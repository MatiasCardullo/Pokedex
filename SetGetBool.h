#ifndef SetGetBool_H_INCLUDED
#define SetGetBool_H_INCLUDED
#include "ArrayList.h"

//SETTERS
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

//GETTERS
int getPositiveNumber();
char* getString(int,char*);
char* getTrueOrFalse(char*);
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

//BOOLEAN
int trueOrFalse();
int isLegendary(Pokemon*);
int isMegaOrPrimal(Pokemon*);
int isGeneration1(Pokemon*);
int isGeneration2(Pokemon*);
int isGeneration3(Pokemon*);
int isGeneration4(Pokemon*);
int isGeneration5(Pokemon*);
int isGeneration6(Pokemon*);
int isGeneration7(Pokemon*);
int tipoAcero(Pokemon*);
int tipoAgua(Pokemon*);
int tipoBicho(Pokemon*);
int tipoDragon(Pokemon*);
int tipoElectrico(Pokemon*);
int tipoFantasma(Pokemon*);
int tipoFuego(Pokemon*);
int tipoHada(Pokemon*);
int tipoHielo(Pokemon*);
int tipoLucha(Pokemon*);
int tipoNormal(Pokemon*);
int tipoPlanta(Pokemon*);
int tipoPsiquico(Pokemon*);
int tipoRoca(Pokemon*);
int tipoSiniestro(Pokemon*);
int tipoTierra(Pokemon*);
int tipoVeneno(Pokemon*);
int tipoVolador(Pokemon*);

#endif // SetGetBool_H_INCLUDED
