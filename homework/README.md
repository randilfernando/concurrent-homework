# About
Answers for concurrent homework problems  
Implemented using Java

# Question 1
A group of students are studying for CS 4532 exam. The students can study only while eating pizza.
Each student executes the following loop:
```
while (true) {
 pick up a slice of pizza;
 study while eating the pizza
}
```
If a student finds that the pizza is gone, the student goes to sleep until another pizza arrives. The first
student to discover that the group is out of pizza calls Kamal’s Pizza to order another pizza before
going to sleep. Each pizza has s slices. Once Kamal delivers pizza, he wake up all the students in the
group. Then the students pick up a slice of pizza and go back to studying, and the process continues.
Write code to synchronize the student threads and the Kamal’s pizza delivery thread.
Your solution should avoid deadlock and call Kamal’s Pizza (i.e., wake up the delivery thread) exactly
once each time a pizza is exhausted. No slice/piece of pizza may be consumed by more than one
student. Comment your code. 

# Question 2
Tickets for a concert are to be sold through a web site. Only a limited number of tickets are
available and multiple fans may try to purchase them at the same time. Each fan can
purchase up to 4 tickets at a time. Write a server-side script to keep track of the remaining
number of tickets and income earned from tickets. No need to keep track of who purchased
tickets.

# Question 3
Kamal and Rani work in a restaurant that specializes in a made-to-order Koththu Roti and
Curry combination. Kamal makes 2 rounds of Koththu Roti while, at the same time, Rani
makes 2 bowls of Curry. When the Koththu Roti and Curry are ready Kamal and Rani each,
at the same time, serve a Koththu Roti and Curry combination to a customer(s). These 
Page 2 of 2
actions are repeated throughout the day. Note that Kamal cannot serve until Rani has made
the curry and Rani cannot serve until Kamal has made the Koththu Roti. Write a concurrent
program that demonstrates the behavior of Kamal and Rani while satisfying the given
constraints.
