#pragma once

#include <cstdint>

#include <memory>
#include <string>
#include <variant>

#include <enums.hh>
#include <shorthands.hh>

struct Expr;

struct SourceInfo {
};

using ConstLiteral = std::variant<int64_t, double, String>;

struct Identifier {
        String name;
};

struct AssignExpr {
        Identifier tgt;
        Box<Expr> expr;
};

struct UnaryExpr {
        UnaryOperations op;
        Box<Expr> expr;
};

struct BinaryExpr {
        BinaryOperations op;
        Box<Expr> lhs, rhs;
};

using Variant = std::variant
        < None
        , ConstLiteral
        , AssignExpr
        , UnaryExpr
        , BinaryExpr
        >;

struct Expr {
        Expr() = default;
        Expr(Variant v) : inf({}), v(std::move(v)) {}
        Expr(SourceInfo inf, Variant v) : inf(inf), v(std::move(v)) {}

        SourceInfo inf;
        Variant v;
};

