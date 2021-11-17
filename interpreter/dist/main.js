"use strict";
var _treeSitter = _interopRequireDefault(require("tree-sitter"));
var _treeSitterLox = _interopRequireDefault(require("tree-sitter-lox"));
var _commander = require("commander");
var _promises = _interopRequireDefault(require("fs/promises"));
var _getStdin = _interopRequireDefault(require("get-stdin"));
function _interopRequireDefault(obj) {
    return obj && obj.__esModule ? obj : {
        default: obj
    };
}
const program = new _commander.Command();
program.version('0.0.1');
program.option('-f, --file [file]', 'file to interpret');
program.parse(process.argv);
const options = program.opts();
const main = async ()=>{
    const sourceCode = await (options.file ? _promises.default.readFile(options.file, 'utf8') : (0, _getStdin).default());
    const parser = new _treeSitter.default();
    parser.setLanguage(_treeSitterLox.default);
    const tree = parser.parse(sourceCode);
    console.log(tree);
};
main();
