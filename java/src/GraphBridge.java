import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GraphBridge {

    private static int time = 0;

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

    private static class Vertex {

        int idx;
        List<Edge> edges;

        boolean discovered;
        int discoveryTime;
        Edge discoveryEdge;

        int loopValue;

        Vertex(int idx, List<Edge> edges) {
            this.idx = idx;
            this.edges = edges;
        }

        @Override
        public boolean equals(Object o) {
            return o == this;
        }

        @Override
        public int hashCode() {
            return idx;
        }

    }

    public static void main(String[] args) throws IOException {
        Map<Integer, Vertex> graph = loadGraph();

        int result = -1;
        for (Vertex vertex : graph.values()) {
            result = Math.max(result, findMaxBridge(graph, vertex));
        }
        System.out.println(result);
    }

    private static int findMaxBridge(Map<Integer, Vertex> graph, Vertex current) {
        int result = -1;
        if (current.discovered) {
            return result;
        }

        current.discovered = true;
        current.discoveryTime = time;
        current.loopValue = time;

        for (Edge edge : current.edges) {
            int nextIdx = current.idx == edge.start ? edge.end : edge.start;
            Vertex next = graph.get(nextIdx);

            if (!next.discovered) {
                time++;
                next.discoveryEdge = edge;

                result = Math.max(result, findMaxBridge(graph, next));
                current.loopValue = Math.min(current.loopValue, next.loopValue);

                if (next.loopValue > current.discoveryTime) {
                    result = Math.max(result, edge.weight);
                }

            } else if (current.discoveryEdge != edge) {
                current.loopValue = Math.min(current.loopValue, next.discoveryTime);
            }
        }

        return result;
    }

    private static Map<Integer, Vertex> loadGraph() throws IOException {
        List<Edge> edges = loadEdges();
        Map<Integer, List<Edge>> graph = new HashMap<>();

        for (Edge edge : edges) {
            if (!graph.containsKey(edge.start)) {
                graph.put(edge.start, new ArrayList<Edge>());
            }

            if (!graph.containsKey(edge.end)) {
                graph.put(edge.end, new ArrayList<Edge>());
            }

            graph.get(edge.start).add(edge);
            graph.get(edge.end).add(edge);
        }

        Map<Integer, Vertex> result = new HashMap<>();
        for (Map.Entry<Integer, List<Edge>> vert : graph.entrySet()) {
            result.put(vert.getKey(), new Vertex(vert.getKey(), vert.getValue()));
        }
        return result;
    }

    private static List<Edge> loadEdges() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int connections = Integer.valueOf(bf.readLine());

        List<Edge> result = new ArrayList<>(connections);

        for (int i = 0; i < connections; i++) {
            String[] parts = bf.readLine().split(" ");
            int start = Integer.valueOf(parts[0]);
            int end = Integer.valueOf(parts[1]);
            int weight = Integer.valueOf(parts[2]);

            result.add(new Edge(start, end, weight));
        }

        return result;
    }

}
