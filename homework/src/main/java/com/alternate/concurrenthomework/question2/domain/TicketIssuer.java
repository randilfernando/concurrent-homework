package com.alternate.concurrenthomework.question2.domain;

public class TicketIssuer extends Thread {

    private int ticketsNeeded;

    public TicketIssuer(String name, int ticketsNeeded) {
        super(name);
        this.ticketsNeeded = ticketsNeeded;
    }

    @Override
    public void run() {
        try {
            this.bookTicket();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void bookTicket() throws InterruptedException {
        Satisfactions.mutex1.acquire();
        // =============================== critical section 1 =============================== //
        boolean isAvailable = Satisfactions.availableTickets >= ticketsNeeded;
        if (isAvailable) {
            Satisfactions.availableTickets -= ticketsNeeded;
            System.out.println(this.getName() + ": " + ticketsNeeded + " tickets grabbed. Proceed to payment.");
        } else {
            System.out.println(this.getName() + ": " + ticketsNeeded + " tickets not available.");
        }
        // ============================ end of critical section 1 ============================ //
        Satisfactions.mutex1.release();

        if (isAvailable) this.pay();
    }

    private void pay() throws InterruptedException {
        // since two mutexes are used some thread can grab tickets white another thread is at the payment section
        Satisfactions.mutex2.acquire();
        // =============================== critical section 2 =============================== //
        double amount = Satisfactions.ticketPrice * ticketsNeeded;
        Satisfactions.income += amount;

        System.out.println(this.getName() + ": " + amount + " payed.");
        // ============================ end of critical section 2 ============================ //
        Satisfactions.mutex2.release();
    }
}
