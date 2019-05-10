//Objetivo: Simular uma bilheteria
//Autor: Diego da Costa Braga
//Data: 05/04/2019

#ifndef INGRESSO_H_INCLUDED
#define INGRESSO_H_INCLUDED
#include "stdlib.h"
#include <stdbool.h>


using namespace std;

struct Ingresso{

    bool *v;
    int LINHA, COLUNA;

    //bool cadeira[LINHA][COLUNA];
    unsigned int vendidos=0;

    Ingresso(int lin,int col){
        LINHA = lin;
        COLUNA = col;
        v=new bool[lin*col];
        for(int i=0;i<LINHA;i++){
            for(int j=0;j<COLUNA;j++){
                v[i*col+j]=true;
                //cadeira[i][j]=true;
            }
        }
    }

    bool isDisponivel(int linha, int coluna){
        //return !cadeira[linha-1][coluna-1];
        return !v[(linha-1)*COLUNA+(coluna-1)];

        /*if(cadeira[linha][coluna]==true){
            return false;
        }
        else
            return true;*/

    }

    void venda(int linha, int coluna){
        vendidos++;
        v[(linha-1)*COLUNA+(coluna-1)]=false;
        //cadeira[linha-1][coluna-1]=false;
    }

    void devolucao(int linha, int coluna){
        vendidos--;
        v[(linha-1)*COLUNA+(coluna-1)]=true;
        //cadeira[linha-1][coluna-1]=true;
    }

    void troca(int linha, int coluna){
        v[(linha-1)*COLUNA+(coluna-1)]=false;
        //cadeira[linha-1][coluna-1]=false;
    }

    void devolve(int linha, int coluna){
        v[(linha-1)*COLUNA+(coluna-1)]=true;
        //cadeira[linha-1][coluna-1]=true;
    }

    /*void vetor(int linha, int coluna){
        int i,col,j;
        int *v;

        v=i*col+j;
    }*/

};

#endif // INGRESSO_H_INCLUDED
