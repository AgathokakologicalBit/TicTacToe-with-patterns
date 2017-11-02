// Copyright 2017 Ermishin Michael

#pragma once

#include <string>


/**
 * Cross-platform console class that provides input & output functionality
 */
class Console
{
public:
    /**
     * Reads value from the input stream
     * @tparam T Value type
     * @return value
     */
    template <typename T>
    T read();

    /**
     * Writes value to the output stream
     * @tparam T Value type
     * @param value value to output
     */
    template <typename T>
    void write(const T& value);

    /**
     * Writes multiple values to the output stream, separating them using `sep`
     * @tparam T Value type
     * @tparam Args Other arguments types
     * @param sep Value separator
     * @param value Value to output
     * @param args Variadic arguments list
     */
    template <typename T, typename... Args>
    void write(const std::string& sep, const T& value, Args... args);

    /**
     * Writes values to the output stream the same way `write` does.
     * Added new line at the end of output.
     * @tparam Args Arguments types
     * @param args Variadic arguments list
     */
    template <typename... Args>
    void writeln(Args... args)
    {
        write(args...);
        write('\n');
    }

    /**
     * Clears console text buffer
     */
    void clear();
};
