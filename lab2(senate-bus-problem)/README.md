# Senate bus problem
Java implementation for senate bus problem (CS4532 Lab2)

# Problem
This problem was originally based on the Senate bus at Wellesley College. Riders come to a bus
stop and wait for a bus. When the bus arrives, all the waiting riders invoke boardBus, but anyone who
arrives while the bus is boarding has to wait for the next bus. The capacity of the bus is 50 people; if there
are more than 50 people waiting, some will have to wait for the next bus. When all the waiting riders have
boarded, the bus can invoke depart. If the bus arrives when there are no riders, it should depart
immediately

# Solution

## How to run
```bash
mvn clean package
java -jar senate-bus-problem-1.0.jar
```

## Program arguments
Enter bus wait time (seconds) 	- time waits untill create a new bus
Enter rider wait time (seconds) - time waits until create a new rider

### Sample data
```
Enter bus wait time (seconds) : 40
Enter rider wait time (seconds) : 1
```