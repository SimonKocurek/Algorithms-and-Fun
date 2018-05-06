import java.util.ArrayList;

public class Vehicle {

    private boolean handicappedTicket;

    public boolean hasHandicappedTicket() {
        return handicappedTicket;
    }

}

public class Spot {

    protected Vehicle vehicle;

    public boolean canTake(Vehicle vehicle) {
        return this.vehicle == null;
    }

    public boolean has(Vehicle vehicle) {
        return this.vehicle == vehicle;
    }

    public void take(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public Vehicle unpark() {
        Vehicle unparked = this.vehicle;
        this.vehicle = null;
        return unparked;
    }

}

public class HandicappedSpot extends Spot {

    @Override
    public boolean canTake(Vehicle vehicle) {
        return super.canTake(vehicle) && vehicle.hasHandicappedTicket();
    }

}

public class ParkingLot {
    
    public final List<Spot> spots;

    public ParkingLot() {
        this.spots = new ArrayList<>();
    }

    public Spot spotFor(Vehicle vehicle) {
        for (Spot spot : spots) {
            if (spot.canTake(vehicle)) {
                return spot;
            }
        }

        return null;
    }

    public Spot SpotWith(Vehicle vehicle) {
        for (Spot spot : spots) {
            if (spot.has(vehicle)) {
                return spot;
            }
        }

        return null;
    }

}
