package com.alternate.concurrenthomework.question2;

import com.alternate.concurrenthomework.question2.domain.Satisfactions;
import com.alternate.concurrenthomework.question2.domain.TicketIssuer;

import java.util.concurrent.ThreadLocalRandom;

public class Main {
    public static void main(String[] args) {
        TicketIssuer[] ticketIssuers = new TicketIssuer[100];

        Satisfactions.availableTickets = 100;
        for (int i = 0; i < 100; i++) {
            int randomNum = ThreadLocalRandom.current().nextInt(1, 10 + 1);
            ticketIssuers[i] = new TicketIssuer("Issuer" + (i + 1), randomNum);
        }

        for (TicketIssuer ticketIssuer : ticketIssuers) {
            ticketIssuer.start();
        }
    }
}
