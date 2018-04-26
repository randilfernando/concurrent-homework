package com.alternate.concurrenthomework.question3.domain;

public class Shop extends Thread {

    @Override
    public void run() {
        try {
            execute();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void execute() throws InterruptedException {
        // assumption1: both Kamal and Rani start creating curries when there are two customers available
        // assumption2: both of them create 2 foods and 2 curries
        // assumption3: after serving those they will wait or another 3 customers
        while (true) {
            FoodMaker foodMaker = new FoodMaker("Kamal");
            CurryMaker curryMaker = new CurryMaker("Rani");
            // fork and join technique used
            // fork child threads to execute parallel tasks
            foodMaker.start();
            curryMaker.start();
            // wait until all the child threads complete and then join them
            foodMaker.join();
            curryMaker.join();
            // from here onwards all the child threads are completed
            serve();
        }
    }

    private void serve() {
        System.out.println("Serve foods and curries to customer(s)");
    }

}
