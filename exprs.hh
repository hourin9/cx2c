#pragma once

#include <cstdint>

#include <variant>
#include <string>

struct SourceInfo {
};

using ConstLiteral = std::variant<int64_t, double, std::string>;

struct Identifier {
        std::string name;
};

struct Expr {
        SourceInfo inf;
        std::variant
                < std::monostate
                , ConstLiteral
                > v;
};

