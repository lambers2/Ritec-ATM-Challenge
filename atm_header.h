/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   atm_header.h
 * Author: shane
 *
 * Created on March 21, 2019, 6:49 PM
 */

#ifndef ATM_HEADER_H
#define ATM_HEADER_H

#include <string>
#include <iostream>
#include <cctype>
#include <utility>

void atmStartUp();

int balanceCheck(int);
int withdrawFromAccount(int);
int depositToAccount(int);
void dispenseMoney(int);



#endif /* ATM_HEADER_H */

