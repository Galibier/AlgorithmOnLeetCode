import java.util.HashMap;
import java.util.Map;

public class LRUCache {
    private int capacity = 0;
    Map<Integer, Node> map = null;
    Node head = null;
    Node tail = null;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap();
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.next = head;
    }

    public int get(int key) {
        if (!map.containsKey((key))) {
            return -1;
        }
        moveToFront(map.get(key));
        return map.get(key).val;
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (map.containsKey(key)) {
            map.get(key).val = value;
            moveToFront(map.get(key));
        } else {
            freeSpace();
            Node n = new Node(key, value);
            map.put(key, n);
            addToFront(n);
        }
    }

    public void freeSpace() {
        if (map.size() == capacity) {
            Node toRemove = head.next;
            map.remove(toRemove.key);
            Node next = toRemove.next;
            head.next = next;
            next.prev = head;
        }
    }

    private void moveToFront(Node newNode) {
        Node prev = newNode.prev;
        Node next = newNode.next;
        prev.next = next;
        next.prev = prev;
        addToFront(newNode);
    }

    private void addToFront(Node newNode) {
        Node prev = tail.prev;
        prev.next = newNode;
        newNode.prev = prev;
        tail.prev = newNode;
        newNode.next = tail;
    }

    class Node {
        int key;
        int val;
        Node prev;
        Node next;

        public Node() {
        }

        public Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }
}
