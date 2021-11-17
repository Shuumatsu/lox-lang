"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const tree_sitter_1 = __importDefault(require("tree-sitter"));
// @ts-ignore
const tree_sitter_lox_1 = __importDefault(require("tree-sitter-lox"));
const commander_1 = require("commander");
const promises_1 = __importDefault(require("fs/promises"));
const ast_1 = require("./ast");
const program = new commander_1.Command();
program.version('0.0.1');
program.option('-f, --file <file>', 'file to interpret');
program.parse(process.argv);
const options = program.opts();
const main = async () => {
    const sourceCode = await promises_1.default.readFile(options.file, 'utf8');
    const parser = new tree_sitter_1.default();
    parser.setLanguage(tree_sitter_lox_1.default);
    const tree = parser.parse(sourceCode);
    const root = tree.rootNode;
    console.log(root);
    console.log((0, ast_1.translate)(root));
};
main();
