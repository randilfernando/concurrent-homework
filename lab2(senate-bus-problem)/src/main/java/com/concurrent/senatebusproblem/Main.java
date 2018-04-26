package com.concurrent.senatebusproblem;

import com.concurrent.senatebusproblem.domain.BusDispatcher;
import com.concurrent.senatebusproblem.domain.RiderDispatcher;

import java.util.Scanner;

/**
 * Created by Adeesha on 2/8/2018.
 */
public class Main {

    public static void main(String[] arg) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter bus wait time (seconds): ");
        int busWaitTime = scanner.nextInt();
        System.out.print("Enter rider wait time (seconds): ");
        int riderWaitTime = scanner.nextInt();

        BusDispatcher busDispatcher = new BusDispatcher(busWaitTime);
        RiderDispatcher riderDispatcher = new RiderDispatcher(riderWaitTime);

        busDispatcher.start();
        riderDispatcher.start();
    }
}
