#include"TTetrisCtrl.h"

#include<iostream>
#include<boost/format.hpp>

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
  

  /// Generate Matrix, Sprite Table
  for(int x=0; x<(_tcore.GetWidth()- _offset_x - _offset_x); x++){
    for(int y=0; y<(_tcore.GetHeight()- _offset_y - _offset_y); y++){
       const int space = 16 * 2;

      _piece[x][y] = Sprite::create("Piece.png"); /// Picture Size is 16pixel.
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

  _block.Set(Parts::L, Num);
  Num = (Num+1)%4;
}


// --------------------------------------------------
// --------------------------------------------------
 TCtrl::~TCtrl() {
   /// Clear Matricx
   for (int x = 0; x<(_tcore.GetWidth() - _offset_x - _offset_x); x++) {
     for (int y = 0; y<(_tcore.GetHeight() - _offset_y - _offset_y); y++) {
       CC_SAFE_RELEASE_NULL(_piece[x][y]);
     }
   }

 }

 
// --------------------------------------------------
// --------------------------------------------------
 void TCtrl::Draw(){
   static int ptx = 3;
   static int pty = 3;
   //_piece[0][ct++]->setVisible(false);

   _tcore.Initialize(false);
   _tcore.PutBlock(_block, ptx, pty, 0, 1, false);

   for (int x = 0; x<(_tcore.GetWidth() - _offset_x - _offset_x); x++) {
     for (int y = 0; y<(_tcore.GetHeight() - _offset_y - _offset_y); y++) {
        if( _tcore._matrix0[x+ _offset_x][y+ _offset_y] || 
            _tcore._matrix1[x+ _offset_x][y+ _offset_y] ){
          _piece[x][y]->setVisible(true);
        }else{
          _piece[x][y]->setVisible(false);
        }
     }
   }

}



