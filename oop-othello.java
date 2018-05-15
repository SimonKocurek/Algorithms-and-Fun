public enum Color {
    WHITE, BLACK;

    public Color opposite() {
        switch (this) {
            case WHITE: return Color.BLACK;
            case BLACK: return Color.WHITE;
        }

        throw new IllegalStateException();
    }
}

public class Piece {

    private Color color;

    public void flipColor() {
        color = color.opposite();
    }

}

public class Player {

    private int score;

    public int getScore() {
        return score;
    }

}

public class Board {

}

public class Othello {

    public final Player lPlayer;
    public final Player rPlayer;
    public final Board board;

    

}

// Each turn you must flip color of at least 1 opponents piece
// you flip by surrounding with 2 of your own (TOP-BOTTOM, or 
// LEFT-RIGHT)
// Game ends when player cant flip
// Winner has most pieces;