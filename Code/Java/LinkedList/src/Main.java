class Node{
    public int data;
    public Node next;

    public Node(int data){
        this.data = data;
        this.next = null;
    }

    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }
}

class LinkedList{
    public Node head;
    public Node tail;

    public LinkedList(){
        head = null;
        tail = null;
    }

    public void insertAtHead(int data){
        Node newNode = new Node(data);

        if(head == null){
            head = tail = newNode;
        } else{
            newNode.next = head;
            head = newNode;
        }
    }

    public void insertAtTail(int data){
        Node newNode = new Node(data);

        if(head == null){
            head = tail = newNode;
        } else{
            tail.next = newNode;
            tail = newNode;
        }
    }

    public void insertAtBackWithNoTail(int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
        }else{
            Node tail = head;
            while(tail.next != null){
                tail = tail.next;
            }
            tail.next = newNode;
        }
    }

    public void removeFromFront(){
        if(head == null){
            System.out.println("List is empty");
        }else{
            Node temp = head;
            head = head.next;
            temp.next = null;
        }
    }

    public void removeFromBack(){
        if(head == null){
            System.out.println("List is empty");
        }else{
            Node temp = head;
            while(temp.next != tail){
                temp = temp.next;
            }
            temp.next = null;
            tail = temp;
        }
    }
    public void print(){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println("null");
    }

}
public class Main {

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertAtHead(1);
        list.insertAtHead(2);
        list.insertAtHead(3);
        list.print();
        list.insertAtTail(4);
        list.insertAtTail(5);
        list.insertAtTail(6);
        list.print();
        list.removeFromFront();
        list.print();
        list.removeFromBack();
        list.print();
    }
}
