package com.alternate.concurrenthomework.question2.domain;

import java.util.concurrent.Semaphore;

public class Satisfactions {
    // keep the ticket price to calculate income
    // this is a read only variable hence no mutual exclusion
    public final static double ticketPrice = 1000.00;
    // keep track of available tickets
    public static int availableTickets = 10;
    // keep track of income received
    public static double income = 0.00;
    // guard available tickets variable
    public final static Semaphore mutex1 = new Semaphore(1);
    // guard income received variable
    public final static Semaphore mutex2 = new Semaphore(1);
}
