#ifndef PILHA_IMPL_H
#define	PILHA_IMPL_H

#include "pilha.h"


namespace prglib {
    
template <typename T> pilha<T>::pilha(unsigned int umaCapacidade) {
    
    if(umaCapacidade == 0) throw 666;
    
    N = umaCapacidade;
    
    buffer = new T[N];
    
    topo=0;
}
 
template <typename T> pilha<T>::pilha(const pilha& outra) {
    
    N = outra.N;
    buffer = new T[N];
    
    for(int i=0;i<N;i++)
        buffer[i] = outra.buffer[i];
    
    topo = outra.topo;
}
 
template <typename T> pilha<T>::~pilha() {
    delete[] buffer;
}

template <typename T> pilha<T> & pilha<T>::operator=(const pilha<T> & outra) {
    
    N = outra.N;
    delete[] buffer;
    buffer = new T[N];
    
    for(int i=0;i<N;i++)
        buffer[i] = outra.buffer[i];
    
    topo = outra.topo;
    
}
 
template <typename T> void pilha<T>::esvazia() {
    topo = 0;
}
 
template <typename T> void pilha<T>::push(const T & dado) {
    
    if(topo == N) throw 666;
    
    buffer[topo] = dado;
    topo++;
}
 
template <typename T> T pilha<T>::pop() {
    if(topo == 0) throw 666;
    
    T aux = buffer[topo-1];
    
    topo--;
    
    return aux;
}
 
template <typename T> const T& pilha<T>::top() const{
    
    if(topo > 0) return buffer[topo-1];
    else return buffer[topo];
}

template <typename T> unsigned int pilha<T>::capacidade() const {
    return N;
}

template <typename T> bool pilha<T>::cheia() const {
    return topo == N;
}

template <typename T> bool pilha<T>::vazia() const {
    return topo == 0; 
}

template <typename T> unsigned int pilha<T>::comprimento() const {
    return topo;
}

}

#endif	/* PILHA_IMPL_H */

