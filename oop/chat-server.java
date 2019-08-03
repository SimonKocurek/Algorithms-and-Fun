
public class Message {
    
    public final Timestamp timestamp;
    public final String content;
    public final User author;

    public Message(String content, User author) {
        this.timestamp = new Timestamp(System.currentTimeMillis());
        this.content = content;
        this.author = author;
    }

}

public class Conversation {

    public final List<Message> messages;

    public Conversation() {
        messages = new ArrayList();
    }
    
}

public class ConversationView extends Conversation {

    public final LoggedInUser viewer;

    public ConversationView(LoggedInUser viewer) {
        super();
        this.viewer = viewer;
    }

    public void send(String content) {
        ...
    }

    public void edit(Message message, String newContent) {
        ...
    }

    public void remove(Message message) {
        ...
    }

}

public class Client {

    public final int SERVER_PORT = ...;
    public final String SERVER_ADDRESS = ...;

    public Client() {

    }

    public LoggedInUser logIn(String email, String password) {
        ...
        listen();
    }

    public void listen() {
        ...
    }

}

public class LoggedInUser extends User {

    private List<ConversationView> Conversations;
    
}

// =========================================

public class Server {

    public final int PORT;

    public static void main() {
        try (Socket sock = new Socket(PORT)) {
            while (true) {
                Request request = getRequest();
                authentificate(request);
            }
        } catch (Exception e) {
            ...
        }
    }

    public void authentificate(Request request) {
        if (valid(request)) {
            Cookie session = new Cookie(request);
            sendSessionCookie(session);
            spinUpSessionThread(session);
        }
    }

    private void sendSessionCookie(Cookie session) {
        ...
    }

    private void spinUpSessionThread(Cookie session) {
        new Thread() {
            ...
        }.start();
    }

}

// Hardest problem to solve is:
// Keeping client subscriptions consistent
