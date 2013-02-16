#include "pixelboost/graphics/camera/camera.h"
#include "pixelboost/graphics/camera/viewport.h"
#include "pixelboost/input/mouseManager.h"
#include "pixelboost/input/touchManager.h"
#include "pixelboost/logic/component/graphics/rectangle.h"
#include "pixelboost/logic/system/graphics/render/bounds.h"
#include "pixelboost/logic/scene.h"

#include "core/game.h"
#include "screens/menuScreen.h"

class MenuInputHandler : public pb::MouseHandler, public pb::TouchManager
{
public:
    MenuInputHandler()
    {
        
    }
    
    virtual bool OnMouseDown(pb::MouseButton button, pb::ModifierKeys modifierKeys, glm::vec2 position)
    {
        Game::Instance()->SetMode(kGameModeGame);
        return false;
    }
    
    virtual bool OnTouchDown(int touchId, glm::vec2 position)
    {
        Game::Instance()->SetMode(kGameModeGame);
        return false;
    }
};

class TitleText : public pb::Entity
{
public:
    TitleText(pb::Scene* scene)
        : pb::Entity(scene, 0)
    {
        pb::RectangleComponent* rect = new pb::RectangleComponent(this);
        rect->SetSize(glm::vec2(5,1));
        rect->SetSolid(true);
    }
    
    virtual ~TitleText()
    {
        
    }
    
    virtual pb::Uid GetType() const
    {
        return GetStaticType();
    }
    
    static pb::Uid GetStaticType()
    {
        return pb::TypeHash("TitleText");
    }
};

MenuScreen::MenuScreen()
    : _Scene(0)
    , _Viewport(0)
{
    _InputHandler = new MenuInputHandler();
}

MenuScreen::~MenuScreen()
{
    
}

void MenuScreen::Update(float timeDelta, float gameDelta)
{
    
}

void MenuScreen::SetActive(bool active)
{
    Screen::SetActive(active);
    
    if (active)
    {
        Game::Instance()->GetTouchManager()->AddHandler(_InputHandler);
        
        _Camera = new pb::OrthographicCamera();
        _Scene = new pb::Scene();
        _Viewport = new pb::Viewport(0, _Camera);
        _Viewport->SetScene(_Scene);
        
        AddViewport(_Viewport);
        
        _Scene->AddSystem(new pb::BoundsRenderSystem());
        
        AddControls();
    } else {
        Game::Instance()->GetTouchManager()->RemoveHandler(_InputHandler);
        
        DestroyViewport(_Viewport);
        _Viewport = 0;
        delete _Camera;
        _Camera = 0;
    }    
}

void MenuScreen::AddControls()
{
    new TitleText(_Scene);
}
