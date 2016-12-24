#pragma once
#ifndef __TTETRISCTRL_H
#define __TTETRISCTRL_H

#include  "TTetrisScene.h"
#include "TTetrisCore.h"

namespace PrityTetris{

  USING_NS_CC;

  
class TCtrl{
private:
  class TCore *_ptcore;
  class Layer *_layer;

public: 
  TCtrl():_ptcore(nullptr), _layer(nullptr){}
  TCtrl(TCore *pt, Layer *pl) :_ptcore(pt),_layer(pl) {}
  ~TCtrl(){}

  Sprite *_piece;
  
  void Init();
  void Draw();
};


}; /// namespace PretyTetris{


#endif /// #ifndef __TTETRISCTRL_H

  
