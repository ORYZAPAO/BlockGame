#include"TTetrisCtrl.h"

#include<iostream>
#include"boost/format.hpp"

using namespace PrettyTetris;
USING_NS_CC;

TCtrl::TCtrl(cocos2d::Layer *pl) {
 //Init();
}

// --------------------------------------------------
// --------------------------------------------------
void TCtrl::Init(){
  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin      = Director::getInstance()->getVisibleOrigin();
  ///setPiece(Sprite::create("Piece.png"));
  

  // Generate Matrix, Sprite Table
  for(int x=0; x<(_tcore.GetWidth()- (_tcore.GetBaseX() * 2) ); x++){
    for(int y=0; y<(_tcore.GetHeight()- (_tcore.GetBaseY() * 2) ); y++){
       const int space = 16 * 2;

      _piece[x][y] = Sprite::create("Piece.png"); // Picture Size is 16 x 16 pixels.
      _piece[x][y]->setPosition(  Vec2((visibleSize.width /2 + (16 * x) + origin.x), 
                                       (                       (16 * (_tcore.GetHeight() - y)) + origin.y  + space) ) );
      //_piece[x][y]->setVisible(false);
      std::cout << boost::format("%d, %d") % (visibleSize.width / 2 + (16 * x) + origin.x) % ((16 * (y + 1)) + origin.y) << std::endl;

      _layer->addChild(_piece[x][y]); 
    }
  }

  //
  //_piece[0][0]->setVisible(false);
}
 

// --------------------------------------------------
// --------------------------------------------------
 void TCtrl::NextStep(){
     Draw();
}


 // --------------------------------------------------
 // --------------------------------------------------
void TCtrl::TurnBlock() {
   static int Num=0;

   _tcore.Turn();
}


// --------------------------------------------------
// --------------------------------------------------
 TCtrl::~TCtrl() {
   /// Clear Matricx
   for (int x = 0; x<(_tcore.GetWidth() - (_tcore.GetBaseX() * 2) ); x++) {
     for (int y = 0; y<(_tcore.GetHeight() - (_tcore.GetBaseY() * 2) ); y++) {
       CC_SAFE_RELEASE_NULL(_piece[x][y]);
     }
   }

 }

 
// --------------------------------------------------
// --------------------------------------------------
 void TCtrl::Draw(){
   //_piece[0][ct++]->setVisible(false);

   _tcore.Initialize(false);
   _tcore.PutBlock(_tcore._currentBlock, 0, 1, false); /// Take Down _pos_y+1

   for (int x = 0; x<(_tcore.GetWidth() - (_tcore.GetBaseX() * 2 )); x++) {
     for (int y = 0; y<(_tcore.GetHeight() - (_tcore.GetBaseY() * 2) ); y++) {
        if( _tcore._matrix0[x+ _tcore.GetBaseX()][y+ _tcore.GetBaseY()] ||
            _tcore._matrix1[x+ _tcore.GetBaseX()][y+ _tcore.GetBaseY()] ){
          _piece[x][y]->setVisible(true);
        }else{
          _piece[x][y]->setVisible(false);
        }
     }
   }

}



