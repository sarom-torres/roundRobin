/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Thread.h
 * Author: sarom
 *
 * Created on 27 de Março de 2019, 14:43
 */

#ifndef THREAD_H
#define THREAD_H

#include <ucontext.h>

class Thread {
public:
    Thread(int id);
    ucontext_t* get_context();
    
    ucontext_t contexto;
    
private:
    
    int id_thread;
    
};

#endif /* THREAD_H */

