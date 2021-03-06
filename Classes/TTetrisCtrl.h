#pragma once
#ifndef __TTETRISCTRL_H
#define __TTETRISCTRL_H

#include "cocos2d.h"
#include "TTetrisCore.h"

USING_NS_CC;

namespace PrettyTetris{

class TCtrl{
private:

public: 
  TCtrl(): _layer(nullptr){}
  TCtrl(cocos2d::Layer *pl);
  ~TCtrl();

  enum GAMESTATUS  {wait, play}  _gamestatus= GAMESTATUS::wait;
  
  TCore      _tcore;
  Sprite    *_piece[10][20];    /// !!! KARI !!!
  

  CC_SYNTHESIZE_RETAIN(cocos2d::Layer*, _layer, Layer);
  ///CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _piece, Piece);
    
  void Init();
  void Draw();
  void NextStep();
  void TurnBlock();
};


}; /// namespace PretyTetris{

#endif /// #ifndef __TTETRISCTRL_H
