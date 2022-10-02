
/* 
 * File:   EncodeUtility.cpp
 * Author: pnovack
 * 
 * Created on October 2, 2022, 9:38 AM
 */
#include "EncodeUtility.h"

EncodeUtility::EncodeUtility() {
}

EncodeUtility::EncodeUtility(const EncodeUtility& orig) {
}

EncodeUtility::~EncodeUtility() {
}

std::string EncodeUtility::BintEncode(int64_t numin){
    std::string b65num = "";
    if(numin > h8 ){
            b65num = b65num + tb65[int(numin / h8)];
            numin = numin - h8 * (numin / h8);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h7 ){
        b65num = b65num + tb65[int(numin / h7)];
        numin = numin - h7 * (numin / h7);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h6 ){
        b65num = b65num + tb65[int(numin / h6)];
        numin = numin - h6 * (numin / h6);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h5 ){
        b65num = b65num + tb65[int(numin / h5)];
        numin = numin - h5 * (numin / h5);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h4 ){
        b65num = b65num + tb65[int(numin / h4)];
        numin = numin - h4 * (numin / h4);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h3 ){
        b65num = b65num + tb65[int(numin / h3)];
        numin = numin - h3 * (numin / h3);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h2 ){
        b65num = b65num + tb65[int(numin / h2)];
        numin = numin - h2 * (numin / h2);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h1 ){
        b65num = b65num + tb65[int(numin)];
        numin = numin - numin;
    } else {
        b65num = b65num + "0";
    }
    return b65num;
}
int64_t EncodeUtility::BintDecode(std::string b65num){
    int64_t calced = 0;
    for(int idx = 0;idx < 8;idx++){
        if(idx == 0)calced = calced + h8 * fb65[int(b65num[idx])];
        if(idx == 1)calced = calced + h7 * fb65[int(b65num[idx])];  
        if(idx == 2)calced = calced + h6 * fb65[int(b65num[idx])];
        if(idx == 3)calced = calced + h5 * fb65[int(b65num[idx])];  
        if(idx == 4)calced = calced + h4 * fb65[int(b65num[idx])];  
        if(idx == 5)calced = calced + h3 * fb65[int(b65num[idx])];  
        if(idx == 6)calced = calced + h2 * fb65[int(b65num[idx])];  
        if(idx == 7)calced = calced + fb65[int(b65num[idx])];  
    }   
    return calced;
}
std::string EncodeUtility::MintEncode(int64_t numin){
    std::string b65num = "";
    if(numin > h4 ){
        b65num = b65num + tb65[int(numin / h4)];
        numin = numin - h4 * (numin / h4);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h3 ){
        b65num = b65num + tb65[int(numin / h3)];
        numin = numin - h3 * (numin / h3);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h2 ){
        b65num = b65num + tb65[int(numin / h2)];
        numin = numin - h2 * (numin / h2);
    } else {
        b65num = b65num + "0";
    }
    if(numin > h1 ){
        b65num = b65num + tb65[int(numin)];
        numin = numin - numin;
    } else {
        b65num = b65num + "0";
    }
    return b65num;
}
int64_t EncodeUtility::MintDecode(std::string b65num){
    int64_t num = 0;
    return num;
}
