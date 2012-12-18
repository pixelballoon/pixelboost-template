#include "pixelboost/graphics/camera/camera.h"
#include "pixelboost/graphics/camera/viewport.h"
#include "pixelboost/graphics/device/device.h"
#include "pixelboost/graphics/renderer/common/renderer.h"
#include "pixelboost/graphics/renderer/primitive/primitiveRenderer.h"
#include "pixelboost/logic/component/graphics/rectangle.h"
#include "pixelboost/logic/system/graphics/render/bounds.h"
#include "pixelboost/logic/entity.h"
#include "pixelboost/logic/scene.h"

#include "game/game.h"

namespace pb
{
    Engine* Engine::Create(void* platformContext, std::vector<std::string> args)
    {
        return new Game(platformContext);
    }
}

Game::Game(void* viewController)
    : pb::Engine(viewController)
{
    _Scene = new pb::Scene();
    
    _Scene->AddSystem(new pb::BoundsRenderSystem());
    
    glm::vec2 displaySize = pb::GraphicsDevice::Instance()->GetDisplayResolution();
    
    _Camera = new pb::OrthographicCamera();
    
    _Viewport = new pb::Viewport(0, _Camera);
    _Viewport->SetResolution(glm::vec2(displaySize.x, displaySize.y/2.f));
    _Viewport->SetPosition(glm::vec2(0, displaySize.y/4.f));
    _Viewport->SetScene(_Scene);
    
    pb::Renderer::Instance()->AddViewport(_Viewport);
}

Game::~Game()
{
    pb::Renderer::Instance()->RemoveViewport(_Viewport);
    
    delete _Viewport;
    delete _Camera;
}

void Game::Update(float time)
{
    _Scene->Update(time);
    
    Engine::Update(time);
}

void Game::Render()
{
    Engine::Render();
}
