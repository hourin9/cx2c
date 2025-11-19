#include <iostream>

#include <exprs.hh>
#include <codegen.hh>

int main(void)
{
        Expr expr(
                AssignExpr(
                        Identifier("hello"),
                        std::make_unique<Expr>(ConstLiteral(123.4))
                )
        );

        String code = expr_codegen(expr);
        std::cout << code << "\n";

        return 0;
}

