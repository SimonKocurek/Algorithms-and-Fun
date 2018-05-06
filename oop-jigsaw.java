public interface Puzzle {

    void solve();

}

public class Edge {

    public boolean fitsWith(Edge other) {
        return this == other;
    }

}

public class Piece {

    
}

public class Jigsaw implements Puzzle {

    @Override
    public void solve() {

    }

}