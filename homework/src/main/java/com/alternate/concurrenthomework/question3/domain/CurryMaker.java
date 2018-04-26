package com.alternate.concurrenthomework.question3.domain;

public class CurryMaker extends Thread {

    public CurryMaker(String name) {
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
        // since both serve at the same time curry maker need to wait until food maker make 2 foods
        System.out.println(this.getName() + " finished creating curry.");
    }

}
