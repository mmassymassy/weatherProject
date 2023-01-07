"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.BinaryTree = void 0;
const Node_1 = require("./Node");
class BinaryTree {
    constructor() {
        this.root = null;
    }
    insert(data) {
        if (!this.root) {
            this.root = new Node_1.BinaryNode(data);
            return;
        }
        this.root.insertNode(data);
    }
    print() {
        if (this.root) {
            this.root.print();
        }
    }
}
exports.BinaryTree = BinaryTree;
