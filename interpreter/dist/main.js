"use strict";
var _webTreeSitter = _interopRequireDefault(require("web-tree-sitter"));
var _treeSitterTlox = _interopRequireDefault(require("tree-sitter-tlox"));
function _interopRequireDefault(obj) {
    return obj && obj.__esModule ? obj : {
        default: obj
    };
}
const main = async ()=>{
    await _webTreeSitter.default.init();
    const parser = new _webTreeSitter.default();
    parser.setLanguage(_treeSitterTlox.default);
};
main();
