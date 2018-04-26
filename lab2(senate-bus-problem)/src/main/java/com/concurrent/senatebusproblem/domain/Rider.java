package com.concurrent.senatebusproblem.domain;

import static com.concurrent.senatebusproblem.constants.ColorCodes.ANSI_GREEN;
import static com.concurrent.senatebusproblem.constants.ColorCodes.ANSI_YELLOW;
import static com.concurrent.senatebusproblem.constants.ColorCodes.ANSI_RESET;

public class Rider extends Thread {

    public Rider(String name) {
        super(name);
    }

    @Override
    public void run() {
        this.arrive();
        this.waiting();
        this.board();
    }

    private void arrive() {
        System.out.print("[rider:" + this.getName() + " arrived] ");
    }

    private void waiting() {
        try {
            BusHalt.multiplex.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        try {
            BusHalt.mutex.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        BusHalt.riders++;
        BusHalt.mutex.release();

        System.out.print(ANSI_YELLOW + "[rider:" + this.getName() + " waiting]" + ANSI_RESET + " ");

        try {
            BusHalt.bus.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        BusHalt.multiplex.release();
    }

    private void board() {
        BusHalt.riders--;

        System.out.print(ANSI_GREEN + "[rider:" + this.getName() + " boarded]" + ANSI_RESET + " ");
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if (BusHalt.riders == 0) {
            BusHalt.allAboard.release();
        } else {
            BusHalt.bus.release();
        }
    }

}
