import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class HashTable<K, V> {

    private static class HashedKey<K> {

        public int hash;
        public K key;

        public HashedKey(K key) {
            this.hash = key.hashCode();
            this.key = key;
        }

        public boolean fromKey(K key) {
            if (hash != key.hashCode()) {
                return false;
            }

            if (this.key == key) {
                return true;
            }

            return this.key.equals(key);
        }

    }

    private static class BucketValue<K, V>{

        public HashedKey<K> hashedKey;
        public V value;

        public BucketValue(HashedKey<K> hashedKey, V value) {
            this.hashedKey = hashedKey;
            this.value = value;
        }

        public boolean fromKey(K key) {
            return hashedKey.fromKey(key);
        }

    }

    private static class Bucket<K, V> extends LinkedList<BucketValue<K, V>> {}

    private List<Bucket<K, V>> values; 
    private int size = 0;

    public HashTable() {
        this(10);
    }

    public HashTable(int capacity) {
        if (capacity < 0) {
            throw new Exception();
        }

        values = new ArrayList(capacity);
    }

    public V get(K key) {
        int bucket = key.hashCode() % values.size();
        Bucket<K, V> bucketValues = values.get(bucket);

        for (BucketValue<K, V> bucketValue : bucketValues) {
            if (bucketValue.fromKey(key)) {
                return bucketValue.value;
            }
        }

        throw new ElementMissingException();
    }

    public void put(K key, V value) {
        BucketValue<K, V> bucketValue = new BucketValue(new HashedKey(key), value);
        
        size++;
        if (values.size() * 2 <= size * 3) {
            rebucket();
        }

        int bucket = bucketValue.hashedKey.hash % values.size();
        values.get(bucket).add(bucketValue);
    }
    
    private void rebucket() {
        List<Bucket<K, V>> rebucketed = new ArrayList<>(values.size() * 2);
        
        for (Bucket<K, V> bucket : values) {
            for (BucketValue<K, V> bucketValue : bucket) {
                int newBucket = bucketValue.hashedKey.hash % rebucketed.size();
                rebucketed.get(newBucket).add(bucketValue);
            }
        }

        values = rebucketed;
    }

    public void remove(K key) {
        int bucket = key.hashCode() % values.size();
        Bucket<K, V> bucketValues = values.get(bucket);

        for (Iterator<BucketValue<K, V>> it = bucketValues.iterator(); it.hasNext();) {
            BucketValue<K, V> bucketValue = it.next();
            
            if (bucketValue.fromKey(key)) {
                it.remove();
                size--;
                collapseBucketsIfNeeded();
                break;
            }
        }
    }

    private void collapseBucketsIfNeeded() {
        if (size < values.size() ...) {
            ...
        }
    }

}
