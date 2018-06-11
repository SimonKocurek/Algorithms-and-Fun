import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Stream;

/*
test.txt:

1 2 2
2 3 2
2 4 1
3 5 2
4 6 5
5 7 2
5 8 3
7 8 1
6 9 2
8 9 1

Test2.txt:

1 2 2
2 3 2
2 4 1
3 5 2
4 6 5
5 7 2
5 8 3
7 8 1
6 9 2
8 9 1
1 9 11

test3.txt:

1 2 2
2 3 2
2 4 1
3 5 2
4 6 5
5 7 2
5 8 3
7 8 1
6 9 2
8 9 1
1 9 10
2 9 4
 */

class Edge implements Comparable<Edge> {

    final int to;
    final int weight;

    Edge(int from, int weight) {
        this.to = from;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge edge) {
        return Integer.compare(weight, edge.weight);
    }

}

class Node {

    List<Edge> edges = new ArrayList<>();

}

class Main {

    public static void main(String[] args) {
        int from = 1;
        int to = 9;

        Map<Integer, Node> graph = loadGraph(new File("test.txt"));
        System.out.println("Expected: 3 Got: " + shortestPathsCount(graph, from, to));

        Map<Integer, Node> graph2 = loadGraph(new File("test2.txt"));
        System.out.println("Expected: 3 Got: " + shortestPathsCount(graph2, from, to));

        Map<Integer, Node> graph3 = loadGraph(new File("test3.txt"));
        System.out.println("Expected: 1 Got: " + shortestPathsCount(graph3, from, to));
    }

    private static Map<Integer, Node> loadGraph(File file) {
        Map<Integer, Node> graph = new HashMap<>();

        try (Stream<String> stream = Files.lines(Paths.get(file.toURI()))) {
            stream.forEach(line -> parseLine(line, graph));
        } catch (IOException e) {
            e.printStackTrace();
        }

        return graph;
    }

    private static void parseLine(String line, Map<Integer, Node> graph) {
        try (Scanner parser = new Scanner(line)) {
            int from = parser.nextInt();
            int to = parser.nextInt();
            int weight = parser.nextInt();

            addEdge(graph, from, to, weight);

        } catch (Exception e) {
            throw new RuntimeException("File in wrong format, " +
                    "please format each line such that it has 3 integers: from to weight. " +
                    "Instead of " + line, e);
        }
    }

    private static void addEdge(Map<Integer, Node> graph, int from, int to, int weight) {
        graph.putIfAbsent(from, new Node());
        graph.putIfAbsent(to, new Node());

        Edge edge = new Edge(to, weight);
        graph.get(from).edges.add(edge);
    }

    private static int shortestPathsCount(Map<Integer, Node> graph, int from, int to) {
        PriorityQueue<Edge> paths = new PriorityQueue<>();
        Map<Integer, Integer> distances = new HashMap<>();
        Map<Integer, Integer> shortestPaths = new HashMap<>();

        paths.offer(new Edge(from, 0));

        while (!paths.isEmpty()) {
            Edge current = paths.poll();

            if (!distances.containsKey(current.to) || distances.get(current.to) > current.weight) {
                shortestPaths.put(current.to, 0);
                distances.put(current.to, current.weight);
            }

            if (distances.get(current.to) == current.weight) {
                shortestPaths.put(current.to, shortestPaths.get(current.to) + 1);
            }

            List<Edge> neighbours = graph.get(current.to).edges;
            for (Edge edge : neighbours) {
                int newDistance = current.weight + edge.weight;
                paths.offer(new Edge(edge.to, newDistance));
            }
        }

        return shortestPaths.get(to);
    }

}
