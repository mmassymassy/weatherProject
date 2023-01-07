"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const random_1 = require("../../helpers/random");
const Tree_1 = require("./Tree");
const numbers = (0, random_1.getArrayOfRandomNumbers)(3000);
const tree = new Tree_1.BinaryTree();
numbers.forEach((n) => tree.insert(n));
tree.print();
