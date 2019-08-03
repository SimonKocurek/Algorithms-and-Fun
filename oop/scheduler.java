import java.util.AbstractQueue;
import java.util.concurrent.PriorityBlockingQueue;

class Scheduler {

    public static class Task implements Comparable<Task> {

        public final Runnable function;
        public final long time;

        public Task(Runnable function, long time) {
            this.function = function;
            this.time = time;
        }

        @Override
        public int compareTo(Task t) {
            return Long.compare(time, t.time);
        }
    }

    private AbstractQueue<Task> tasks = new PriorityBlockingQueue<>();

    public Scheduler() {
        new Thread(() -> {
            while (true) {
                boolean ran = false;

                if (!tasks.isEmpty() && tasks.element().time <= System.currentTimeMillis()) {
                    ran = true;
                    tasks.remove().function.run();
                }

                if (ran) {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }).start();
    }

    public void addTask(Runnable function, int time) {
        Task added = new Task(function, System.currentTimeMillis() + time * 1000);
        tasks.add(added);
    }

    public static void main(String[] args) {
        Scheduler s = new Scheduler();
        s.addTask(() -> System.out.println(1), 4);
        s.addTask(() -> System.out.println(2), 5);
        s.addTask(() -> System.out.println(3), 6);
        s.addTask(() -> System.out.println(4), 1);
    }

}

