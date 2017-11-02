// Copyright 2017 Ermishin Michael

#include <cstdarg>
#include <iostream>
#include <utility>

#include "console.h"


template <typename T>
void Console::write(const T& value)
{
    std::cout << value;
}

template <typename T, typename... Args>
void Console::write(const std::string& sep, const T& value, Args... args)
{
    std::cout << value;
    using expander = int[];
    static_cast<void>(expander{0, (void(std::cout << sep << std::forward<Args>(args)), 0)... });
}

template <typename T>
T Console::read()
{
    T value;
    std::cin >> value;
    return value;
}
