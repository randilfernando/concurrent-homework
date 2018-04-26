package com.concurrent.senatebusproblem.domain;

import java.util.concurrent.Semaphore;

public class BusHalt {

    public static Semaphore mutex = new Semaphore(1);
    public static Semaphore multiplex = new Semaphore(50);
    public static Semaphore bus = new Semaphore(0);
    public static Semaphore allAboard = new Semaphore(0);
    public static int riders = 0;

}
