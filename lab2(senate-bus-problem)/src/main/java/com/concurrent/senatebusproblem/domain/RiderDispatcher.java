package com.concurrent.senatebusproblem.domain;

import org.apache.commons.math3.distribution.ExponentialDistribution;

public class RiderDispatcher extends Thread {
    private final ExponentialDistribution riderWaitTimeDistribution;

    public RiderDispatcher(int riderWaitTime) {
        super();
        riderWaitTimeDistribution = new ExponentialDistribution(riderWaitTime * 1000);
    }

    @Override
    public void run() {
        int riderCount = 0;
        while (true) {
            int riderTime = (int) riderWaitTimeDistribution.sample();
            try {
                Thread.sleep(riderTime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            riderCount++;
            Rider rider = new Rider(String.valueOf(riderCount));
            rider.start();
        }
    }
}
