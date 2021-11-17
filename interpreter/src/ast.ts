import Parser from 'tree-sitter'
import { match, select } from 'ts-pattern'

export type BinaryOperator = '+' | '-' | '*' | '/'

export type BinaryExpression = {
    kind: 'Binary Expression'
    operands: [Expression, Expression]
    operator: BinaryOperator
}

export type UnaryOperator = '-' | '!'

export type UnaryExpression = {
    kind: 'Unary Expression'
    operator: UnaryOperator
    operand: Expression
}

export type NumberLiteral = { kind: 'Number Literal'; value: number }
export type StringLiteral = { kind: 'String Literal'; value: string }
export type BooleanLiteral = { kind: 'Boolean Literal'; value: boolean }
export type NullLiteral = { kind: 'Null Literal' }

export type LiteralExpression = NumberLiteral | NullLiteral | BooleanLiteral | StringLiteral

export type Expression = BinaryExpression | UnaryExpression | LiteralExpression

export const translate = (node: Parser.SyntaxNode): Expression => {
    const binary = (node: Parser.SyntaxNode): BinaryExpression => {
        const operator: BinaryOperator = node.child(1)!.text as BinaryOperator
        const operands: [Expression, Expression] = [translate(node.child(0)!), translate(node.child(2)!)]
        return { kind: 'Binary Expression', operands, operator }
    }
    const unary = (node: Parser.SyntaxNode): UnaryExpression => {
        const operator: UnaryOperator = node.child(0)!.text as UnaryOperator
        const operand: Expression = translate(node.child(1)!)
        return { kind: 'Unary Expression', operand, operator }
    }

    return match(node.type)
        .with('expression', () => translate(node.firstChild!))
        .with('grouping', () => translate(node.child(1)!))
        .with('literal', () => translate(node.firstChild!))
        .with('number', () => ({ kind: 'Number Literal', value: +node.text }))
        .with('string', () => ({ kind: 'String Literal', value: node.text }))
        .with('nil', () => ({ kind: 'Null Literal' }))
        .with('true', () => ({ kind: 'Boolean Literal', value: true }))
        .with('false', () => ({ kind: 'Boolean Literal', value: true }))
        .with('unary_expression', () => unary(node))
        .with('binary_expression', () => binary(node))
        .otherwise((type) => {
            throw new Error(`Unsupported node type ${type}`)
        })
}
