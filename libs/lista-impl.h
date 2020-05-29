#ifndef LISTA2_IMPL_H
#define	LISTA2_IMPL_H

#include "lista.h"


namespace prglib {


template <typename T> lista<T>::lista() {
    
    len = 0;
    primeiro = nullptr;
    ultimo = nullptr;
    
}

template <typename T> lista<T>::lista(const lista<T> & outra) {
}

template <typename T> lista<T>::~lista() {
}

template <typename T> void lista<T>::insere(const T& algo) {
    
    Nodo * novo = new Nodo(algo);
    
    if(len==0){
        primeiro = novo;
        ultimo = novo;
    }
    else{
        novo->proximo = primeiro;
        primeiro->anterior = novo;
        primeiro = novo; 
        
    }
    len++;
}

template <typename T> void lista<T>::anexa(const T& algo){

    Nodo * novo = new Nodo(algo); 
    if(len == 0){
        primeiro = novo;        
    }else{
        ultimo->proximo = novo;
        novo->anterior = ultimo;        
    }
    
    ultimo = novo;
    len++;
}

template <typename T> int lista<T>::comprimento() const {
    return len;
}


template <typename T> void lista<T>::esvazia() {
    
    Nodo * ptr = primeiro;
    Nodo * succ;

    for(;ptr !=nullptr;){
        succ = ptr->proximo;
        delete ptr;
        ptr = succ;
    }
    len = 0;
    primeiro = nullptr;
    ultimo = nullptr;
}

template <typename T> void lista<T>::insere(const T& algo, int posicao) {
    
    if (posicao >= len) anexa(algo);
    else{
        if(posicao == 0) insere(algo);
        else{
            Nodo * nodo = new Nodo(algo);
    
            //Seleciona a posição para inserir o novo nodo;
            Nodo * ptr = primeiro;
            for(int i=0; i<posicao;i++)
                ptr = ptr->proximo;
            
            nodo->anterior = ptr->anterior;
            nodo->proximo = ptr;
            (ptr->anterior)->proximo = nodo;
            ptr->anterior = nodo;
                        
            len++;
        }
    }
}

template <typename T> T& lista<T>::obtem(int posicao) const {
    
    if(posicao >=len) throw 666;
    
    Nodo * ptr = primeiro;
    
    for(int i=0; i<posicao;i++){
        ptr = ptr->proximo;
    }
    return ptr->dado;
}

template <typename T> T& lista<T>::operator[](int pos) const {
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out) const {  
    if (len == 0) return;
    
    Nodo * ptr;
    
    for(ptr = primeiro;ptr!=ultimo;ptr=ptr->proximo)
        out << ptr->dado << "\n";
    out << ultimo->dado;
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out, const std::string & delim) const {
    
    if(len==0) return;
    Nodo * ptr;
    
    for(ptr = primeiro;ptr!=ultimo;ptr=ptr->proximo)
        out << ptr->dado << delim;
    out << ultimo->dado;
}

template <typename T> T lista<T>::remove(int posicao) {
    
    if(posicao > len) throw 666;
    
    Nodo * ptr = primeiro;
    Nodo * aux = primeiro;
    
    if(posicao==0){
        primeiro = primeiro->proximo;
        T data = aux->dado;
        delete aux;
        len--;
        return data;
    }else{
        for(int i=0; i<posicao; i++)
            ptr = ptr->proximo;

        T data2 = ptr->dado;
        (ptr->anterior)->proximo = ptr->proximo;
        if (ptr != ultimo) (ptr->proximo)->anterior = ptr->anterior;
        else ultimo = ptr->anterior;
        delete ptr;
        len--;
        return data2;

    }
}

template <typename T> void lista<T>::retira(const T& algo) {
    
    /*
    Nodo * ptr;
    Nodo * memoria;

    for(ptr = primeiro; ptr != nullptr; ){
        
        
        Nodo * succ = ptr->proximo;
        
        if(ptr->dado == algo){
            if(ptr==primeiro){
                primeiro = primeiro->proximo;
                delete ptr;
                len--;
            }else{
                memoria->proximo = succ;
                delete ptr;
                len--;
            }
        } else memoria = ptr;    

        ptr = succ;
    }*/
    
    Nodo * ptr;
    
    for(ptr = primeiro; ptr!=nullptr;){
        
        Nodo * succ = ptr->proximo;
        if(ptr->dado == algo){
            if(ptr==primeiro){
                primeiro = primeiro->proximo;
                delete ptr;
                len--;
            }else if(ptr == ultimo){
                ultimo = ultimo->anterior;
                delete ptr;
                len--;
            }else{
                (ptr->anterior)->proximo = ptr->proximo;
                (ptr->proximo)->anterior = ptr->anterior;
                delete ptr;
                len--;

            }
        }
        ptr = succ;
    
    }
    
}

template <typename T> bool lista<T>::vazia() const {
    return len==0;
}

template <typename T> void lista<T>::insereOrdenado(const T & algo) {
    
    Nodo * ptr;
    Nodo * nodo = new Nodo(algo);
    
    if(len == 0) insere(algo);
    
    for(ptr=primeiro; ptr!=nullptr; ptr = ptr->proximo){
        if(algo < ptr->dado){
            if(ptr == primeiro){
                nodo->anterior = ptr->anterior;
                nodo->proximo = ptr;
                ptr->anterior = nodo;
                primeiro = nodo;
                len++;
                return;
                
            }else{ 
                nodo->anterior = ptr->anterior;
                nodo->proximo = ptr;
                (ptr->anterior)->proximo = nodo;
                ptr->anterior = nodo;
                len++;
                return;
            }
        }       
    }  
    anexa(algo);
                
                
    
}

template <typename T> void lista<T>::ordena() {
   
}

template <typename T> T& lista<T>::procura(const T& algo) const {
    
    Nodo * ptr;
    
    for(ptr = primeiro; ptr != nullptr; ptr=ptr->proximo){
        if(ptr->dado == algo)
            return ptr->dado;
    }
    throw 666;
}

template <typename T> lista<T>& lista<T>::procuraMuitos(const T& algo, lista<T>& outra) const {
    
    Nodo * ptr;
    
    for(ptr = primeiro; ptr != nullptr; ptr=ptr->proximo){
        if(ptr->dado == algo)
            outra.anexa(ptr->dado);
    }
    return outra;
}

template <typename T> std::shared_ptr<lista<T>> lista<T>::procuraMuitos(const T& algo) const {
}

template <typename T> lista<T>& lista<T>::operator=(const lista<T>& outra) {
}

template <typename T> bool lista<T>::operator==(const lista<T>& outra) const {
}

template <typename T> void lista<T>::inverte() { 
    
    /* Método inverte sem usar swap 
    Nodo * ptr;
    Nodo * ptr2;
    
    for(ptr=primeiro;ptr!=nullptr;){
        
        ptr2 = ptr->proximo;
        
        //Nodo para memorizar o proximo e incrementar o laço
        Nodo * aux2 = ptr->proximo;
               
        ptr->proximo = ptr->anterior;
        ptr->anterior = ptr2;
        
        ptr = aux2;
    }
    
    Nodo * aux = primeiro;

    primeiro=ultimo;
    ultimo=aux;*/
    

    Nodo * ptr;
    Nodo * ptr2;
    
    //O incremento é para o anterior porque a posicao dos ponteiro estao invertidas
    for(ptr=primeiro;ptr!=nullptr;ptr=ptr->anterior)
        swap <Nodo*> (ptr->proximo, ptr->anterior);
        
   
    swap <Nodo*> (ultimo,primeiro);
    
}

template <typename T> bool lista<T>::inicio() const {
    return atual==nullptr;
}    

template <typename T> bool lista<T>::fim() const {
    return atual==nullptr;
    
}

template <typename T> void lista<T>::inicia() {
    atual = primeiro; 
}

template <typename T> void lista<T>::iniciaPeloFim() {
    atual = ultimo;
}

template <typename T> T& lista<T>::proximo() {
    
    T & dado = atual->dado;
    atual = atual->proximo;
    
    return dado;
}

template <typename T> T& lista<T>::anterior() {
    T & dado = atual->dado;
    atual = atual->anterior;
    
    return dado;
}

template <typename T> lista<T>& lista<T>::sublista(unsigned int pos1, unsigned int pos2, lista<T> & outra) const {   
}

template <typename T> lista<T>* lista<T>::sublista(unsigned int pos1, unsigned int pos2) const {   
}

template <class T> void lista<T>::embaralha() {
    
    Nodo * ptr;
    
    //struct e função para obter o valor do relógio em microssegundos
    timeval time;
    gettimeofday(&time,NULL);
    
    //semente para a randomização;
    srand(time.tv_usec);
       
    for(ptr=primeiro;ptr!=ultimo;ptr=ptr->proximo){
        int value = rand() % (len-1);
        T & dado1 = obtem(value);
        swap <T> (dado1,ptr->dado);
    }
   
}

template <typename T> void lista<T>::ordenaBolha(){
    
    Nodo * ptr;
    Nodo * ptr2;
    
    for(ptr=ultimo;ptr!=primeiro; ptr = ptr->anterior){
        for(ptr2=primeiro; ptr2 != ptr; ptr2 = ptr2->proximo){
            if(ptr2->dado > ptr->dado){
                T aux = ptr2->dado;
                ptr2->dado = ptr->dado;
                ptr->dado = aux;
            }
        }
    }
}

template <typename T> void lista<T>::ordenaSelecao(){
    
    Nodo * ptr;
    Nodo * ptr2;
    Nodo * menor;
    
    for(ptr=primeiro; ptr!=ultimo;ptr=ptr->proximo){
        menor = ptr;
        for(ptr2=menor->proximo;ptr2 != nullptr; ptr2=ptr2->proximo){
            if(menor->dado > ptr2->dado)
                menor = ptr2;
        }
        if(menor != ptr){
            T aux = ptr->dado;
            ptr->dado = menor->dado;
            menor->dado = aux;
        }
    }   
}
  
} // fim namespace

#endif	/* LISTA_IMPL_H */

