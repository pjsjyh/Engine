#include "Input.h"
#include <algorithm>
namespace so {
    std::vector<Input::Key> Input::Keys = {};
    int ASCII[(UINT)eKeyCode::End] = {
         'Q','W','E','R','T','Y','U','I','O','P',
            'A','S','D','F','G','H','J','K','L',
            'Z','X','C','V','B','N','M',
            VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
    };


    void so::Input::Initialize()
    {
        createKeys();

    }

    void so::Input::Update()
    {
        for (size_t i = 0; i < Keys.size(); i++) {
            if (GetAsyncKeyState(ASCII[i])&0x8000) {
                if (Keys[i].bPressed == true) {
                    Keys[i].state = eKeyState::Pressed;
                }
                else {
                    Keys[i].state = eKeyState::Down;
                }
                Keys[i].bPressed = true;
            }
            else {
                if (Keys[i].bPressed == true) {
                    Keys[i].state = eKeyState::Up;
                }
                else {
                    Keys[i].state = eKeyState::None;
                }
                Keys[i].bPressed = false;
            }
        }
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
   /* void Input::updateKeys()
    {
        std::for_each(mKeys.begin(), mKeys.end(),
            [](Key& key) -> void
        {
            updateKey(key);
        });
    }
    void Input::updateKey(Input::Key& key)
    {
        if (isKeyDown(key.keyCode)) {

        }
        else {

        }
    }
    bool Input::isKeyDown(eKeyCode code)
    {
        return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
    }*/
}
