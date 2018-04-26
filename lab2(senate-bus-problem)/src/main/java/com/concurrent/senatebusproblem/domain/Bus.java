package com.concurrent.senatebusproblem.domain;

/**
 * Created by Adeesha on 2/8/2018.
 */
public class Bus extends Thread {

    public Bus(String name) {
        super(name);
    }

    @Override
    public void run() {
        this.arrive();
        this.waiting();
        this.depart();
    }

    private void arrive() {
        try {
            BusHalt.mutex.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("\nbus:" + this.getName() + " arrived.");
    }

    private void waiting() {
        if (BusHalt.riders > 0) {
            System.out.println(BusHalt.riders + " riders available.");

            BusHalt.bus.release();

            System.out.println("bus:" + this.getName() + " waiting.");

            try {
                BusHalt.allAboard.acquire();
                System.out.println("all boarded.");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private void depart() {
        BusHalt.mutex.release();
        System.out.println("bus:" + this.getName() + " departed.");
    }
}
