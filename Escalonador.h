/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escalonador.h
 * Author: sarom
 *
 * Created on 27 de Março de 2019, 14:28
 */

#ifndef ESCALONADOR_H
#define ESCALONADOR_H
#include "prglib.h"
#include "Thread.h"

using prglib::lista;

class Escalonador {
public:
    Escalonador();
    Escalonador(const Escalonador& orig);
    virtual ~Escalonador();
    void add_thread();
    
    
private:

    lista <Thread> ready_pool;
    int id_thread;
    
};

#endif /* ESCALONADOR_H */

