import java.util.Map;

public class Author {
    
    public final String name;

    public Author(String name) {
        this.name = name;
    }

}

public class Page {

    public final String content;

}

public class Book {

    public final String title;
    public final List<Author> authors;
    protected final List<Page> pages;
    public final int price;

    public Book(String title, List<Author> authors, List<Page> pages, int price) {
        this.title = title;
        this.authors = authors;
        this.pages = pages;
        this.price = price;
    }

    public int pageCount() {
        return this.pages.size();
    }

}

public class BoughtBook extends Book {

    public int lastPage;
    
    public BoughtBook(Book book) {
        super(book.title, book.authors, book.pages, book.price);
    }

    public Page readPage(int pageNumber) {
        this.lastPage = pageNumber;
        return this.pages.get(pageNumber);
    }

}

public class User {

    public final List<BoughtBook> books;
    
    public final String email;
    public final String password;

    private int balance;

    public User() {
        this.books = new ArrayList<>();
    }

    public addBalance(int amount) {
        balance += amount;
    }

    public BoughtBook buy(Book book) {
        if (book.price <= balance) {
            balance -= book.price;

            BoughtBook bought = new BoughtBook(book);
            books.add(bought);
            
            return bought;
        }

        return null;
    }

}

public class BookReader {

    private final List<Book> books;
    private final Map<String, User> users;

    public BookReader() {
        this.books = new Library();
    }

    private boolean validPassword(String password, String hash) {
        return String.valueOf(password.hashCode()).equals(hash);
    }

    public User login(String email, String password) {
        if (users.containsKey(email)) {
            User user = users.get(email);
            if (validPassword(password, user.password)) {
                return user;
            }
        }

        return null;
    }

}
