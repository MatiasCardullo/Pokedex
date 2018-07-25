#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Pokedex.h"

int parser_pokedex(char* fileName, ArrayList* listaPokemons)
{
    char id[4], nombre[50], tipo1[10], tipo2[10], statsTotal[5];
    char HP[4], atk[4], def[4], atkEspecial[4], defEspecial[4], velocidad[4];
    char generacion[2], legendario[6], mega_o_primal[7], alola[6];
    int ok=1,cant;
    FILE* pFile;
    pFile= fopen(fileName, "r");
    if((pFile)==NULL){
        printf("No se pudo abrir el archivo.\n");
        system("pause");
        ok=0;
    }fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,tipo1,tipo2,statsTotal,HP,atk,def,atkEspecial,defEspecial,velocidad,generacion,legendario,mega_o_primal,alola);
    while(!feof(pFile)){
        cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,tipo1,tipo2,statsTotal,HP,atk,def,atkEspecial,defEspecial,velocidad,generacion,legendario,mega_o_primal,alola);
        if(cant!=15){
            if(feof(pFile))
                {break;}
            else{
                printf("Error.\n");
                system("pause");
                ok=0;break;
            }
        }
        Pokemon* eAux=pkmn_new();
        pkmn_setIdPokedex(eAux,atoi(id));
        pkmn_setName(eAux,nombre);
        pkmn_setType1(eAux,tipo1);
        pkmn_setType2(eAux,tipo2);
        pkmn_setStatsTotal(eAux,atoi(statsTotal));
        pkmn_setHP(eAux,atoi(HP));
        pkmn_setAttack(eAux,atoi(atk));
        pkmn_setDefense(eAux,atoi(def));
        pkmn_setSpAtk(eAux,atoi(atkEspecial));
        pkmn_setSpDef(eAux,atoi(defEspecial));
        pkmn_setSpeed(eAux,atoi(velocidad));
        pkmn_setGeneration(eAux,atoi(generacion));
        pkmn_setLegendary(eAux,legendario);
        pkmn_setMegaOrPrimal(eAux,mega_o_primal);
        pkmn_setAlola(eAux,alola);
        listaPokemons->add(listaPokemons,eAux);
    }fclose(pFile);
    return ok; // OK
}

int crear_pokedex(char* fileName,ArrayList* listaPokemons)
{
    FILE* f;
    Pokemon* Pokemon = pkmn_new();
    int returnAux = 0;
    int i;
    if(listaPokemons != NULL){
        f = fopen(fileName, "w");
        if(f != NULL){
            fprintf(f,"Id,Name,Type 1,Type 2,statsTotal,HP,attack,defense,spAtk,spDef,Speed,Generation,Legendary,Mega or primal,Alola\n");
            for(i=0; i<listaPokemons->len(listaPokemons); i++){
                Pokemon = listaPokemons->get(listaPokemons,i);
                fprintf(f,"%d,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%s,%s,%s\n",pkmn_getIdPokedex(Pokemon),pkmn_getName(Pokemon),pkmn_getType1(Pokemon),pkmn_getType2(Pokemon),pkmn_getStatsTotal(Pokemon),pkmn_getHP(Pokemon),pkmn_getAttack(Pokemon),pkmn_getDefense(Pokemon),pkmn_getSpAtk(Pokemon),pkmn_getSpDef(Pokemon),pkmn_getSpeed(Pokemon),pkmn_getGeneration(Pokemon),pkmn_getLegendary(Pokemon),pkmn_getMegaOrPrimal(Pokemon),pkmn_getAlola(Pokemon));
            }fclose(f);

        }returnAux = 1;
    listaPokemons->deleteArrayList(listaPokemons);
    }free(Pokemon);
    return returnAux;
}
