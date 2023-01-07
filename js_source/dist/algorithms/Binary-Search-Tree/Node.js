"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.BinaryNode = void 0;
class BinaryNode {
    constructor(data) {
        this.left = null;
        this.right = null;
        this.Data = data;
    }
    insertRight(data) {
        this.right = new BinaryNode(data);
    }
    insertLeft(data) {
        this.left = new BinaryNode(data);
    }
    getLeft() {
        return this.left;
    }
    getRight() {
        return this.right;
    }
    getData() {
        return this.Data;
    }
    insertNode(data) {
        if (this.Data > data) {
            const right = this.getRight();
            if (!right) {
                // if there is no right insert it here
                this.insertRight(data);
                return;
            }
            right.insertNode(data);
        }
        else {
            const left = this.getLeft();
            // go to left
            if (!left) {
                // there is no left insert here
                this.insertLeft(data);
                return;
            }
            left.insertNode(data);
        }
    }
    print() {
        var _a, _b;
        if (this.getRight()) {
            (_a = this.getRight()) === null || _a === void 0 ? void 0 : _a.print();
        }
        console.log(this.Data);
        if (this.getLeft()) {
            (_b = this.getLeft()) === null || _b === void 0 ? void 0 : _b.print();
        }
    }
}
exports.BinaryNode = BinaryNode;
