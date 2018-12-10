#ifndef __GPIO_H_
#define __GPIO_H_

#ifdef __C51__


#include "STC8.H"



enum pinMode
{
    IO = 0,
    OUTPUT,
    INPUT,
    OPENOUT

};
typedef struct _PIN
{
   char _0 : 1;
   char _1 : 1;
   char _2 : 1;
   char _3 : 1;
   char _4 : 1;
   char _5 : 1;
   char _6 : 1;
   char _7 : 1;
} PIN;


#define pin0Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                        P0M0 = *(char*)&PnM0;P0M1 = *(char*)&PnM1
#define pin1Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                        P1M0 = *(char*)&PnM0;P1M1 = *(char*)&PnM1;
#define pin2Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                        P2M0 = *(char*)&PnM0;P2M1 = *(char*)&PnM1;
#define pin3Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                        P3M0 = *(char*)&PnM0;P3M1 = *(char*)&PnM1;
#define pin4Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                         P4M0 = *(char*)&PnM0;P4M1 = *(char*)&PnM1;
#define pin5Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                         P5M0 = *(char*)&PnM0;P5M1 = *(char*)&PnM1;
#define pin6Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                         P6M0 = *(char*)&PnM0;P6M1 = *(char*)&PnM1;
#define pin7Mode(n,mode) if(mode == IO)      {PnM1._##n = 0;PnM0._##n = 0;}\
                         if(mode == OUTPUT)  {PnM1._##n = 0;PnM0._##n = 1;}\
                         if(mode == INPUT)   {PnM1._##n = 1;PnM0._##n = 0;}\
                         if(mode == OPENOUT) {PnM1._##n = 1;PnM0._##n = 1;}\
                         P7M0 = *(char*)&PnM0;P7M1 = *(char*)&PnM1;

extern PIN xdata PnM0;
extern PIN xdata PnM1;

#endif
#endif
