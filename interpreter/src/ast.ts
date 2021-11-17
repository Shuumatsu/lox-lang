type BinaryOperator = '+' | '-' | '*' | '/'

type BinaryExpression = {
    kind: 'Binary Expression'
    operands: [Expression, Expression]
    operator: BinaryOperator
}

type UnaryOperator = '-' | '!'

type UnaryExpression = {
    kind: 'Unary Expression'
    operator: UnaryOperator
    operand: Expression
}

type LiteralExpression = boolean | null | number | string

type Expression = BinaryExpression | UnaryExpression | LiteralExpression
