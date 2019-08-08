import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class SkuskaMotovod {

    /**
     * Bipartite coloring colors:
     */
    private static final int LEFT_BANK = 1;
    private static final int RIGHT_BANK = 2;
    private static final int UNVISITED = -1;

    public static void main(String[] args) {
        // Nice api of scanner with performance benefits of Buffered Reader
        // This works even on problems with large input sets
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int sets = sc.nextInt();
        for (int i = 0; i < sets; i++) {
            int stops = sc.nextInt();
            int roads = sc.nextInt();

            // We want to find out if the graph is bipartite
            // Meaning that for each vertex on the left bank there are only roads to the right bank
            // A simple DFS can do that for us

            // We chose map representation of graph instead of matrix, as 10_000^2 vertexes is too much to store
            // and it is very sparse graph, with only 20_000 edges at most

            // Duplicated edges will not change bipartitness, however list is faster than set
            // so we chose mapping: stop -> connected stops
            Map<Integer, List<Integer>> graph = loadGraph(roads, sc);

            int[] color = new int[stops];
            Arrays.fill(color, UNVISITED);

            // We default to a valid graph
            // in case we detect that the graph is not bipartite, we can end prematurely
            String result = "ANO";

            // Start the DFS for each component
            for (int stop : graph.keySet()) {
                if (color[stop] != UNVISITED) {
                    // if stop already has a color that means we already processed its component
                    continue;
                }

                if (!isBipartite(graph, color, stop)) {
                    result = "NIE";
                    break;
                }
            }

            System.out.println(result);
        }
    }


    private static boolean isBipartite(Map<Integer, List<Integer>> graph, int[] color, int start) {
        // In case you decide to go with BFS
        // ArrayDeque is a faster implementation of Queue than LinkedList
        // it works in a way similar to ArrayList
        Stack<Integer> dfs = new Stack<>();
        dfs.push(start);

        color[start] = LEFT_BANK;

        while (!dfs.empty()) {
            int currentStop = dfs.pop();
            int neighbourColor = getOppositeColor(color[currentStop]);

            for (int neighbour : graph.get(currentStop)) {
                // in bipartite graphs neighbour must have opposite colors
                if (color[neighbour] == color[currentStop]) {
                    return false;
                }

                if (color[neighbour] == UNVISITED) {
                    color[neighbour] = neighbourColor;
                    dfs.push(neighbour);
                }

                // else the color is opposite and already processed
            }
        }

        // We didn't detect a problem with bipartitness
        return true;
    }

    private static int getOppositeColor(int color) {
        return color == LEFT_BANK ? RIGHT_BANK : LEFT_BANK;
    }

    private static Map<Integer, List<Integer>> loadGraph(int roads, Scanner sc) {
        Map<Integer, List<Integer>> graph = new HashMap<>();

        for (int road = 0; road < roads; road++) {
            // Undo fucked up indexing from 1
            int start = sc.nextInt() - 1;
            int end = sc.nextInt() - 1;

            // putIfAbsent is not usable in RKB's tester, as it does not support java 8
            graph.putIfAbsent(start, new ArrayList<>());
            graph.putIfAbsent(end, new ArrayList<>());

            // roads are bidirectional
            graph.get(start).add(end);
            graph.get(end).add(start);
        }

        return graph;
    }

}
