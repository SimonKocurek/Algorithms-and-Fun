import java.awt.image.BufferedImage;
import java.util.Set;

public class Edge {

    public boolean fitsWith(Edge other) {
        return this == other;
    }

}

public class Piece {

    public final List<Edge> edges;
    public final BufferedImage image;
    
    public bool fitsWith(Chunk chunk) {
        return fittinEdge(chunk) != null;
    }

    private Edge fittinEdge(Chunk chunk) {
        Set<Edge> possibleFits = chunk.edges();

        for (Edge edge : edges) {
            for (Edge possibleFit: possibleFits) {
                if (edge == possibleFit) {
                    return edge;
                }
            }
        }

        return null;
    }

    public void appendTo(Chunk chunk) {
        ...
    }

}

public class Chunk {

    public final List<List<Piece>> pieces;

    public Set<Edge> edges() {
        ...
    }

    public Set<Piece> tear() {
        Set<Piece> result = new HashSet<>();

        for (List<Piece> line : pieces) {
            for (Piece piece : line) {
                if (piece != null) {
                    result.add(piece);
                }
            }
        }

        pieces.clear();
        return result;
    }

}

public interface Puzzle {

    void solve();

}

public class Jigsaw implements Puzzle {

    public final Chunk result;
    public final Set<Piece> unused;

    public Jigsaw() {
        result = new Chunk();
        unused = Set.of(...);
    }

    public void reset() {
        for (Piece piece : result.tear()) {
            unused.add(piece);
        }
    }

    @Override
    public void solve() {
        while (!unused.isEmpty()) {
            for (Piece piece : unused) {

                if (piece.fitsWith(result)) {
                    piece.appendTo(result);
                    unused.remove(piece);
                }

            }
        }
    }

}
