import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Slova {

    private static class Node {
        int[] ends = new int[21];
        Node[] children = new Node['z' - 'a' + 1];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int words = Integer.valueOf(bf.readLine());

        Node root = new Node();
        for (int i = 0; i < words; i++) {
            String word = bf.readLine();
            addWord(root, word, 0);
        }

        int queries = Integer.valueOf(bf.readLine());
        for (int i = 0; i < queries; i++) {
            String[] parts = bf.readLine().split(" ");
            int len = Integer.valueOf(parts[0]);
            String start = parts.length == 2 ? parts[1] : "";

            Node head = move(root, start, 0);
            System.out.println(depth(head, len));
        }
    }

    private static void addWord(Node root, String word, int i) {
        if (i == word.length()) {
            return;
        }

        root.ends[word.length() - i]++;

        char c = word.charAt(i);

        if (root.children[c - 'a'] == null) {
            root.children[c - 'a'] = new Node();
        }

        addWord(root.children[c - 'a'], word, i + 1);
    }

    private static Node move(Node root, String word, int i) {
        if (i == word.length()) {
            return root;
        }

        char c = word.charAt(i);
        if (root.children[c - 'a'] == null) {
            return null;
        }

        return move(root.children[c - 'a'], word, i + 1);
    }

    private static int depth(Node root, int len) {
        if (root == null) {
            return 0;
        }

        return root.ends[len];
    }

}
