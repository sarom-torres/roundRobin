/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escalonador.cpp
 * Author: sarom
 * 
 * Created on 27 de Março de 2019, 14:28
 */

#include "Escalonador.h"


Escalonador::Escalonador() {
    id_thread = 0;
}

Escalonador::Escalonador(const Escalonador& orig) {
}

Escalonador::~Escalonador() {
}

void Escalonador::add_thread(){

    Thread thread(id_thread);
    id_thread++;
    ready_pool.anexa(thread);
}

