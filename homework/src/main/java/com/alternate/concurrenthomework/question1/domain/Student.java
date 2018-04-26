package com.alternate.concurrenthomework.question1.domain;

public class Student extends Thread {

    public Student(String name) {
        super(name);
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
            // only one thread can access the critical section
            Satisfactions.mutex.acquire();
            //============================== critical section ==============================//
            // when there are no pizza slices available
            if (Satisfactions.availableSlices == 0) {
                System.out.println(this.getName() + ": No slices available.");

                // notify pizza delivery thread
                Satisfactions.order.release();
                // student thread will wait for the signal
                // assume a situation where pizza delivery notify before student thread wait
                // semaphore will store previous wake calls hence this does not affect the execution
                Satisfactions.pizza.acquire();
            }

            // in this point there should be pizza available to grab
            // if there are enough slices then availableSlices > 0
            // if there are not enough slices then delivery should happen hence availableSlices > 0
            Satisfactions.availableSlices--;

            System.out.println(this.getName() + ": Grab a slice.");
            //=========================== end of critical section ===========================//
            // this will release mutex, other threads can enter the critical section
            Satisfactions.mutex.release();
            study();
        }
    }

    private void study() {
        // student thread will sleep for 2 seconds (eat and study)
        System.out.println(this.getName() + ": Study while eating.");
    }

}
