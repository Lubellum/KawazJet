#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "cocos2d.h"

class CMainScene : public cocos2d::Layer
{
public:
	CMainScene();
	virtual ~CMainScene();
	bool init() override;

	static cocos2d::Scene* createScene();
	void update(float dt) override;
	CREATE_FUNC(CMainScene);

private:

};

#endif // MAINSCENE_H
