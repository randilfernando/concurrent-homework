package com.alternate.concurrenthomework.question1.domain;

public class PizzaDelivery extends Thread {

    private int slicesForPizza;

    public PizzaDelivery(String name, int slicesForPizza) {
        super(name);
        this.slicesForPizza = slicesForPizza;
    }

    @Override
    public void run() {
        try {
            execute();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void execute() throws InterruptedException {
        while (true) {
            // delivery thread will wait for the signal
            // when there are no pizza only one student thread will notify while others sleep
            // assume a situation where student thread signal before delivery thread wait
            // semaphore will store previous wake calls hence this does not affect the execution
            Satisfactions.order.acquire();
            // at this point all other thread are blocked and only pizza delivery thread is accessing the variable
            Satisfactions.availableSlices = slicesForPizza;

            System.out.println(this.getName() + ": Pizza is delivered.");

            // notify student thread
            Satisfactions.pizza.release();
        }
    }

}
