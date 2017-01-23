#include "TTetrisScene.h"
#include "SimpleAudioEngine.h"

#include  "TTetrisCtrl.h"
#include<memory>

USING_NS_CC;

// --------------------------------------------------
// Scene* TTetris::createScene()
//
// --------------------------------------------------
Scene* TTetrisScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TTetrisScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// --------------------------------------------------
// TTetris::init()
//
// on "init" you need to initialize your instance
// --------------------------------------------------
bool TTetrisScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(TTetrisScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width -closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    ///
    auto  layer = Layer::create();
    setLayer(layer);

    ///
    auto label = Label::createWithTTF("Hello,TTetris World", "fonts/Marker Felt.ttf", 15);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    layer->addChild(label, 1);
    //layer->retain();
  
    // add "TTetris" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
 
    //auto sprite2 = Sprite::create("Box.png");
    this->setBackground( Sprite::create("Background.png") );

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    ///this->getPiece()->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    _background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
  
    // add the sprite as a child to this layer
    layer->addChild(_background);
    layer->addChild(sprite, 0);

    this->addChild(layer);
    _tctrl.setLayer(layer);
    _tctrl.Init();

    // Update Method
    this->scheduleUpdate();

    // creating a keyboard event listener
    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(TTetrisScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

    ///layer->addChild(this->getPiece(), 0);
    return true;
}


// --------------------------------------------------
// --------------------------------------------------
void TTetrisScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
  log("Key with keycode %d pressed", keyCode);
  _tctrl.TurnBlock();

}


// --------------------------------------------------
// --------------------------------------------------
void TTetrisScene::update(float delta) {
  static float sum = 0;

  if ( (sum += delta) > 1.0){
    _tctrl.NextStep();
    sum=0;
  }
}


// --------------------------------------------------
// --------------------------------------------------
void TTetrisScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

// --------------------------------------------------
// --------------------------------------------------
TTetrisScene::~TTetrisScene() {
   
  CC_SAFE_RELEASE_NULL(_background);
  CC_SAFE_RELEASE_NULL(_layer);
  return;
}
