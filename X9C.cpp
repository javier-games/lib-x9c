//
//  DS1267.cpp
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <X9C.h>

X9C::X9C(int _UoD_pin,int _INC_pin,int _MNT_pin,int _MTR_pin,int _SLV_pin[]):
UoD_pin(_UoD_pin),INC_pin(_INC_pin),MNT_pin(_MNT_pin),MTR_pin(_MTR_pin),SLV_pin(_SLV_pin){
    
    pinMode(UoD_pin,OUTPUT);
    pinMode(INC_pin,OUTPUT);
    pinMode(MTR_pin,OUTPUT);
    for (int i=0; i<sizeof(SLV_pin); i++) {
        pinMode(SLV_pin[i],OUTPUT);
    }
    
    digitalWrite(UoD_pin,LOW );
    digitalWrite(INC_pin,HIGH);
    digitalWrite(MTR_pin,HIGH);
    zeros();
}

X9C::X9C(int _UoD_pin,int _INC_pin,int _MNT_pin,int _MTR_pin,int _SLV_pin):
UoD_pin(_UoD_pin),INC_pin(_INC_pin),MNT_pin(_MNT_pin),MTR_pin(_MTR_pin){
    
    int aux[]={_SLV_pin};
    SLV_pin = aux;
    
    pinMode(UoD_pin,   OUTPUT);
    pinMode(INC_pin,   OUTPUT);
    pinMode(MTR_pin,   OUTPUT);
    pinMode(SLV_pin[0],OUTPUT);
    
    digitalWrite(UoD_pin,LOW );
    digitalWrite(INC_pin,HIGH);
    digitalWrite(MTR_pin,HIGH);
    zeros();
}

X9C::X9C(int _UoD_pin,int _INC_pin,int _MNT_pin,int _MTR_pin):
UoD_pin(_UoD_pin),INC_pin(_INC_pin),MNT_pin(_MNT_pin),MTR_pin(_MTR_pin){
    
    int aux[0];
    SLV_pin = aux;
    pinMode(UoD_pin,OUTPUT);
    pinMode(INC_pin,OUTPUT);
    pinMode(MTR_pin,OUTPUT);
    
    digitalWrite(UoD_pin,LOW );
    digitalWrite(INC_pin,HIGH);
    digitalWrite(MTR_pin,HIGH);
    zeros();
}


void X9C::zeros(){
    for (int i=0; i<110 ; i++){
        
        for(int j=0;j<sizeof(SLV_pin);j++)
            digitalWrite(SLV_pin[j],LOW);
        digitalWrite(MTR_pin,LOW);
        digitalWrite(INC_pin,LOW);
        
        for(int j=0;j<sizeof(SLV_pin);j++)
            digitalWrite(SLV_pin[j],HIGH);
        digitalWrite(MTR_pin,HIGH);
        digitalWrite(INC_pin,HIGH);
    }
}