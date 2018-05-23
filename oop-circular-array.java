import java.util.ArrayList;

public class CircularArray<T> implements Iterable<T> {

    private final List<T> elements;

    public CircularArray(int capacity) {
        elements = new ArrayList<>(capacity);
    }
    
    public CircularArray() {
        elements = new ArrayList<>();
    }
    
    public void shift(int n) {

    }

    public void add(T added) {

    }

    public void remove(int index) {

    }

    public T get(int index) {

    }

    public Iterator<T> iterator() {
        return new CircularArrayIterator();
    }

    class CircularArrayIterator implements Iterator<T> {

        private int index = 0;

        public boolean hasNext() {

        }

        public T next() {

        }

        public void remove() {

        }
        
    }
    
}

// iterable shiftable array