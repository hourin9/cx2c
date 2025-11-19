#pragma once

#include <cstdint>

#include <memory>
#include <string>
#include <variant>

struct Expr;

struct SourceInfo {
};

using ConstLiteral = std::variant<int64_t, double, std::string>;

struct Identifier {
        std::string name;
};

struct AssignExpr {
        Identifier tgt;
        std::unique_ptr<Expr> expr;
};

struct Expr {
        SourceInfo inf;
        std::variant
                < std::monostate
                , ConstLiteral
                , AssignExpr
                > v;
};

