#ifndef FILMES_H
#define FILMES_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "Datas.h"
using namespace std;
class Filmes{
    private:
        string m_nome;
	Datas m_estreia;
    public:
	Filmes(){
            m_nome = "nao-definido";
        }
        Filmes(string nomeFilme, Datas dataEstreia){
            m_nome=nomeFilme;
            m_estreia=dataEstreia;
        }
	void setNome(string nomeFilme){
            m_nome=nomeFilme;
        }
	void setEstreia(Datas dataEstreia){
            m_estreia=dataEstreia;
        }
	string getNome(){
            return m_nome;
        }
	Datas getEstreia(){
            return m_estreia;
        }
	~Filmes(){
            
        }
	friend bool operator == (Filmes filme1, Filmes filme2){
            return(
                (filme1.m_nome==filme2.m_estreia)&&
                (filme1.m_estreia.getAno()==filme2.m_estreia.getAno())
            );
	}
        friend bool operator < (Filmes filme1, Filmes filme2){
            return(filme1.m_estreia<filme2.m_estreia);
	}
        friend bool operator > (Filmes filme1, Filmes filme2){
            return(filme1.m_estreia>filme2.m_estreia);
	}
	friend ostream& operator << (std::ostream &saida, const Filmes &filme){
            return saida << "Filme: "<<filme.m_nome<<"\tData de Estreia: "<<filme.m_estreia<<endl;
	}
};
#endif /* FILMES_H */

