//Objetivo: Simular uma bilheteria
//Autor: Diego da Costa Braga
//Data: 05/04/2019

#include <iostream>
#include "ingresso.h"
#include <stdbool.h>
#include <windows.h>

using namespace std;

int main()
{

    int escolha, x, y, lin, col, lin_troca, col_troca;

    cout<<"\t============="<<endl;
    cout<<"\t| Teatro RL |"<<endl;
    cout<<"\t============="<<endl;

    cout<<"Digite a quantidade de linhas: ";
    cin>>x;
    cout<<"Digite a quantidade de colunas: ";
    cin>>y;

    Ingresso ing(x,y);

    do{

        Sleep(1000);
        system("clear||cls");

        cout<<"\t============="<<endl;
        cout<<"\t| Teatro RL |"<<endl;
        cout<<"\t============="<<endl;

        for(int repete=0; repete<y; repete++)
            cout<<"=======";
        cout<<endl;

        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(ing.v[i*y+j]==true){
                    cout<<" | D | ";
                    //cout<<ing.cadeira[i][j]<<"   ";
                }

                else
                    cout<<" | V | ";
            }
            cout<<endl;
        }

        for(int repete=0; repete<y; repete++)
            cout<<"=======";
        cout<<endl;
        cout<<endl;

        cout<<"Vendas realizadas -> "<<ing.vendidos<<endl;
        cout<<endl;

        cout<<"1 - Venda"<<endl;
        cout<<"2 - Devolucao"<<endl;
        cout<<"3 - Troca"<<endl;
        cout<<"9 - Sair"<<endl;
        cout<<"Selecione -> ";
        cin>>escolha;

        switch (escolha){
        case 1:
            cout<<"Digite a fila: ";
            cin>>lin;
            cout<<"Digite a coluna: ";
            cin>>col;

            if(ing.isDisponivel(lin,col)){
                cout<<"===================="<<endl;
                cout<<"|Lugar indisponivel|"<<endl;
                cout<<"===================="<<endl;
            }
            else{
                ing.venda(lin, col);
                cout<<"\n================"<<endl;
                cout<<"|Confirmando...|"<<endl;
                cout<<"================"<<endl;
                Sleep(500);
                cout<<"\n============"<<endl;
                cout<<"|CONFIRMADO|"<<endl;
                cout<<"============"<<endl;
            }

            break;

        case 2:
            if(ing.vendidos!=0){
                cout<<"Digite a sua fila: ";
                cin>>lin;
                cout<<"Digite a sua coluna: ";
                cin>>col;

                if(!ing.isDisponivel(lin,col)){
                    cout<<"\n=================="<<endl;
                    cout<<"|Lugar esta vazio|"<<endl;
                    cout<<"=================="<<endl;
                }
                else{
                    ing.devolucao(lin,col);
                    cout<<"\n================"<<endl;
                    cout<<"|Confirmando...|"<<endl;
                    cout<<"================"<<endl;
                    Sleep(500);
                    cout<<"\n============"<<endl;
                    cout<<"|CONFIRMADO|"<<endl;
                    cout<<"============"<<endl;
                }
            }
            else{
                cout<<"\n========================================="<<endl;
                cout<<"|Nao eh possivel realizar a devolucao!!!|"<<endl;
                cout<<"========================================="<<endl;
            }

            break;

        case 3:
            if(ing.vendidos!=0){
                cout<<"Digite a sua fila: ";
                cin>>lin;
                cout<<"Digite a sua coluna: ";
                cin>>col;

                if(!ing.isDisponivel(lin,col)){
                    cout<<"\n=================="<<endl;
                    cout<<"|Lugar esta vazio|"<<endl;
                    cout<<"=================="<<endl;
                }
                else{
                    cout<<endl;
                    cout<<"Digite a sua nova fila: ";
                    cin>>lin_troca;
                    cout<<"Digite a sua nova coluna: ";
                    cin>>col_troca;

                    if(ing.isDisponivel(lin_troca,col_troca)){
                    cout<<"\n===================="<<endl;
                    cout<<"|Lugar indisponivel|"<<endl;
                    cout<<"===================="<<endl;

                    break;
                    }

                    ing.devolve(lin,col);
                    ing.troca(lin_troca,col_troca);

                    cout<<"\n================"<<endl;
                    cout<<"|Confirmando...|"<<endl;
                    cout<<"================"<<endl;
                    Sleep(500);
                    cout<<"\n============"<<endl;
                    cout<<"|CONFIRMADO|"<<endl;
                    cout<<"============"<<endl;
                }
            }
            else{
                cout<<"\n====================================="<<endl;
                cout<<"|Nao eh possivel realizar a troca!!!|"<<endl;
                cout<<"====================================="<<endl;
            }

            break;

        case 9:
            cout<<"Finalizando..."<<endl;
            break;

        default:
            cout<<"\n===================="<<endl;
            cout<<"=Escolha invalida!!="<<endl;
            cout<<"===================="<<endl;
        }

    }while(escolha!=9);

}
