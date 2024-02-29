
# UDP SERVER - CLIENT 

SERVER - CLIENT CONNECTION USING UDP IMPLEMENT USING C PROGRAMMING

User Datagram Protocol (UDP) is a Transport Layer protocol. UDP is a part of the Internet Protocol suite, referred to as the UDP/IP suite. Unlike TCP, it is an unreliable and connectionless protocol. So, there is no need to establish a connection before data transfer. The UDP helps to establish low-latency and loss-tolerating connections establish over the network. The UDP enables process-to-process communication.

## FEATURES
![udp](https://github.com/Abhinand-s/s6-networklab/blob/main/2.udp%20serverclient/udp-1.png)

## Features of UDP
Used for simple request-response communication when the size of data is less and hence there is lesser concern about flow and error control.
It is a suitable protocol for multicasting as UDP supports packet switching.
UDP is used for some routing update protocols like RIP(Routing Information Protocol).
Normally used for real-time applications which can not tolerate uneven delays between sections of a received message.
## Advantages of UDP
It does not require any connection for sending or receiving data.
Broadcast and Multicast are available in UDP.
UDP can operate on a large range of networks.
UDP has live and real-time data.
UDP can deliver data if all the components of the data are not complete.
## Disadvantages of UDP
We can not have any way to acknowledge the successful transfer of data.
UDP cannot have the mechanism to track the sequence of data.
UDP is connectionless, and due to this, it is unreliable to transfer data.
In case of a Collision, UDP packets are dropped by Routers in comparison to TCP.
UDP can drop packets in case of detection of errors.

