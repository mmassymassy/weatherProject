"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getArrayOfRandomNumbers = void 0;
function getArrayOfRandomNumbers(length, max = 1000) {
    return Array.from({ length }, () => Math.floor(Math.random() * max));
}
exports.getArrayOfRandomNumbers = getArrayOfRandomNumbers;
