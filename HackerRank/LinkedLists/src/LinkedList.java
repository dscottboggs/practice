
class SLLNode {
    int data;
    SLLNode next;
    SLLNode(int node_data){
        this.data = node_data;
        this.next = null;
    }
    SLLNode(int node_data, SLLNode next_node){
        this.data = node_data;
        this.next = next_node;
    }
}

class SinglyLinkedList {
    SLLNode head;
    private SLLNode tail;

    SinglyLinkedList(){
        // Empty list constructor
        this.head = null;
    }

    SinglyLinkedList(SLLNode head){
        // Constructor with element specified.
        this.head = head;
    }

    private static boolean isPresent(SLLNode node){
        return (node != null);
    }

    public SLLNode getTail(){
        // Retrieve the last element of the list
        if (isPresent(this.head)){
            return this.head;
        }
        SLLNode element = this.head;
        while (isPresent(element.next)){
            element = element.next;
        }
        return element;
    }

    public int getLength(){
        // The number of elements in this linked list
        int length = 1;
        SLLNode element = this.head;
        while (isPresent(element.next)){
            element = element.next;
            length++;
        }
        return length;
    }

    public void list_elements(){
        // Print each element of the current list to a new line on stdout.
        this.list_elements_of(this.head);
    }

    public static void list_elements_of(SinglyLinkedList list){
        // Print each element of the given list to a new line on stdout.
        list.list_elements_of(list.head);
    }

    public static void list_elements_of(SLLNode head){
        // Print each element of the list starting at the given node.
        if (isPresent(head)){
            System.out.println("null");
        } else {
            SLLNode element = head;
            while (element.next != null){
                System.out.println(element.data);
            }
            System.out.println(element.data);
        }
    }

    public void prepend(int data){
        // Prepend the given data to the current list. It will be the new head.
        this.head = new SLLNode(data, this.head);
    }

    public static SinglyLinkedList prepend_to(SinglyLinkedList list, int data){
        // prepend the given data to the given list, returning the new list.
        list.prepend(data);
        return list;
    }

    public void append(SLLNode node){
        if ( isPresent(this.head) ) {
            this.getTail().next = node;
        } else {
            this.head = node;
        }
    }

    public void append(int data){
        this.append(new SLLNode(data));
    }

    public static SinglyLinkedList append_to(SinglyLinkedList list, int data){
        list.append(data);
        return list;
    }
    public static SinglyLinkedList append_to(
        SinglyLinkedList list, SLLNode node
    ){
        list.append(node);
        return list;
    }

    public void insert(
        int data, int position
    ) throws IllegalArgumentException {
        // Insert the given data at the given index of this list.
        this.insert(new SLLNode(data), position);
    }
    public void insert(
        SLLNode node, int position
    ) throws IllegalArgumentException {
        // Insert the given node at the given index of this list.
        int index = 0;
        SinglyLinkedList oldList = new SinglyLinkedList(this.head);
        SLLNode workingNode = oldList.head;
        this.head = null;
        while (index < position){
            if( !isPresent(workingNode.next) ){
                throw new IllegalArgumentException(String.format(
                    "Position %d is greater than the length (%d) of this list.",
                    position,
                    this.getLength()
                ));
            }
            index++;
            this.append(workingNode.data);
            workingNode = workingNode.next;
        }
        this.append(node);
        this.append(workingNode);
    }
    public static SLLNode insert_in_from_head(
        SLLNode head, int data, int position
    ) throws IllegalArgumentException {
        SinglyLinkedList outlist = new SinglyLinkedList(head);
        outlist.insert(data, position);
        return outlist.head;
    }

    public void print_len(){
        System.out.println(String.format(
            "This list is %d nodes long.", this.getLength()
        ));
    }

    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList(
            new SLLNode(1, new SLLNode(2, new SLLNode(3)))
        );
        list.print_len();
        list.insert(0, 0);
        list.insert(10, 2);
        list.print_len();
    }
}
