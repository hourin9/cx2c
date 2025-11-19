#pragma once

#include <memory>
#include <string>
#include <variant>

template<typename T> using Box = std::unique_ptr<T>;
template<typename T> using Arc = std::shared_ptr<T>;
using None = std::monostate;
using String = std::string;

