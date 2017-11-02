// Copyright 2017 Ermishin Michael

#include "input_manager.h"


InputManager& InputManager::get()
{
    static InputManager manager;
    return manager;
}
