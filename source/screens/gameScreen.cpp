#include "pixelboost/graphics/camera/camera.h"
#include "pixelboost/graphics/camera/viewport.h"
#include "pixelboost/logic/scene.h"

#include "screens/gameScreen.h"

GameScreen::GameScreen()
    : _Scene(0)
    , _Viewport(0)
{
    
}

GameScreen::~GameScreen()
{
    
}

void GameScreen::Update(float timeDelta, float gameDelta)
{
    
}

void GameScreen::SetActive(bool active)
{
    if (active)
    {
        _Camera = new pb::OrthographicCamera();
        _Scene = new pb::Scene();
        _Viewport = new pb::Viewport(0, _Camera);
        
        AddViewport(_Viewport);
    } else {
        DestroyViewport(_Viewport);
        _Viewport = 0;
        delete _Camera;
        _Camera = 0;
    }
}
