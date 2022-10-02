/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EncodeUtility.h
 * Author: pnovack
 *
 * Created on October 2, 2022, 9:38 AM
 */

#ifndef ENCODEUTILITY_H
#define ENCODEUTILITY_H

#include <cstdlib>
#include <iostream>
#include <cmath>



using namespace std;
// this is not base 64 encoding it is custom base 65 encoding to sort with redis

static const unsigned int fb65[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10,
11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
31, 32, 33, 34, 35,36, 0, 0, 0, 0, 0,36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65};

// this is not base 64 encoding it is custom base 65 encoding to sort with redis
static const char tb65[] = 
"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}~";

int64_t   h8 = 65LL * 65LL * 65LL * 65LL * 65LL * 65LL * 65LL; 
int64_t   h7 = 65LL * 65LL * 65LL * 65LL * 65LL * 65LL; 
int64_t   h6 = 65LL * 65LL * 65LL * 65LL * 65LL; // 1160290625
int64_t   h5 = 65LL * 65LL * 65LL * 65LL; //17850625
int64_t   h4 = 65LL * 65LL * 65LL; // 274625
int64_t   h3 = 65LL * 65LL; //4225
int64_t   h2 = 65LL; // 65
int64_t   h1 = 0; // 0 - 64


class EncodeUtility {
public:
    EncodeUtility();
    EncodeUtility(const EncodeUtility& orig);
    virtual ~EncodeUtility();
    std::string BintEncode(int64_t numin); 
    int64_t BintDecode(std::string b65num);
    std::string MintEncode(int64_t numin);
    int64_t MintDecode(std::string b65num);
    /*
DateEncode
DateDecode
     */
    
private:

};

#endif /* ENCODEUTILITY_H */

