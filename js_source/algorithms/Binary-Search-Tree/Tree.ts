import { BinaryNode } from "./Node";

export class BinaryTree {
  private root: BinaryNode | null = null;


  public insert(data: number) {
    if (!this.root) {
      this.root = new BinaryNode(data);
      return
    }

    this.root.insertNode(data)
  }

  public print(){
    if(this.root){
        this.root.print()
    }
  }


}
