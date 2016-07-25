#include "HelloWorldScene.h"
#include "HttpClient.h"
#include "SignLayer.hpp"
#include "World.hpp"

USING_NS_CC;
using namespace cocos2d::network;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "scv_button.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuScvCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto itemScv = MenuItemImage::create(
                                           "scv_button.png.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
    return true;
}

void HelloWorld::menuScvCallback(cocos2d::Ref* pSender)
{
//    SignLayer* signLayer = SignLayer::create();
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    signLayer->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2));
//    this->addChild(signLayer,100000);
    
    auto scene = World::create();
    Director::getInstance()->replaceScene(scene);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
//    测试网络
    {
        HttpRequest* request = new (std::nothrow) HttpRequest();
        request->setUrl("http://192.168.0.105:2345/");
        request->setRequestType(HttpRequest::Type::GET);
//        request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));
    
        request->setTag("GET immediate test1");
        HttpClient::getInstance()->sendImmediate(request);
  
        request->release();
    }
    
//    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
#endif
}
