import java.util.ArrayList;

public class Timer {
    public static final long MILLIS_IN_MINUTE = 1000 * 60;
}

public class Car {

    private Spot spot;

    public final int sizeX;
    public final int sizeY;

    public Car(int sizeX, int sizeY) {
        this.sizeX = sizeX;
        this.sizeY = sizeY;
    }

    public bool parked() {
        return spot != null;
    }

    public void parkAt(Spot spot) {
        if (parked()) {
            throw new Exception();
        }

        spot.enter();
        this.spot = spot;
    }

    public void unpark() {
        if (!parked()) {
            throw new Exception();
        }

        spot.leave();
        this.spot = null;
    }

}

public enum TicketType {
    
    HOUR(15, 60), HALF_DAY(165, 720), DAY(300, 1440);

    public final int price;
    public final long time;
    
    private TicketType(int price, long time) {
        this.price = price;
        this.time = time;
    }

}

public class Ticket {

    public final long validUntil;
    public final boolean special;

    private Ticket(TicketType type, boolean special) {
        this.validUntil = System.currentTimeMillis() / Timer.MILLIS_IN_MINUTE + type.time;
        this.special = special;
    }

    public static Ticket buy(TicketType type, boolean special) {
        return new Ticket(type, special);
    }

}

public class Spot {

    private final int sizeX;
    private final int sizeY;

    private Ticket ticket;
    private Car car;

    private final boolean special;

    public Spot(int sizeX, int sizeY, boolean special) {
        this.sizeX = sizeX;
        this.sizeY = sizeY;
        this.special = special;
    }

    public boolean canFit(Car car, Ticket ticket) {
        if (special && !ticket.special) {
            return false;
        }

        return car.sizeX <= sizeX && car.sizeY <= sizeY;
    }

    public boolean free() {
        checkTicketValidity();
        return ticket == null;
    }

    private void checkTicketValidity() {
        long currentTime = System.currentTimeMillis() / Timer.MILLIS_IN_MINUTE;
        if (ticket != null && ticket.validUntil < currentTime) {
            ticket = null;
        }
    }

}

public class ParkingLot {
    
    public final List<Spot> spots;

    public ParkingLot() {
        this.spots = new ArrayList<>();
    }

}
