/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "BoxFix.h"
USING_NS_CC;

//한글 출력할때 필요함
#pragma execution_character_set("UTF-8")

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();

	auto layer = HelloWorld::create();

	scene->addChild(layer);

	return scene;
}



bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto mySprite = Sprite::create("HelloWorld.png");
	this->addChild(mySprite);
	auto label = Label::createWithSystemFont("테스트", "Arial", 96);
	this->addChild(label);

	mySprite->setLocalZOrder(1);

	mySprite->setAnchorPoint(Vec2(0.5, 0.5));
	label->setAnchorPoint(Vec2(0.5, 0.5));

	mySprite->setPosition(Vec2(300, 100));
	mySprite->setScale(0.5);

	/*label->setAnchorPoint(Vec2(0, 0));
	mySprite->setAnchorPoint(Vec2(0, 0));

	auto jump = JumpBy::create(1, Point(500, 0), 150, 4);
	mySprite->runAction(jump);

	mySprite->runAction(Sequence::create(moveT1, DelayTime::create(0), moveB1, DelayTime::create(1), MoveTo::create(1, Vec2(300, 300)), nullptr));


	mySprite->runAction(rep);
	mySprite->runAction(RepeatForever::create(Spawn::create(MoveBy::create(1, Vec2(10, 0)), MoveBy::create(1, Vec2(-10, 0)))));
	mySprite->runAction(RepeatForever::create(Spawn::create(MoveBy::create(0.1, Vec2(-10, 0)), nullptr)));
	mySprite->runAction(Spawn::create(MoveBy::create(1,Vec2(100,0)),nullptr));
	mySprite->runAction(RepeatForever::create(MoveBy::create(1, Vec2(10, 0))));*/

	auto keyboard = EventListenerKeyboard::create();
	keyboard->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	keyboard->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard, this);

	return true;
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode KeyCode, cocos2d::Event* event)
{
	log("test succes");
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode KeyCode, cocos2d::Event* event)
{

	switch (KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_A:
	{
		Director::getInstance()->replaceScene(test::create());
		break;
	}
	case EventKeyboard::KeyCode::KEY_S:
	{
		Director::getInstance()->replaceScene(keyboard::create());
		break;
	}
	case EventKeyboard::KeyCode::KEY_D:
	{
		MessageBox("test succes\ntest\n테스트", "테스트 창");
	}
	}
}

bool test::init()
{

	if (!Scene::init())
	{
		return false;
	}

	auto coin = Sprite::create("coin1.png");
	this->addChild(coin);

	coin->setTexture("coin1.png");
	
	coin->setAnchorPoint(Vec2(0, 0));
	coin->setPosition(Vec2(100, 0));
	return true;
}

bool keyboard::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//sprite
	{
		Wkey = Sprite::create("keyboard/Wkey1.png");
		Akey = Sprite::create("keyboard/Akey1.png");
		Skey = Sprite::create("keyboard/Skey1.png");
		Dkey = Sprite::create("keyboard/Dkey1.png");
		this->addChild(Wkey);
		this->addChild(Akey);
		this->addChild(Skey);
		this->addChild(Dkey);

		Wkey->setAnchorPoint(Vec2(0.5, 0.5));
		Akey->setAnchorPoint(Vec2(0.5, 0.5));
		Skey->setAnchorPoint(Vec2(0.5, 0.5));
		Dkey->setAnchorPoint(Vec2(0.5, 0.5));
		Wkey->setPosition(Vec2(200, 428));
		Akey->setPosition(Vec2(72, 200));
		Skey->setPosition(Vec2(200, 200));
		Dkey->setPosition(Vec2(328, 200));

		boxTest = Sprite::create("keyboard/Wkey1.png");
		this->addChild(boxTest);
		boxTest->setAnchorPoint(Vec2(0, 0));
		boxTest->setPosition(Vec2(200, 200));
	}

	// keyboard
	{
	auto keyboard = EventListenerKeyboard::create();
	keyboard->onKeyPressed = CC_CALLBACK_2(keyboard::onKeyPressed, this);
	keyboard->onKeyReleased = CC_CALLBACK_2(keyboard::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard, this);
	}

	// Touch
	{
		auto listener = EventListenerTouchOneByOne::create();

		listener->setSwallowTouches(true);

		listener->onTouchBegan = CC_CALLBACK_2(keyboard::onTouchBegan, this);
		listener->onTouchMoved = CC_CALLBACK_2(keyboard::onTouchMoved, this);
		listener->onTouchCancelled = CC_CALLBACK_2(keyboard::onTouchCancelled, this);
		listener->onTouchEnded = CC_CALLBACK_2(keyboard::onTouchEnded, this);

		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	}

	return true;
}

void keyboard::ChangeImage(int key, bool statue)
{
	//W = 1
	//A = 2
	//S = 3
	//D = 4
	if (statue)
	{
		switch (key)
		{
		case 1:
			Wkey->setTexture("keyboard/Wkey2.png");
			break;

		case 2:
			Akey->setTexture("keyboard/Akey2.png");
			break;

		case 3:
			Skey->setTexture("keyboard/Skey2.png");
			break;

		case 4:
			Dkey->setTexture("keyboard/Dkey2.png");
			break;

		}
	}
	else
	{
		switch (key)
		{
		case 1:
			Wkey->setTexture("keyboard/Wkey1.png");
			break;

		case 2:
			Akey->setTexture("keyboard/Akey1.png");
			break;

		case 3:
			Skey->setTexture("keyboard/Skey1.png");
			break;

		case 4:
			Dkey->setTexture("keyboard/Dkey1.png");
			break;

		}
	}


	/*
	if(WkeyChange)
		Wkey->setTexture("keyboard/Wkey2.png");
	else
		Wkey->setTexture("keyboard/Wkey1.png");

	if(AkeyChange)
		Akey->setTexture("keyboard/Akey2.png");
	else
		Akey->setTexture("keyboard/Akey1.png");

	if(SkeyChange)
		Skey->setTexture("keyboard/Skey2.png");
	else
		Skey->setTexture("keyboard/Skey1.png");

	if(DkeyChange)
		Dkey->setTexture("keyboard/Dkey2.png");
	else
		Dkey->setTexture("keyboard/Dkey1.png");
		*/
}

void keyboard::onKeyPressed(EventKeyboard::KeyCode KeyCode, Event* event)
{
	switch (KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		keyboard::ChangeImage(1, true);
		break;

	case EventKeyboard::KeyCode::KEY_A:
		keyboard::ChangeImage(2, true);
		break;

	case EventKeyboard::KeyCode::KEY_S:
		keyboard::ChangeImage(3, true);
		break;

	case EventKeyboard::KeyCode::KEY_D:
		keyboard::ChangeImage(4, true);
		break;
	}
}

void keyboard::onKeyReleased(EventKeyboard::KeyCode KeyCode, Event* event)
{
	switch (KeyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		keyboard::ChangeImage(1, false);
		break;

	case EventKeyboard::KeyCode::KEY_A:
		keyboard::ChangeImage(2, false);
		break;

	case EventKeyboard::KeyCode::KEY_S:
		keyboard::ChangeImage(3, false);
		break;

	case EventKeyboard::KeyCode::KEY_D:
		keyboard::ChangeImage(4, false);
		break;
	}
}

bool keyboard::onTouchBegan(Touch *touch, Event *unused_event)
{
	Vec2 pos = touch->getLocation();

	// error
	pos.y = BoxFix::FixCursorY(pos.y);

	log("%f,%f", pos.x, pos.y);



	return true;
}

void keyboard::onTouchMoved(Touch* touch, Event* unused_event)
{
	Point pos = touch->getLocation();
}

void keyboard::onTouchCancelled(Touch* touch, Event* unused_event)
{

}

void keyboard::onTouchEnded(Touch* touch, Event *unused_event)
{

}