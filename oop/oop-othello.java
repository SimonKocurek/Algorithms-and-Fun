import java.util.ArrayList;
import java.util.List;

enum Piece {

    WHITE('w'), BLACK('b'), EMPTY('.');

    private final char sign;

    Piece(char sign) {
        this.sign = sign;
    }

    public Piece opposite() {
        switch (this) {
            case WHITE: return BLACK;
            case BLACK: return WHITE;
            case EMPTY: return EMPTY;
        }

        throw new IllegalStateException();
    }

    @Override
    public String toString() {
        return Character.toString(sign);
    }

}

class Othello {

    private final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    private int blackScore;
    private int whiteScore;

    private Piece turn;
    private List<List<Piece>> board;

    Othello(int boardSize) {
        boardSize *= 2;

        turn = Piece.WHITE;
        board = new ArrayList<>(boardSize);
        fillBoard(boardSize);
    }

    private void fillBoard(int boardSize) {
        if (boardSize <= 2) {
            throw new RuntimeException();
        }

        for (int i = 0; i < boardSize; i++) {
            List<Piece> row = new ArrayList<>(boardSize);

            for (int j = 0; j < boardSize; j++) {
                row.add(Piece.EMPTY);
            }

            board.add(row);
        }

        placeInitialPieces();
    }

    private void placeInitialPieces() {
        int middle = board.size() / 2;
        board.get(middle).set(middle, Piece.BLACK);
        board.get(middle).set(middle + 1, Piece.WHITE);
        board.get(middle + 1).set(middle, Piece.WHITE);
        board.get(middle + 1).set(middle + 1, Piece.BLACK);
    }

    public boolean placePiece(int row, int col) {
        if (!canPlace(row, col)) {
            return false;
        }

        int flipped = placeAndFlip(row, col);
        endTurn(flipped);
        draw();
        return true;
    }

    private boolean canPlace(int row, int col) {
        if (board.get(row).get(col) != Piece.EMPTY) {
            return false;
        }

        for (int[] direction : directions) {
            ...
        }

        return false;
    }

    private int placeAndFlip(int row, int col) {
        int result = 1;
        board.get(row).set(col, turn);

        for (int[] direction : directions) {
            ...
        }

        return result;
    }

    private void endTurn(int flipped) {
        if (turn == Piece.BLACK) {
            blackScore += flipped + 1;
            whiteScore -= flipped;
        } else {
            whiteScore += flipped + 1;
            blackScore -= flipped;
        }

        turn = turn.opposite();
    }

    private void draw() {
        if (gameEnd()) {
            printWinner();
        } else {
            printBoard();
        }
    }

    private boolean gameEnd() {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (canPlace(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    private void printWinner() {
        if (!fullBoard()) {
            System.out.println("Draw");
        } else if (blackScore > whiteScore) {
            System.out.println("Black won");
        } else if (blackScore == whiteScore) {
            System.out.println("White won");
        }
    }

    private boolean fullBoard() {
        return blackScore + whiteScore < board.size() * board.size();
    }

    private void printBoard() {
        for (List<Piece> row : board) {
            for (Piece piece : row) {
                System.out.print(piece);
            }
            System.out.println();
        }

        System.out.println();
    }

    public int getBlackScore() {
        return blackScore;
    }

    public int getWhiteScore() {
        return whiteScore;
    }

}
