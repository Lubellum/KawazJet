#include "MainScene.h"

// 重力を表すベクトル
const cocos2d::Vec2 GRAVITY_ACCELERATION = cocos2d::Vec2(0, -3);

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    // 画面の大きさを取り出す
    auto winSize = cocos2d::Director::getInstance()->getWinSize();

    // 物理エンジンの検証用なので後で消す
    auto sprite = cocos2d::Sprite::create("image/box.png");

    // スプライトと同じ大きさの剛体を作成する
    auto physicsBody = cocos2d::PhysicsBody::createBox(sprite->getContentSize());

    // 剛体をspriteに付ける
    sprite->setPhysicsBody(physicsBody);
    sprite->setPosition(cocos2d::Vec2(winSize.width / 2.0, winSize.height));
    this->addChild(sprite);

    this->scheduleUpdate();

    return true;
}

cocos2d::Scene* CMainScene::createScene()
{
    // 物理エンジンを有効にしたシーンを作成する
    auto scene = cocos2d::Scene::createWithPhysics();

    // 物理空間を取り出す
    auto world = scene->getPhysicsWorld();

    // 重力を設定する
    world->setGravity(GRAVITY_ACCELERATION);

    // デバッグビルドのとき
#if COCOS2D_DEBUG > 0
    //物理空間にデバッグ用の表示を追加する
    world->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
#endif // COCOS2D_DEBUG > 0

    // 物理空間のスピードを設定する
    world->setSpeed(6.0);

    // レイヤーを作成する
    auto layer = CMainScene::create();
    scene->addChild(layer);

    return scene;
}

void CMainScene::update(float aDt)
{
}