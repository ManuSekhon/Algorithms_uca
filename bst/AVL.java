/**
 * Implementation of AVL tree.
 */
public class AVL<Key extends Comparable<Key>, Value> {

    // Root of tree
    private Node root = null;

    /** Public methods */

    // Insert Node into tree
    public void put(Key key, Value value) throws IllegalArgumentException {
        if (key == null && value == null)
            throw new IllegalArgumentException("key and value should not be null");
        this.root = put(key, value, this.root);
    }

    // Return true if tree contains given key
    public boolean contains(Key key) throws IllegalArgumentException {
        if (key == null)
            throw new IllegalArgumentException("key should not be null");
        return search(key) != null;
    }

    // Return value of given key
    public Value get(Key key) throws IllegalArgumentException {
        if (key == null)
            throw new IllegalArgumentException("key should not be null");
        Node x = search(key);
        return (x != null) ? x.value : null;
    }

    // Return true if tree is empty
    public boolean isEmpty() {
        return this.root == null;
    }

    // Clear tree
    public void clear() {
        this.root = null;
    }

    // Return height of tree
    public int height() {
        return height(this.root);
    }

    // Return size of tree
    public int size() {
        return size(this.root);
    }

    /** Private methods */

    private Node put(Key key, Value value, Node n) {
        if (n == null)
            return new Node(key, value);
        int cmp = key.compareTo(n.key);

        // Tree already has given key
        if (cmp == 0) {
            n.value = value;
            return n;
        } 
        else if (cmp < 0) {
            n.left = put(key, value, n.left);
        } 
        else if (cmp > 0)
            n.right = put(key, value, n.right);

        n.size = 1 + size(n.left) + size(n.right);
        n.height = 1 + Math.max(height(n.left), height(n.right));

        return balance(n);
    }

    // Return number of nodes in subtree rooted at n
    private int size(Node n) {
        if (n == null)
            return 0;
        return n.size;
    }

    // Return height of subtree rooted at n
    private int height(Node n) {
        if (n == null)
            return 0;
        return n.height;
    }

    // Balance node n
    private Node balance(Node n) {
        if (balanceFactor(n) > 1) {
            if (balanceFactor(n.left) < 0)
                n.left = rotateLeft(n.left);
            n = rotateRight(n);
        } 
        else if (balanceFactor(n) < -1) {
            if (balanceFactor(n.right) > 0)
                n.right = rotateRight(n.right);
            n = rotateLeft(n);
        }

        return n;
    }

    // Return balance factor of node n
    private int balanceFactor(Node n) {
        return height(n.left) - height(n.right);
    }

    // Rotate node n to right
    private Node rotateRight(Node n) {
        Node y = n.left;
        n.left = y.right;
        y.right = n;

        y.size = n.size;
        y.height = 1 + Math.max(height(y.left), height(y.right));
        n.size = 1 + size(n.left) + size(n.right);
        n.height = 1 + Math.max(height(n.left), height(n.right));
        return y;
    }

    // Rotate node n to left
    private Node rotateLeft(Node n) {
        Node y = n.right;
        n.right = y.left;
        y.left = n;

        y.size = n.size;
        y.height = 1 + Math.max(height(y.left), height(y.right));
        n.size = 1 + size(n.left) + size(n.right);
        n.height = 1 + Math.max(height(n.left), height(n.right));
        return y;
    }

    // Return node of given key; null if key not found
    private Node search(Key key) {
        Node n = this.root;

        while (n != null) {
            int cmp = key.compareTo(n.key);
            if (cmp == 0)
                return n;
            else if (cmp < 0)
                n = n.left;
            else
                n = n.right;
        }
        return null;
    }

    /** Node of tree */
    private class Node {
        private Key key;
        private Value value;
        private Node left, right;
        // size is needed to compute rank
        private int height, size;

        // initialize node
        public Node(Key key, Value value) {
            this.key = key;
            this.value = value;
            this.left = this.right = null;
            // assume height and size of single node to be 1
            this.height = this.size = 1;
        }
    }
}