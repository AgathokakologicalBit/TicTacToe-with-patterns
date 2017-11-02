// Copyright 2017 Ermishin Michael

#pragma once


#include <bits/unique_ptr.h>
#include "console.h"

class InputManager
{
public:
    // Singletons can not be created or assigned
    InputManager(const InputManager&) = delete;
    InputManager& operator =(const InputManager&) = delete;


private:
    InputManager()
        : _console(new Console)
    {}

public:
    static InputManager& get();

private:
    std::unique_ptr<Console> _console;

public:
    Console * const console() const
    {
        return _console.get();
    }
};
