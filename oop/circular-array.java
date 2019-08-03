import java.awt.List;
import java.util.ArrayList;
import java.util.Collections;

public class CircularArray<T> implements Iterable<T> {

    private final List<T> elements;

    public CircularArray(int capacity) {
        elements = new ArrayList<>(capacity);
    }
    
    public CircularArray() {
        elements = new ArrayList<>();
    }
    
    public void shift(int n) {
        n %= elements.size();

        Collections.reverse(elements);
        Collections.reverse(elements.subList(0, n));
        Collections.reverse(elements.subList(n));
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public void add(T added) {
        elements.add(added);
    }

    public void remove(int index) {
        elements.remove(index);
    }

    public T get(int index) {
        return elements.get(index);
    }

    public Iterator<T> iterator() {
        return new CircularArrayIterator();
    }

    class CircularArrayIterator implements Iterator<T> {

        private int index = 0;

        public boolean hasNext() {
            return index < elements.size();
        }

        public T next() {
            return elements.get(index++);
        }

        public void remove() {
            elements.remove(index);
        }

    }
    
}
