#pragma once

#include <shorthands.hh>

enum class UnaryOperations {
        Not,
        Deref,
        Ref,
};

String unary_to_string(UnaryOperations);

enum class BinaryOperations {
        Add,
        Sub,
        Mul,
        Div,

        Eq, Equal = Eq,
        Neq, NotEqual = Neq,
        Gr, GreaterThan = Gr,
        Gre, GreaterOrEqual = Gre,
        Le, LesserThan = Le,
        Lee, LesserOrEqual = Lee,
};

String binary_to_string(BinaryOperations);

