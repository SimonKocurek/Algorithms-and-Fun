import java.util.Arrays;
import java.util.Iterator;

class FlatteningIterator<T> implements Iterator<T> {

    private final T[][] vector;

    private int line;
    private int index;

    FlatteningIterator(T[][] vector) {
        this.vector = vector;
    }

    @Override
    public boolean hasNext() {
        return line < vector.length;
    }

    @Override
    public T next() {
        T result = vector[line][index++];

        while (line < vector.length && index >= vector[line].length) {
            index = 0;
            line++;
        }

        return result;
    }

}

public class Flatten2dArray {

    public static void main(String[] args) {
        test(new Integer[][] {});
        test(new Integer[][]{
                {1, 2},
                {3},
                {4, 5, 6}
        });
        test(new Integer[][]{
                {1, 2},
                {3},
                {},
                {},
                {4, 5, 6}
        });
    }

    private static void test(Integer[][] flattened) {
        System.out.print("Got: ");
        var flatteningIterator = new FlatteningIterator<>(flattened);
        while (flatteningIterator.hasNext()) {
            System.out.print(flatteningIterator.next() + " ");
        }
        System.out.println();

        var expected = Arrays.stream(flattened)
                .flatMap(Arrays::stream)
                .map(String::valueOf)
                .reduce("", (result, number) -> result + " " + number);
        System.out.println("Expected: " + expected);
    }

}
