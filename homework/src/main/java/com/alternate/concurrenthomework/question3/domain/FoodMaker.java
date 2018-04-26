package com.alternate.concurrenthomework.question3.domain;

public class FoodMaker extends Thread {

    public FoodMaker(String name) {
        super(name);
    }

    @Override
    public void run() {
        try {
            this.create();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void create() throws InterruptedException {
        // since both serve at the same time food maker need to wait until curry maker make 2 curries
        System.out.println(this.getName() + " finished creating food.");
    }
}
