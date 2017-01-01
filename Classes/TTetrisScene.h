#pragma once
#ifndef __TTetris_SCENE_H__
#define __TTetris_SCENE_H__

#include "cocos2d.h"
#include "TTetrisCtrl.h"

class TTetrisScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(TTetrisScene);

    // Sprite Data
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _background, Background);
    CC_SYNTHESIZE_RETAIN(cocos2d::Layer*,  _layer, Layer);

    // Pretty Tetris 
    PrettyTetris::TCtrl   _tctrl;

   ~TTetrisScene();
};

#endif // __TTetris_SCENE_H__
