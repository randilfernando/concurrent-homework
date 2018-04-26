package com.concurrent.senatebusproblem.domain;

import org.apache.commons.math3.distribution.ExponentialDistribution;

public class BusDispatcher extends Thread {
    private final ExponentialDistribution busWaitTimeDistribution;

    public BusDispatcher(int busWaitTime) {
        super();
        busWaitTimeDistribution = new ExponentialDistribution(busWaitTime * 1000);
    }

    @Override
    public void run() {
        int busCount = 0;
        while (true) {
            int busTime = (int) busWaitTimeDistribution.sample();
            try {
                Thread.sleep(busTime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            busCount++;
            Bus bus = new Bus(String.valueOf(busCount));
            bus.start();
        }
    }
}
