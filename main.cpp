#include <cstdlib>
#include <iostream>
#include <string>
#include "BinaryNode.h"
#include "Filmes.h"
#include "Datas.h"
#include "BinarySearchTree.h"
using namespace std;
int main(int argc, char** argv) {
    /*string data;
    string data1("09/03/2002");
    string data2("10/03/2002");
    string teste = data1.substr(0,2);
    int teste1 = stoi(teste);
    cout<<teste1<<endl;
    if(data1<data2)
        cout<<"deu certo"<<endl;
    else
        cout<<"deu errado"<<endl;
    cout<<data1<<" "<<data2<<endl;
    getline(cin,data);
    try{
        Datas teste = Datas(data);
        cout<<"excelente"<<endl;
    }
    catch(const char *exceçao){
        cout<<exceçao<<endl;
    }*/ //testes data.
    int inicio, aplicacao, encontrar, registrar, remover, ordem, outraOrdem;
    string nome, data;
    Datas estreia;
    BinarySearchTree<Filmes> ABBFilmes = BinarySearchTree<Filmes>();
    cout<<"AVISO: TALVEZ SEJA NECESSARIO ROLAR A TELA DE EXECUCAO APOS SOLICITAR UMA OPERACAO!"<<endl;
    cout<<"CASO PREZE PELA ESTETICA, FAVOR DIFERENCIAR LETRAS MAIUSCULAS E MINUSCULAS AO INSERIR DADOS"<<endl;
    //system("pause");
    //system("cls");
    ABBFilmes.insert(Filmes("Jurassic Park",Datas("11/06/1993")));
    ABBFilmes.insert(Filmes("Rambo",Datas("06/11/1982")));
    ABBFilmes.insert(Filmes("De Volta para o Futuro",Datas("03/07/1985")));
    ABBFilmes.insert(Filmes("Rocky: Um Lutador",Datas("03/12/1976")));
    ABBFilmes.insert(Filmes("Homem de Ferro",Datas("12/04/2008")));
    ABBFilmes.insert(Filmes("X-Men: O Filme",Datas("14/07/2000")));
    ABBFilmes.insert(Filmes("Coringa",Datas("04/10/2019")));//teste de AVL;
    //system("pause");
    //system("cls");
    cout<<"Ola, Seja Bem Vindo!"<<endl;
    cout<<"Deseja Iniciar? (1-SIM, 2-NAO)"<<endl;
    cin>>inicio;
    switch(inicio){
        case 1:
            do{
                cout<<"***********************************************************************************"<<endl;
		cout<<"E agora, o que voce deseja?"<<endl;
		cout<<"\t1-\tSaber se esta arvore contem filmes."<<endl;
		cout<<"\t2-\tSaber qual o filme mais antigo desta arvore."<<endl;
		cout<<"\t3-\tSaber qual o filme mais recente desta arvore."<<endl;
		cout<<"\t4-\tSaber se o filme solicitado esta registrado nesta arvore."<<endl;
		cout<<"\t5-\tRegistrar um filme nesta arvore."<<endl;
		cout<<"\t6-\tRemover um filme desta arvore."<<endl;
		cout<<"\t7-\tVisualizar todos os filmes registrados nesta arvore."<<endl;
                cout<<"\t8-\tLimpar arvore."<<endl;
                //cout<<"\t9- Limpar Tela."<<endl;"
		cout<<"\t9-\tEncerrar."<<endl;
		cout<<"***********************************************************************************"<<endl;
		cout<<endl;
		cin>>aplicacao;
                cin.ignore();
		switch(aplicacao){
                    case 1:
			if(ABBFilmes.isEmpty()){
                            cout<<"Nao, nao existem filmes registrados nesta arvore!"<<endl;
			}
			else{
                            cout<<"Sim, existem filmes registrados nesta arvore!"<<endl;
			}
			break;
                    case 2:
			try{
                            cout<<"Resultado de Busca ->\t"<<ABBFilmes.findMin()<<endl;                            
                        }
                        catch(const char *exceArvore){
                            cout<<exceArvore<<endl;
                        }
			break;
                    case 3:
			try{
                            cout<<"Resultado de Busca ->\t"<<ABBFilmes.findMax()<<endl;                            
                        }
                        catch(const char *exceArvore){
                            cout<<exceArvore<<endl;
                        }                   
			break;
                    case 4:
                        if(ABBFilmes.isEmpty()){
                            cout<<"Arvore Vazia! Deseja Continuar Mesmo Assim? SIM-1 NAO-2"<<endl;
                            cin>>encontrar;
                            cin.ignore();
                            if(encontrar>2 || encontrar<=0)
                                cout<<"Opcao Invalida! A Aplicacao Retornara ao Menu!"<<endl;
                        }
                        else
                            encontrar=1;
                        while(encontrar==1){
                            cout<<"Informe o nome desejado:"<<endl;
                            getline(cin,nome);
                            cout<<"Informe a data de estreia nos EUA (DD/MM/AAAA, APENAS NUMEROS e BARRAS):"<<endl;
                            getline(cin,data);
                            try{//tente validar a data.
                                estreia = Datas(data);
                                if(ABBFilmes.find(Filmes(nome,estreia)))
                                    cout<<"Filme Encontrado!"<<endl;
                                else
                                    cout<<"Filme Nao Encontrado!"<<endl;
                            }
                            catch(const char *exceData){
                                cout<<exceData<<endl;
                            }
                            cout<<"Deseja tentar novamente? SIM-1, NAO-2"<<endl;
                            cin>>encontrar;
                            cin.ignore();
                            if(encontrar>2 || encontrar<=0)
                                cout<<"Opcao Invalida! A Aplicacao Retornara ao Menu!"<<endl;
                        }
                        break;
                    case 5:
			do{
                            cout<<"Informe o nome do filme"<<endl;
                            getline(cin,nome);
                            cout<<"Informe a data de estreia nos EUA (DD/MM/AAAA, APENAS NUMEROS e BARRAS!)"<<endl;
                            getline(cin,data);
                            try{
                                estreia = Datas(data);
                                ABBFilmes.insert(Filmes(nome,data));
                                cout<<"Filme Registrado!"<<endl;
                            }
                            catch(const char *exceData){
                                cout<<exceData<<endl;
                            }
                            cout<<"Deseja tentar novamente? SIM-1, NAO-2"<<endl;
                            cin>>registrar;
                            cin.ignore();
                            if(registrar>2)
                                cout<<"Opcao Invalida! A Aplicacao Retornara ao Menu!"<<endl;
                        }while(registrar!=2);
                        break;
                    case 6:
                        if(ABBFilmes.isEmpty()){
                            cout<<"Arvore Vazia! A Aplicacao Retornara ao Menu!"<<endl;
                        }
                        else{
                            do{
                                cout<<"Informe o nome do filme"<<endl;
                                getline(cin,nome);
                                cout<<"Informe a data de estreia nos EUA (DD/MM/AAAA, APENAS NUMEROS e BARRAS)"<<endl;
                                getline(cin,data);
                                try{
                                    estreia = Datas(data);
                                    ABBFilmes.remove(Filmes(nome,data));
                                    cout<<"Filme Removido!"<<endl;
                                }
                                catch(const char *exceData){
                                    cout<<exceData<<endl;
                                }
                                cout<<"Deseja tentar novamente? SIM-1, NAO-2"<<endl;
                                cin>>remover;
                                cin.ignore();
                                if(remover>2 || remover<=0)
                                    cout<<"Opcao Invalida! A Aplicacao Retornara ao Menu!"<<endl;
                            }while(remover==1);
                        }
                        break;
                    case 7:
                        if(ABBFilmes.isEmpty()){
                            cout<<"Arvore Vazia! A Aplicacao Retornara ao Menu!"<<endl;
                        }
                        else{
                            do{
                                cout<<"Escolha a ordem de exibicao: -1==PreOrdem, 0==EmOrdem, 1==PosOrdem"<<endl;
                                cin>>ordem;
                                cin.ignore();
                                ABBFilmes.print(ordem);
                                cout<<"Deseja escolher outra ordem de exibicao? SIM-1, NA0-2"<<endl;                            
                                cin>>outraOrdem;
                                cin.ignore();
                                if(outraOrdem>2 || outraOrdem<=0)
                                    cout<<"Opcao Invalida! A Aplicacao Retornara ao Menu!"<<endl;
                            }while(outraOrdem==1);
                        }
			break;
                    case 8:
			try{
                            ABBFilmes.clear();                            
                        }
                        catch(const char *exceArvore){
                            cout<<exceArvore<<" A Aplicacao Retornara ao Menu!"<<endl;
                        }
			break;
                    case 9:
			//system("cls");
			break;
                    default:
			cout<<"Opcao Invalida! A Aplicacao Sera Encerrada!"<<endl;
			break;
		}
            }while(aplicacao>0 && aplicacao<9);
            break;
	case 2:
            break;
	default:
            cout<<"Opcao Invalida! A Aplicacao Sera Encerrada!"<<endl;
            break;
    }
    cout<<"Aplicação Encerrada!"<<endl;

    return 0;
}

