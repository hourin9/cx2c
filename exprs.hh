#pragma once

#include <variant>

struct SourceInfo {
};

struct Expr {
        SourceInfo inf;
        std::variant<std::monostate> v;
};

