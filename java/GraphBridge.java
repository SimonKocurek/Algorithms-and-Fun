import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class GraphBridge {

    private static int LOOP_EDGE = -1;

    private static class Edge {

        int start;
        int end;
        int weight;

        Edge(int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public boolean equals(Object o) {
            return this == o;
        }

    }

    public static void main(String[] args) throws IOException {
        Map<Integer, List<Edge>> graph = loadGraph();

        int result = -1;
        for (List<Edge> vertexEdges : graph.values()) {
            for (Edge edge : vertexEdges) {

                if (edge.weight == LOOP_EDGE) {
                    continue;
                }

                Set<Edge> visited = new HashSet<>();
                visited.add(edge);
                if (isCycle(graph, visited, edge, edge.start)) {
                    edge.weight = LOOP_EDGE;
                    continue;
                }

                result = Math.max(result, edge.weight);
            }
        }

        System.out.println(result);
    }

    private static Map<Integer, List<Edge>> loadGraph() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int connections = Integer.valueOf(bf.readLine());

        Map<Integer, List<Edge>> graph = new HashMap<>();

        for (int i = 0; i < connections; i++) {
            String[] parts = bf.readLine().split(" ");
            int start = Integer.valueOf(parts[0]);
            int end = Integer.valueOf(parts[1]);
            int weight = Integer.valueOf(parts[2]);

            if (!graph.containsKey(start)) {
                graph.put(start, new ArrayList<Edge>());
            }

            if (!graph.containsKey(end)) {
                graph.put(end, new ArrayList<Edge>());
            }

            Edge edge = new Edge(start, end, weight);
            graph.get(start).add(edge);
            graph.get(end).add(edge);
        }

        return graph;
    }

    private static boolean isCycle(Map<Integer, List<Edge>> graph, Set<Edge> visited, Edge current, int wantedEnd) {
        for (Edge edge : graph.get(current.end)) {
            if (visited.contains(edge)) {
                continue;
            }

            if (edge.end == wantedEnd || edge.start == wantedEnd) {
                edge.weight = LOOP_EDGE;
                return true;
            }


            visited.add(edge);
            if (isCycle(graph, visited, edge, wantedEnd)) {
                edge.weight = LOOP_EDGE;
                return true;
            }
            visited.remove(edge);
        }

        return false;
    }

}
