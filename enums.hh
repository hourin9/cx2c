#pragma once

enum class UnaryOperations {
        Not,
        Deref,
        Ref,
};

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

