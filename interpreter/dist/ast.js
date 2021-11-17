"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.translate = void 0;
const ts_pattern_1 = require("ts-pattern");
const translate = (node) => {
    const binary = (node) => {
        const operator = node.child(1).text;
        const operands = [(0, exports.translate)(node.child(0)), (0, exports.translate)(node.child(2))];
        return { kind: 'Binary Expression', operands, operator };
    };
    const unary = (node) => {
        const operator = node.child(0).text;
        const operand = (0, exports.translate)(node.child(1));
        return { kind: 'Unary Expression', operand, operator };
    };
    return (0, ts_pattern_1.match)(node.type)
        .with('expression', () => (0, exports.translate)(node.firstChild))
        .with('grouping', () => (0, exports.translate)(node.child(1)))
        .with('literal', () => (0, exports.translate)(node.firstChild))
        .with('number', () => ({ kind: 'Number Literal', value: +node.text }))
        .with('string', () => ({ kind: 'String Literal', value: node.text }))
        .with('nil', () => ({ kind: 'Null Literal' }))
        .with('true', () => ({ kind: 'Boolean Literal', value: true }))
        .with('false', () => ({ kind: 'Boolean Literal', value: true }))
        .with('unary_expression', () => unary(node))
        .with('binary_expression', () => binary(node))
        .otherwise((type) => {
        throw new Error(`Unsupported node type ${type}`);
    });
};
exports.translate = translate;
