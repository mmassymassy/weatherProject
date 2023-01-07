export class BinaryNode {
  private Data: number;

  private left: BinaryNode | null = null;
  private right: BinaryNode | null = null;

  constructor(data: number) {
    this.Data = data;
  }

  public insertRight(data: number) {
    this.right = new BinaryNode(data);
  }

  public insertLeft(data: number) {
    this.left = new BinaryNode(data);
  }

  public getLeft() {
    return this.left;
  }

  public getRight() {
    return this.right;
  }

  public getData() {
    return this.Data;
  }

  public insertNode(data: number) {
    if (this.Data > data) {
      const right = this.getRight() 
      if (!right) {
        // if there is no right insert it here
        this.insertRight(data);
        return;
      }
      right.insertNode(data);
    } else {
      const left = this.getLeft()
      // go to left
      if (!left) {
        // there is no left insert here
        this.insertLeft(data);
        return;
      } 
        left.insertNode(data);
    }
  }

  public print(){
    if(this.getRight()){
      this.getRight()?.print()
    }

    console.log(this.Data)

    if(this.getLeft()){
      this.getLeft()?.print()
    }
  }


}
