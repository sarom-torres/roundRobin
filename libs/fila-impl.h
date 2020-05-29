#ifndef FILA_IMP_H
#define	FILA_IMP_H

namespace prglib {
    
template <typename T> fila<T>::fila(unsigned int max_itens) {
    
    if(max_itens == 0) throw 666;
    
    cap = max_itens;
    
    buffer = new T[cap];
    
    inicio =0;
    fim =0;
    N=0;
}

template <typename T> fila<T>::fila(const fila& orig) { 
    
    cap = orig.cap;
    buffer = new T[cap];
    
    for(int i=0; i<cap; i++)
        buffer[i] = orig.buffer[i];
    
    fim = orig.fim;
    inicio = orig.inicio;
    N = orig.N;
}

template <typename T> fila<T>::~fila() {
    
    delete[] buffer; 
}

template <typename T> fila<T>& fila<T>::operator=(const fila& outra) {
    
    if(cap < outra.cap){
        cap = outra.cap;
        delete[] buffer;
        buffer = new T[cap]; 
    }
    
    for(int cont=0;cont<cap;cont++)
        buffer[cont] = outra.buffer[cont];
    
    inicio = outra.inicio;
    fim = outra.fim;
    N = outra.N;
    
    
    return *this;
}

template <typename T> void fila<T>::enfileira(const T& algo) {
    
    if(N<cap){
        buffer[fim] = algo;
        N++;
        fim++;   
        if(fim == cap){
            fim=0;    
        }
    }else 
        throw 666;
        
}

template <typename T> T fila<T>::desenfileira() {
    
    if(N==0) throw 666;
    
    T dado = buffer[inicio];
    inicio++;
    N--;
    
    if(inicio == cap)
        inicio=0;
    
    return dado;
    
}

template <typename T> const T & fila<T>::frente() const {
    return buffer[inicio];
}

template <typename T> bool fila<T>::vazia() const {  
    return N==0;        
}

template <typename T> bool fila<T>::cheia() const {
    return N==cap;
}

template <typename T> unsigned int fila<T>::capacidade() const {
    return cap;
}

template <typename T> unsigned int fila<T>::comprimento() const {
    return N;
}

template <typename T> void fila<T>::esvazia() {

    T esv;
    while(N!=0){
        esv = buffer[inicio];
        N--;
        inicio++;
    }

}

} // fim namespace

#endif	/* FILA_IMP_H */

