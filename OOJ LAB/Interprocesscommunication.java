import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class InterprocessCommunicationAndDeadlock {

    public static void main(String[] args) {
        // Shared resource
        final SharedResource sharedResource = new SharedResource();

        // Threads simulating interprocess communication and deadlock
        Thread process1 = new Thread(() -> sharedResource.process1(), "Process-1");
        Thread process2 = new Thread(() -> sharedResource.process2(), "Process-2");

        process1.start();
        process2.start();
    }
}

class SharedResource {
    private final Lock lock1 = new ReentrantLock();
    private final Lock lock2 = new ReentrantLock();

    // First process attempting to acquire locks
    public void process1() {
        try {
            System.out.println(Thread.currentThread().getName() + " trying to acquire Lock 1...");
            lock1.lock();
            System.out.println(Thread.currentThread().getName() + " acquired Lock 1.");

            // Simulate work
            Thread.sleep(100);

            System.out.println(Thread.currentThread().getName() + " trying to acquire Lock 2...");
            lock2.lock();
            System.out.println(Thread.currentThread().getName() + " acquired Lock 2.");

        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            lock2.unlock();
            lock1.unlock();
            System.out.println(Thread.currentThread().getName() + " released locks.");
        }
    }

    // Second process attempting to acquire locks in reverse order
    public void process2() {
        try {
            System.out.println(Thread.currentThread().getName() + " trying to acquire Lock 2...");
            lock2.lock();
            System.out.println(Thread.currentThread().getName() + " acquired Lock 2.");

            // Simulate work
            Thread.sleep(100);

            System.out.println(Thread.currentThread().getName() + " trying to acquire Lock 1...");
            lock1.lock();
            System.out.println(Thread.currentThread().getName() + " acquired Lock 1.");

        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            lock1.unlock();
            lock2.unlock();
            System.out.println(Thread.currentThread().getName() + " released locks.");
        }
    }
}
