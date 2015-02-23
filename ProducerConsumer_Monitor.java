public class ProducerConsumer {
   public static void main(String[] args) {
      monitor c = new monitor();
       Consumer c1 = new Consumer(c, 1);
       Producer p1 = new Producer(c, 1);
     	 Consumer c2 = new Consumer(c, 2);
       Producer p2 = new Producer(c, 2);
	Consumer c3 = new Consumer(c,3);
	Producer p3 = new Producer(c,3);

      System.out.print("\nConsumer 1 arriving\n");
      c1.start();
      System.out.print("\nConsumer 2 arriving\n");
      c2.start();
      System.out.print("\nConsumer 3 arriving\n");
      c3.start();
      System.out.print("\nProducer 1 arriving\n");
      p1.start(); 
      System.out.print("\nProducer 2 arriving\n");
       p2.start();  
	 System.out.print("\nProducer 3 arriving\n");
      p3.start();     
   }
}
class monitor {
   private int contents;
   private boolean available = false;
   public synchronized int get() {
      while (available == false) {
         try {
            wait();
            System.out.print("\nConsumer waiting for Producer\n");
         }
         catch (InterruptedException e) {
         }
      }
      available = false;
      notifyAll();
      return contents;
   }
   public synchronized void put(int value) {
      while (available == true) {
         try {
            wait();
            System.out.print("\nProducer waiting\n");
         }
         catch (InterruptedException e) { 
         } 
      }
      contents = value;
      available = true;
      notifyAll();
   }
}

class Consumer extends Thread {
   private monitor monitor;
   private int number;
   public Consumer(monitor c, int number) {
      monitor = c;
      this.number = number;
   }
   public void run() {
      int value = 0;
        
            value = monitor.get();
            System.out.println("Consumer " 
			+ this.number
+ " consumes: " + value);

}
}

class Producer extends Thread {
private monitor monitor;
private int number;

public Producer(monitor c, int number) {
monitor = c;
this.number = number;
}

public void run() {

monitor.put(this.number);
System.out.println("Producer " + this.number
+ " produces: " + this.number);
try {
sleep((int)(Math.random() * 1000));
} catch (InterruptedException e) { }

}
}
