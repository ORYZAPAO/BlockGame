#include"TTetrisCtrl.h"

using namespace PrettyTetris;
USING_NS_CC;

TCtrl::TCtrl(cocos2d::Layer *pl) {
 //Init();
}

TCtrl::~TCtrl() {
  CC_SAFE_RELEASE_NULL(_piece);
}

/*
 *
 */
 void TCtrl::Init(){
  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();
  ///setPiece(Sprite::create("Piece.png"));

  setPiece(Sprite::create("piece.png"));
  _piece->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

  // Draw Piece
  _layer->addChild(_piece);

}

void TCtrl::Draw(){

}



