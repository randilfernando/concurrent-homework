package com.alternate.concurrenthomework.question1;

import com.alternate.concurrenthomework.question1.domain.PizzaDelivery;
import com.alternate.concurrenthomework.question1.domain.Student;

public class Main {

    public static void main(String[] args) {
        Student[] students = new Student[6];

        for (int i = 0; i < 6; i++) {
            students[i] = new Student("Student" + (i + 1));
        }

        new PizzaDelivery("Kamal's pizza", 8).start();

        for (Student student : students) {
            student.start();
        }
    }
}
