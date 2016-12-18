#pragma once
#ifndef __TTETRISCTRL_H
#define __TTETRISCTRL_H

#include "TTetrisCore.h"

namespace PrityTetris{

class TCtrl{
private:
  class TCore *_ptcore;

public: 
  TCtrl():_ptcore(nullptr){}
  TCtrl(TCore *p) :_ptcore(p) {}
  ~TCtrl(){}



};


}; /// namespace PretyTetris{


#endif /// #ifndef __TTETRISCTRL_H

  
