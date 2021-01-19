#ifndef DATAS_H
#define DATAS_H
#include <cstdlib>
#include <iostream>
#include <string> //Estratégias Utilizadas: https://www.youtube.com/watch?v=Vt6FIzLffaI ; https://www.youtube.com/watch?v=EX0yK9YwIGk ; https://www.youtube.com/watch?v=cPE8ogJ9f7g
using namespace std;
class Datas{//IDEIA: Usar uma Data como parametro de comparação
    private:
        string m_data;
    public:
        Datas(){
            m_data="DD/MM/AAAA";
        }
        Datas(string data){
            data.resize(10);// DD/MM/AAAA = 10 caracteres. toda string recebida terá seu tamanho redefinido para 10 caracteres, para permitir a analise e conversão.
            string dia = data.substr(0,2); //DD  ->  String P3 (7:03)
            int Dia = stoi(dia); //String P3 (11:07)    Técnica de Java: transformar string em int     
            string mes = data.substr(3,2);// MM
            int Mes = stoi(mes);
            string ano = data.substr(6,4);// AAAA    as / não podem ser contabiizadas
            int Ano = stoi(ano);
            if(Dia<=0||Dia>31 || Mes<=0||Mes>12 || Ano<1000 || (Dia>29 && Mes==2) || (Dia>30 && (Mes==4||Mes==6||Mes==9||Mes==11))){
                throw "Data Invalida!";
            }
            m_data = data;
        }
        string getDia(){
            string dia = m_data.substr(0,2);
            return dia;
        }
        string getMes(){
            string mes = m_data.substr(3,2);
            return mes;
        }
        string getAno(){
            string ano = m_data.substr(6,4);
            return ano;
        }
        ~Datas(){
            
        }
        friend bool operator == (Datas data1, Datas data2){
            return data1.m_data.compare(data2.m_data); //String P3 (9:02)
	}
        friend bool operator < (Datas data1, Datas data2){
            string dia1 = data1.getDia();
            int Dia1 = stoi(dia1);             
            string mes1 = data1.getMes();
            int Mes1 = stoi(mes1);
            string ano1 = data1.getAno();
            int Ano1 = stoi(ano1);
            string dia2 = data2.getDia();
            int Dia2 = stoi(dia2);             
            string mes2 = data2.getMes();
            int Mes2 = stoi(mes2);
            string ano2 = data2.getAno();
            int Ano2 = stoi(ano2);
            if(Ano1<Ano2)
                return true;
            else if(Ano1==Ano2){ // podem ter o mesmo ano, mas ter mes e dia diferentes. precisam de verificação.
                if(Mes1<Mes2)
                    return true;
                else if(Mes1==Mes2){
                    if(Dia1<Dia2)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
	}
        friend bool operator > (Datas data1, Datas data2){
            string dia1 = data1.getDia();
            int Dia1 = stoi(dia1);             
            string mes1 = data1.getMes();
            int Mes1 = stoi(mes1);
            string ano1 = data1.getAno();
            int Ano1 = stoi(ano1);
            string dia2 = data2.getDia();
            int Dia2 = stoi(dia2);             
            string mes2 = data2.getMes();
            int Mes2 = stoi(mes2);
            string ano2 = data2.getAno();
            int Ano2 = stoi(ano2);
            if(Ano1>Ano2)
                return true;
            else if(Ano1==Ano2){
                if(Mes1>Mes2)
                    return true;
                else if(Mes1==Mes2){
                    if(Dia1>Dia2)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
	}
        friend ostream& operator << (std::ostream &saida, const Datas &data){
            return saida<<data.m_data;
	}
};
#endif /* DATAS_H */
