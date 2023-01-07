import { getArrayOfRandomNumbers } from "../../helpers/random";
import { BinaryTree } from "./Tree";

const numbers = getArrayOfRandomNumbers(3000);

const tree = new BinaryTree();

numbers.forEach((n) => tree.insert(n));

tree.print();


