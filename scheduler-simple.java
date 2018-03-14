import java.util.Timer;
import java.util.TimerTask;

class Scheduler {

    private Timer timer = new Timer();

    public void addTask(Runnable function, int seconds) {
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                function.run();
            }
        }, seconds * 1000);
    }

    public static void main(String[] args) {
        Scheduler s = new Scheduler();
        s.addTask(() -> System.out.println(1), 4);
        s.addTask(() -> System.out.println(2), 5);
        s.addTask(() -> System.out.println(3), 6);
        s.addTask(() -> System.out.println(4), 1);
    }

}

