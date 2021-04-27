/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Node {
    public char c;
    public int nchstr;
    public Node parent;
    public ArrayList<Node> children;
    
    public Node(char c, Node parent) {
        this.c = c;
        this.parent = parent;
        if (parent != null) {
            parent.nchstr++;
            parent.children.add(this);
        }
        this.children = new ArrayList<Node>();
    }
    
    public void addChild(Node child) {
        children.add(child);
    }
    
    public Node getChild(char cc) {
        for (Node n : children) {
            if (n.c == cc) return n;
        }
        return null;
    }
}

/* Name of the class has to be "Main" only if the class is public. */
public class Main {
    public static void treeify(Node root, String s, int index) {
        boolean treed = false;
        for (Node n : root.children) {
            if (n.c == s.charAt(index)) {
                treed = true;
                root.nchstr++;
                treeify(n, s, index+1);
                break;
            }
        }
        if (!treed) {
            Node prevNode = new Node(s.charAt(index), root);
            for (int i = index+1; i<s.length(); i++) {
                Node tempNode = new Node(s.charAt(i), prevNode);
                prevNode = tempNode;
            }
        }
    }
    
    public static long dfs(Node root, int ns) {
        long sum = 0;
        for (Node n : root.children) {
            if (n.nchstr >= ns || (n.nchstr == 0 && ns == 1)) {
                sum++;
            }
            sum += dfs(n, ns);
        }
        return sum;
    }
    
    public static void printtree(Node root, int ilevel) {
        String pad = "";
        for (int i=0; i < ilevel; i++) {
            pad += " ";
        }
        for (Node n : root.children) {
            System.out.println(pad + n.c + "(" + n.nchstr + ")");
            printtree(n, ilevel+1);
        }
    }
    
	public static void main (String[] args) throws Exception {
	    Scanner sc = new Scanner(System.in);
	    int nstrings = sc.nextInt();
	    Node root = new Node('*', null);
	    for (int i=0; i<nstrings; i++) {
	        treeify(root, sc.next(), 0);
	    }
	    
	    // now do a DFS for given level
	    int nt = sc.nextInt();
	    for (int i=0; i<nt; i++) {
	        int ns = sc.nextInt();
	        long num = dfs(root, ns);
	        System.out.println(num);
	    }
	}
}
