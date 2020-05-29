/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Thread.cpp
 * Author: sarom
 * 
 * Created on 27 de Março de 2019, 14:43
 */

#include "Thread.h"

Thread::Thread(int id) {
    
    //salva o contexto atual
    getcontext(&contexto);
    
    int stackLen = 32*1024;
    char *stack=new char[stackLen];
    
    //Cada thread executa em uma pilha própria - configurando pilha
    contexto.uc_stack.ss_sp = stack;
    contexto.uc_stack.ss_size= stackLen;
    contexto.uc_stack.ss_flags = 0;
    
    id_thread = id;
    
    //muda o contexto
    makecontext(&contexto,0);
    
}

ucontext_t* Thread::get_context(){
    return &contexto;
}

