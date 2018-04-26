Read Me

this project contains 3 files

serial.c - sequential
one_mutex.c - using one mutex
read_write_lock.c - using read write lock

to compile
==========

1. serial.c

gcc <filename>.c

2. one_mutex.c or read_write_lock.c

gcc -pthread <filename>.c


to run
==========

1. serial.c

./a.out [n_value] [m_value] [m_member] [m_insert] [m_delete]

eg: ./a.out 1000 10000 0.99 0.005 0.005

2. one_mutex.c

./a.out [n_value] [m_value] [m_member] [m_insert] [m_delete] [thread_cont]

eg: ./a.out 1000 10000 0.99 0.005 0.005 2

3. read_write_lock.c

./a.out [n_value] [m_value] [m_member] [m_insert] [m_delete] [thread_cont]

eg: ./a.out 1000 10000 0.99 0.005 0.005 2
