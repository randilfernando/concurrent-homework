package com.alternate.concurrenthomework.question1.domain;

import java.util.concurrent.Semaphore;

public class Satisfactions {
    // use to notify when there is a pizza available
    public final static Semaphore pizza = new Semaphore(0);
    // use to notify when there is a order available
    public final static Semaphore order = new Semaphore(0);
    // mutex used when reading and updating availableSlices variable
    public final static Semaphore mutex = new Semaphore(1);
    // variable holds the available number of pizza slices
    public static int availableSlices = 0;
}
