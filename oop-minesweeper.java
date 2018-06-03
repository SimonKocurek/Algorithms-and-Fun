import java.util.ArrayList;
import java.util.List;

enum Type {
    FLAGGED, HIDDEN, SHOWN
}

class Cell {

    public Type type = Type.HIDDEN;
    public boolean isMine = false;
    public int neighbours = 0;

    public Cell() {
    }

    @Override
    public String toString() {
        switch (type) {
            case HIDDEN:
                return ".";
            case FLAGGED:
                return "l";
            case SHOWN:
                return String.valueOf(neighbours);

            default:
                throw new RuntimeException();
        }
    }

}

class Minesweeper {

    private List<List<Cell>> cells;
    private final int[][] directions = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};

    public Minesweeper(int size, int mines) {
        generate(size, mines);
        draw();
    }

    private void generate(int size, int mines) {
        cells = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            List<Cell> row = new ArrayList<>(size);

            for (int j = 0; j < size; j++) {
                row.add(new Cell());
            }

            cells.add(row);
        }

        spreadMines(mines);
    }

    private void spreadMines(int mines) {
        if (mines > cells.size() * cells.size()) {
            throw new RuntimeException();
        }

        int[] minesInRow = new int[cells.size()];
        for (int i = 0; i < mines; i++) {
            int row = (int) (Math.random() * cells.size());

            while (minesInRow[row] >= cells.size()) {
                row = (int) (Math.random() * cells.size());
            }

            minesInRow[row]++;
        }

        for (int i = 0; i < cells.size(); i++) {
            addMines(i, minesInRow[i]);
        }
    }

    private void addMines(int row, int mines) {
        for (int i = 0; i < mines; i++) {
            addMine(row);
        }
    }

    private void addMine(int row) {
        int col = (int) (Math.random() * cells.size());

        while (cells.get(row).get(col).isMine) {
            col = (int) (Math.random() * cells.size());
        }

        cells.get(row).get(col).isMine = true;

        markNeighbours(row, col);
    }

    private void markNeighbours(int row, int col) {
        for (int[] direction : directions) {
            int new_row = row + direction[0];
            int new_col = col + direction[1];

            if (valid(new_row, new_col)) {
                cells.get(new_row).get(new_col).neighbours++;
            }
        }
    }

    public void leftClick(int row, int col) {
        checkDimensions(row, col);
        fill(row, col);
        draw();
    }

    private void fill(int row, int col) {
        Cell cell = cells.get(row).get(col);

        if (cell.type == Type.HIDDEN) {
            cell.type = Type.SHOWN;
        } else {
            return;
        }

        if (cell.neighbours > 0) {
            return;
        }

        for (int[] direction : directions) {
            int new_row = row + direction[0];
            int new_col = col + direction[1];

            if (valid(new_row, new_col)) {
                fill(new_row, new_col);
            }
        }
    }

    public void rightClick(int row, int col) {
        checkDimensions(row, col);

        Cell cell = cells.get(row).get(col);
        switch (cell.type) {
            case HIDDEN:
                cell.type = Type.FLAGGED;
                break;
            case FLAGGED:
                cell.type = Type.HIDDEN;
                break;
        }

        draw();
    }

    private void checkDimensions(int row, int col) {
        if (!valid(row, col)) {
            throw new RuntimeException();
        }
    }

    private boolean valid(int row, int col) {
        return row >= 0 && row < cells.size() && col >= 0 && col < cells.size();
    }

    private void draw() {
        if (won()) {
            System.out.println("You Won!");
        } else if (lost()) {
            System.out.println("You Lost!");
        } else {
            drawCells();
        }
    }

    private void drawCells() {
        for (List<Cell> row : cells) {

            for (Cell cell : row) {
                System.out.print(cell);
            }

            System.out.println();
        }
        System.out.println();

    }

    private boolean won() {
        for (List<Cell> row : cells) {
            for (Cell cell : row) {
                if (cell.type == Type.HIDDEN && !cell.isMine) {
                    return false;
                }

                if (cell.type == Type.SHOWN && cell.isMine) {
                    return false;
                }
            }
        }

        return true;
    }

    private boolean lost() {
        for (List<Cell> row : cells) {
            for (Cell cell : row) {
                if (cell.type == Type.SHOWN && cell.isMine) {
                    return true;
                }
            }
        }

        return false;
    }

}

class Scratch {
    public static void main(String[] args) {
        Minesweeper game = new Minesweeper(10, 12);
        game.leftClick(2, 2);
        game.rightClick(2, 2);
        game.leftClick(2, 2);

        game.rightClick(6, 6);
        game.leftClick(6, 6);
        game.rightClick(6, 6);
        game.leftClick(6, 6);

        game.leftClick(2, 6);
        game.leftClick(1, 6);
        game.leftClick(6, 7);
    }
}