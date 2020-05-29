#ifndef ARVORE_H
#define	ARVORE_H

#include <ostream>
#include <string>

using std::ostream;
using std::string;
namespace prglib {
    
template <typename T> class arvore {
 public:
  arvore();
  //arvore(const arvore<T> & outra);
  arvore(const T & dado);
  ~arvore();

  void adiciona(const T& algo);
  T& obtem(const T & algo);
  
  //Adiciona os dados ordenados em uma lista
  void listeInOrder(lista<T> & result);
  
  //Adiciona em uma lista os dados com a mesma topologia da arvore
  void listePreOrder(lista<T> & result);
  
  void listePostOrder(lista<T> & result);
  
  //Lista os nodos de cada nível por vez, da esquerda pra direita
  void listeEmLargura(lista<T> & result);
  
  //Retorna a quantidade de dados na árvore
  unsigned int tamanho() const;  
  
  //Retorna a altura da folha mais profunda
  unsigned int altura() ;
  int fatorB() ;
  arvore<T> * balanceia();
  arvore<T> * balanceia(bool otimo);
  
  void inicia();
  bool fim();
  T& proximo();

  void iniciaPeloFim();
  bool inicio();
  T& anterior();
  
  //Remove um dado
  T remove(const T & algo);
  
  //Obtém uma referência ao menor dado
  const T & obtemMenor() const;
  
  //Obtém uma referência ao maior dado
  const T & obtemMaior() const;
  
  //Obtém uma lista com os dados menores ou maiores que algo
  void obtemMenoresQue(lista<T> & result, const T & algo);
  void obtemMaioresQue(lista<T> & result, const T & algo);
  void escrevaSe(ostream & out) const;
  
  arvore<T> * rotacionaL();     
  arvore<T> * rotacionaR(); 

  //Obtém todos valores entre "start" e "end" (inclusive)
  void obtemIntervalo(lista<T> & result, const T & start, const T & end);
 protected:
     T data;
     arvore<T> * esq, * dir; 
     
    lista <arvore <T>*> *stack;
     
       
};

} // fim do namespace

#include <libs/arvore-impl.h>

#endif	/* ARVORE_H */

