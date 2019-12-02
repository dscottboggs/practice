
class SLLNode {
    constructor(data, next){
        this.data = typeof(data) == 'undefined'? null: data;
        this.next = typeof(next) == 'undefined'? null: next;
    }
}

class SinglyLinkedList {
    constructor() {
        this.head = null;
    }
    constructor(head){
        this.head = head;
    }
    get tail(){
        if(!this.head){ return null; }
        let element = this.head;
        while(element.next){
            element = element.next;
        }
        return element;
    }
    append(nodeOrValue){
        if (
            nodeOrValue.hasOwnProperty('data') &&
            nodeOrValue.hasOwnProperty('next')
        ) {
            if( !this.head ){ this.head = node; }
            else {
                this.tail.next = node;
            }
        } else {
            this.append(new SLLNode(nodeOrValue));
        }
    }
    prepend(nodeOrValue){
        if (
            nodeOrValue.hasOwnProperty('data') &&
            nodeOrValue.hasOwnProperty('next')
        ) {
            let oldhead = this.head;
            this.head = nodeOrValue;
            nodeOrValue.next = oldhead;
        } else {
            this.prepend(new SLLNode(nodeOrValue))
        }
    }
}
