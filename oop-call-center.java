import java.util.LinkedList;
import java.util.Queue;

import jdk.internal.org.objectweb.asm.util.CheckMethodAdapter;

public class Call {

    public void pickUp() {
        ...
    }

}

public class Employee {

    private boolean free;

    void handleCall(Call call) {
        free = false;
        call.pickUp();
        free = true;
    }

    boolean isFree() {
        return free;
    }

}

public class Employees extends ArrayList<Employee> {
    
    public boolean anyFree() {
        return firstFree() != null;
    }

    public void takeCall(Call call) {
        firstFree().handleCall(call);
    }

    private Employee firstFree() {
        for (Employee employee : this) {
            if (employee.isFree()) {
                return employee;
            }
        }
        
        return null;
    }

}

public class CallCenter {

    public final Employees respondents;
    public final Employees managers;
    public final Employees directors;

    private final Queue<Call> held;

    public CallCenter() {
        this.respondents = new Employees();
        this.managers = new Employees();
        this.directors = new Employees();

        this.held = new LinkedList<>();
    }

    public void dispatchCall(Call call) {
        if (respondents.anyFree()) {
            respondents.takeCall(call);
            checkHeldCalls();

        } else if (managers.anyFree()) {
            managers.takeCall(call);
            checkHeldCalls();
            
        } else if (directors.anyFree()) {
            directors.takeCall(call);
            checkHeldCalls();

        } else {
            holdCall(call);
        }

    }

    private checkHeldCalls() {
        if (!held.isEmpty()) {
            Call call = held.poll();
            dispatchCall(call);
        }
    }

    private void holdCall(Call call) {
        held.offer(call);
    }

}
