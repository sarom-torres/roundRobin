#ifndef FILA_H
#define	FILA_H

namespace prglib {
    
template <typename T> class fila {
public:
    // construtor: cria fila com capacidade N
    fila(unsigned int max_itens);
    
    // construtor: cria fila que é cópia da fila "orig"
    fila(const fila<T>& orig);
    
    // destrutor
    ~fila();
    
    // operador de atribuição: torna esta fila uma cópia da "outra" fila
    fila<T>& operator=(const fila<T> & outra);
    
    // enfileira um dado
    void enfileira(const T & algo);
    
    // desenfileira um dado
    T desenfileira();
    
    // retorna uma referência ao dado que está no início da fila
    const T & frente() const;
    
    // testa se fila está vazia
    bool vazia() const;
    
    // testa se fila está cheia
    bool cheia() const;
    
    // retorna a quantidade de dados armazenados
    unsigned int comprimento() const;
    
    // retorna a capacidade da fila (quantos dados cabem)
    unsigned int capacidade() const;
    
    // remove todos os dados da fila
    void esvazia();
private:
    unsigned int N, cap;
    T * buffer;
    unsigned int inicio, fim;
};

}

#include <libs/fila-impl.h>

#endif	/* FILA_H */

