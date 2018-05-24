import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.sql.Timestamp;
import java.util.List;

public class Authority {

    public boolean read;
    public boolean write;
    public boolean execute;

}

public class Rights {

    public Authority user;
    public Authority group;
    public Authority other;

}

public class File {

    private static final String PATH_SEPARATOR = "/";
    
    public File parent;
    public int size;
    public Rights rights;
    public final List<File> files;
    public final Timestamp created;
    public Timestamp lastUpdated;
    public String name;

    public FileOutputStream outputStream() {
        ...
    }

    public FileInputStream inputStream() {
        ...
    }

    public isDirectory() {
        return files.isEmpty();
    }

    public void createFile() {
        if (isDirectory()) {
            throw new Exception();
        }

        ...
    }

    public String getPath() {
        StringBuilder result = new StringBuilder();

        File current = this;
        while (current != null) {
            result.insert(0, FILE.PATH_SEPARATOR);
            result.insert(0, current.name);

            current = current.parent;
        }

        return result.toString();
    }

}
