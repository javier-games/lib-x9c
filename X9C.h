//
//  DS1267.h
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

#include <Arduino.h>
#ifndef _X9C_h
#define _X9C_h

class X9C{
    
public:
    X9C(int _UoD_pin, int _INC_pin, int _MNT_pin, int _MTR_pin,int _SLV_pin[]);
    X9C(int _UoD_pin, int _INC_pin, int _MNT_pin, int _MTR_pin,int _SLV_pin);
    X9C(int _UoD_pin, int _INC_pin, int _MNT_pin, int _MTR_pin);
    
    void zeros();
    //void SET(int _POT,int _VAL);
    //int  GET(int _POT);
    
private:
    
    int    UoD_pin;
    int    INC_pin;
    int    MNT_pin;
    int    MTR_pin;
    int    *SLV_pin;
    
    //void digitalWriteCLK(int _PIN,int _VAL);
    
};

#endif