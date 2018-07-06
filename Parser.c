#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Pokedex.h"

int parser_pokedex(char* fileName, ArrayList* listaPokemons)
{
    char id[4], nombre[50], tipo1[10], tipo2[10], statsTotal[4];
    char HP[4], atk[4], def[4], atkEspecial[4], defEspecial[4], velocidad[4];
    char generacion[2], legendario[6], mega_o_primal[7];
    int ok=1,cant,index=0;
    FILE* pFile;
    pFile= fopen(fileName, "r");
    if((pFile)==NULL){
        printf("No se pudo abrir el archivo.\n");
        system("pause");
        ok=0;
    }fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,tipo1,tipo2,statsTotal,HP,atk,def,atkEspecial,defEspecial,velocidad,generacion,legendario,mega_o_primal);
    while(!feof(pFile)){
        cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,tipo1,tipo2,statsTotal,HP,atk,def,atkEspecial,defEspecial,velocidad,generacion,legendario,mega_o_primal);
        if(cant!=14){
            if(feof(pFile))
                {break;}
            else{
                printf("Error.\n");
                system("pause");
                ok=0;break;
            }
        }else{index++;}
        Pokemon* eAux=pkmn_new();
        pkmn_setIndex(eAux,index);
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
        listaPokemons->add(listaPokemons,eAux);
    }fclose(pFile);
    return ok; // OK
}

/*int generarArchivoSueldos(char* fileName,ArrayList* listaPokemons)
{
    FILE* f;
    Pokemon* Pokemon = pkmn_new();
    char estado[50];
    int returnAux = 0;
    int i;
    if(listaPokemons != NULL){
        f = fopen(fileName, "w");
        if(f != NULL){
            fprintf(f,"id,nombre,horas_trabajadas,sueldo\n");
            for(i=0; i<listaPokemons->len(listaPokemons); i++){
                Pokemon = listaPokemons->get(listaPokemons,i);
                //fprintf(f,"%d,%s,%d,%.2f\n",pkmn_getId(Pokemon),pkmn_getName(Pokemon),pkmn_getHorasTrabajadas(Pokemon),pkmn_getSueldo(Pokemon));
            }fclose(f);
            for(i=0;i<listaPokemons->len(listaPokemons);i++){
                  Pokemon = listaPokemons->get(listaPokemons,i);
                  free(Pokemon);
            }listaPokemons->deleteArrayList(listaPokemons);
        }returnAux = 1;
    }return returnAux;
}*/
