# Linked list
Insert, update and remove data to linked list

## Sequential
Single threaded approach
### How to run
Run ```gcc src/sequential.c``` to compile the program
Then run ```./a.out [n_value] [m_value] [m_member] [m_insert] [m_delete]```

## One mutex
Multi threaded approach while using one mutex
### How to run
Run ```gcc -pthread src/one_mutex.c``` to compile the program
Then run ```./a.out [n_value] [m_value] [m_member] [m_insert] [m_delete] [thread_cont]```

## Read-write lock
Multi threaded approach while using read-write lock
### How to run
Run ```gcc -pthread src/read_write_lock.c``` to compile the program
Then run ```./a.out [n_value] [m_value] [m_member] [m_insert] [m_delete] [thread_cont]```

## Program arguments
1. n_value - initial amount of records
2. m_malue - number of operations
3. m_member - fraction indicating member operations out of m_value
4. m_insert - fraction indicating insert operations out of m_value
5. m_delete - fraction indicating delete operations out of m_value
6. thread_count - Thread count use (only with multi threaded implementations)