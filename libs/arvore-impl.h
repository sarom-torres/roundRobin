#ifndef ARVORE_IMPL_H
#define	ARVORE_IMPL_H

#include "arvore.h"
#include "lista.h"


namespace prglib {

template <typename T> arvore<T>::~arvore() {    
}
    
template <typename T> arvore<T>::arvore() {    
}

template <typename T> arvore<T>::arvore(const T & dado) { 
    
    data = dado;
    esq = nullptr;
    dir = nullptr;
    stack = nullptr;
}

template <typename T> void arvore<T>::adiciona(const T & algo) {
    
    arvore<T> * atual = this;
    
    while(true){
        if(algo == atual->data){
            atual->data = algo;
            break;
        }
        
        if(algo < atual->data){
            if(atual-> esq != nullptr) atual = atual->esq;
            else{
                arvore <T> *arv = new arvore<T> (algo); 
                atual->esq = arv;
                break;
            }
        }else{
            if(atual->dir != nullptr) atual = atual->dir;
            else{
                arvore <T> *arv = new arvore<T> (algo); 
                atual->dir = arv;
                break;
            }
        }
    }
    
    
    /*
    //Versão recursiva
    if(algo == data) data = algo;
    else if(algo < data){
        if(esq != nullptr) esq->adiciona(algo);
        else esq = new arvore <T>(algo);
    }else{
        if(dir != nullptr) dir->adiciona(algo);
        else dir = new arvore<T>(algo);
    }*/
    
 
}

template <typename T> T& arvore<T>::obtem(const T & algo) {
    
    arvore <T> * atual= this;
            
    while(atual != nullptr){
        if(atual->data == algo) return atual->data;
        
        if(algo < atual->data) atual = atual->esq;  
        else atual = atual->dir;
    }
    
    throw 666;  
}

template <typename T> void arvore<T>::listeEmLargura(lista<T> & result) {
    
    lista <arvore <T>*> laux;
    
    laux.anexa(this);
    
    while(!laux.vazia()){
        arvore <T> * atual= laux.remove(0);
        if(atual->esq) laux.anexa(atual->esq);
        if(atual->dir) laux.anexa(atual->dir);
        result.anexa(atual->data);   
    }
}

template <typename T> void arvore<T>::listeInOrder(lista<T> & result) {
 
   /* Versão recursiva
    if(esq) esq->listeInOrder(result);
    result.anexa(data);
    if(dir) dir->listeInOrder(result);
    */
    
    
    lista <arvore <T> *> l;
    
    arvore <T> *atual = this;
    
    while(atual != nullptr){  
        l.insere(atual);
        atual = atual->esq;
    }
    
    arvore <T> * ptr;
    
    while(!l.vazia()){
        ptr = l.remove(0);
        result.anexa(ptr->data);
        if(ptr->dir){ 
            ptr = ptr->dir;
            while(ptr != nullptr){
                l.insere(ptr);
                ptr = ptr->esq;
                   
            }
        }
    }

    
}

template <typename T> void arvore<T>::listePreOrder(lista<T> & result) {
    
    /*Versão recursiva
    result.anexa(data);
    if(esq) esq->listePreOrder(result);
    if(dir) dir->listePreOrder(result);*/
    
    
    
    lista <arvore <T>*> l;
    
    l.insere(this);
    
    while(!l.vazia()){
        arvore <T> * atual = l.remove(0);
        
        result.anexa(atual->data);
        
        
        if(atual->dir) l.insere(atual->dir);
        if(atual->esq) l.insere(atual->esq);
        
        
        

    }
}

template <typename T> void arvore<T>::listePostOrder(lista<T> & result) {
    
    if(esq) esq->listePostOrder(result);
    if(dir) dir->listePostOrder(result);
    result.anexa(data);
    
}

template <typename T> unsigned int arvore<T>::tamanho() const {
}

template <typename T> int arvore<T>::fatorB()  {
    
    int he = 0;
    int hd = 0;
    int fb = 0;
    
    if(esq!=nullptr) he =1+ esq->altura();
    if(dir!= nullptr) hd = 1+ dir->altura();
    
    fb = he-hd;
    return fb;
    
}

template <typename T> unsigned int arvore<T>::altura()  {
    
    int alt_esq= 0, alt_dir=0;
    
    if(esq!=nullptr) alt_esq =1+ esq->altura(); 
    if(dir!=nullptr) alt_dir = 1+ dir->altura();
    
    if(alt_esq > alt_dir) return alt_esq;
    return alt_dir;
       
}

template <typename T> arvore<T>* arvore<T>::balanceia() {
    
    arvore <T>* raiz = this;
    int fb;
    
    if (esq) esq = esq->balanceia();
    if (dir) dir = dir->balanceia();
    
    fb = raiz->fatorB();
    
    while(fb< -1){
       if(raiz->dir->fatorB() > 0) raiz->dir =  raiz->dir->rotacionaR();
       raiz = raiz->rotacionaL();
       
       fb = raiz->fatorB();
    }    
    
    while(fb > 1){
        if(raiz->esq->fatorB() < 0) raiz->esq = raiz->esq->rotacionaL();
        raiz = raiz->rotacionaR();
        
        fb = raiz->fatorB();
    }
    
    return raiz;
    
}

template <typename T> arvore<T>* arvore<T>::balanceia(bool otimo) {
}

template <typename T> void arvore<T>::inicia() {
    /*
    stack.esvazia();
    stack.insere(this);*/
    
    
    stack = new lista<arvore<T>*>;
   
    arvore <T> *atual = this;
    
    while(atual != nullptr){  
        stack->insere(atual);
        atual = atual->esq;
    }
    
    
}

template <typename T> T& arvore<T>::proximo() {
    
    /*  Pre Order 
    auto atual = stack.remove(0);
    if(atual->dir) stack.insere(atual->dir);
    if(atual->esq) stack.insere(atual->esq);

    return atual->data;*/
    
    arvore <T> *atual = stack->remove(0);
    T &dado = atual->data;
    
    if(atual->dir){
        atual = atual->dir;
        while(atual != nullptr){
            stack->insere(atual);
            atual = atual->esq;
        }
    }

    if(stack->vazia()){
        delete stack;
        stack = nullptr;
    }
    return dado;   
}

template <typename T> bool arvore<T>::fim() {
    
    return stack==nullptr;
}

template <typename T> const T& arvore<T>::obtemMenor() const{
    
    const arvore <T> * menor = this;
    
    while(menor->esq != nullptr){
        menor = menor->esq;
    }
    
    return menor->data;  
}

template <typename T> const T& arvore<T>::obtemMaior() const{
    
    const arvore<T> * maior = this;
    
    while(maior->dir != nullptr){
        maior = maior->dir;
    }
    
    return maior->data;  
}

template <typename T> arvore<T>* arvore<T>::rotacionaR(){
    
    arvore <T>* nodoA = this;
    arvore <T> * nodoB = esq;
    arvore <T> * nodoC = nodoB->dir;
 
    nodoA->esq = nodoC;
    nodoB->dir = nodoA;
    
    return nodoB;
}


template <typename T> arvore<T>* arvore<T>::rotacionaL(){
    
    arvore <T>* nodoA = this;
    arvore <T>* nodoB = dir;
    arvore <T>* nodoC = nodoB->esq;
    
    nodoB->esq = nodoA;
    nodoA->dir = nodoC;
    
    return nodoB;

}

template <typename T> void arvore<T>::obtemMenoresQue(lista<T> & result, const T & algo) {
}

template <typename T> void arvore<T>::obtemMaioresQue(lista<T> & result, const T & algo) {
}

template <typename T> void arvore<T>::obtemIntervalo(lista<T>& result, const T& start, const T& end) {
}

 
template <typename T> void arvore<T>::escrevaSe(ostream& out) const {
    static int nivel = -1;
    string prefixo;
 
    nivel++;
    prefixo.append(nivel, ' ');
 
    if (dir) dir->escrevaSe(out);
    out << prefixo << data << std::endl;
    if (esq) esq->escrevaSe(out);
    nivel--;
}



};

#endif	/* ARVORE_IMPL_H */

