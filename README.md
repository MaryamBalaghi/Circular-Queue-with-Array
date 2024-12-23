when we delete an element in front of queue if we have normal queue with deleting an element we free index but we can not use it again,
because we can just add element in the rear position.
So we can use the circular queue.It is also called ‘Ring Buffer’.
one index before front is always kept empty to differentiate between the full and empty states of the queue. 
This is a common design choice in circular queues implemented using arrays.
