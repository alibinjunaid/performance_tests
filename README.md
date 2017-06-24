# performance_tests
Performance test for C++ and Python publisher &amp; subscribers with 4 combinations
# Usage
Clone the git repository and build it in your ws using catkin_make
# Method
In this test, the method of calculating the latency is used to test the performance of C++ and Python publishers and subscribers.
In the SuperAwesome message, the timestamp is recorded and sent in the message converted to string as per required excercise description) before publishing. At subscriber side, the another timestamp is recorded when the subscriber callback function is executed to get time when message is received. 

Time when message was sent is subtracted from time when message was received which gives the Latency between the transmission and reception of the message.
Resolution of the time is set to ms. Latency should be close to 0 if the desired loop at publisher side matches with the rate at which
subscriber is receiving the message.

Loop_rate is automatically changed in real time by incrementing the variable of loop rate after certain time. The maximum loop rate to test was 500kHz.

# Results

C++_Publisher to C++_Subscriber: Both publisher and subscriber match the desired loop even at higher loop_rate frequencies as Latency is zero

C++_Publisher to Python_Subscriber: Latency starts increasing from 0 when desired loop rate exceeds approximately 4kHz and if the loop rate is furter increased,
                                    Latency increases more and the messages start buffering up.
                                    
Python_Publisher to Python_Subscriber: Although the latency is zero as subscriber receives message at the same time when its published, the python publisher is not able to
                                       achieve higher frequencies. Although the desired loop rate is incrementing but the python publisher is unable to cope with the desired 
                                       loop_rate and it can be observed that the loop rate is not actually increasing and becomes constant even the desired loop rate is increased.
                                       
Python_Publisher to C++_Subscriber: Latency is zero as the subscribes receives the message with no delay but desired loop rate is limited as python publisher is not able to cope with
                                    higher frequencies
