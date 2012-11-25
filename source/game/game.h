#pragma once

#include "pixelboost/framework/engine.h"

namespace pb
{
    class OrthographicCamera; 
    class RenderLayer;
    class Scene;
    class Viewport;
}

class Game : public pb::Engine
{
public:
    Game(void* viewController);
    ~Game();
    
    virtual void Update(float time);
    virtual void Render();
    
private:
    pb::OrthographicCamera* _Camera;
    pb::Viewport* _Viewport;
    
    pb::RenderLayer* _Layer;
    
    pb::Scene* _Scene;
};
