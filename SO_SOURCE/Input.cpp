#include "Input.h"
#include <algorithm>
#include "soApplication.h"

extern so::Application app;
namespace so {
    std::vector<Input::Key> Input::Keys = {};
    math::Vector2 Input::mMousePosition = math::Vector2::One;
    int ASCII[(UINT)eKeyCode::End] = {
         'Q','W','E','R','T','Y','U','I','O','P',
            'A','S','D','F','G','H','J','K','L',
            'Z','X','C','V','B','N','M',
            VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
            VK_LBUTTON, VK_RBUTTON, VK_MBUTTON,
    };


    void so::Input::Initialize()
    {
        createKeys();

    }

    void so::Input::Update()
    {
        updateKeys();
    }

    void so::Input::createKeys() {
        for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
            Key key = {};
            key.bPressed = false;
            key.state = eKeyState::None;
            key.keyCode = (eKeyCode)i;
            Keys.push_back(key);
        }
    }
    void Input::updateKeys()
    {
        std::for_each(Keys.begin(), Keys.end(),
            [](Key& key) -> void
        {
            updateKey(key);
        });
    }
    void Input::updateKey(Input::Key& key)
    {
        //윈도우 활성화 됐는지 확인 방법
        if (GetFocus())
        {
            if (isKeyDown(key.keyCode))
                updateKeyDown(key);
            else
                updateKeyUp(key);

            getMousePositionByWindow();
        }
        else
        {
            clearKeys();
        }
    }
    bool Input::isKeyDown(eKeyCode code)
    {
        return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
    }
    void Input::updateKeyDown(Input::Key& key)
    {
        if (key.bPressed == true)
            key.state = eKeyState::Pressed;
        else
            key.state = eKeyState::Down;

        key.bPressed = true;
    }
    void Input::updateKeyUp(Input::Key& key)
    {
        if (key.bPressed == true)
            key.state = eKeyState::Up;
        else
            key.state = eKeyState::None;

        key.bPressed = false;
    }
    void Input::getMousePositionByWindow()
    {
        POINT mousePos = { };
        GetCursorPos(&mousePos);
        ScreenToClient(app.GetHwnd(), &mousePos);

        mMousePosition.x = mousePos.x;
        mMousePosition.y = mousePos.y;
    }
    void Input::clearKeys()
    {
        for (Key& key : Keys)
        {
            if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
                key.state = eKeyState::Up;
            else if (key.state == eKeyState::Up)
                key.state = eKeyState::None;

            key.bPressed = false;
        }
    }
}
