# RPCMonitoring-

The objective of the machine problem is to write a network management application that tracks user
logins, CPU usage and other statistics on a host and allows querying by a RPC-based network management
system. Its output can be used to feed into an analysis component for deciding on corrective actions in
self-managing distributed systems.
The system will have multiple clients and single/multiple servers. Clients can send request to a server
running at a different machine to get the current system statistics of the server machine. Track, for example:

• Current system time (can be in different formats such as date, time, or a combination of both.)

• CPU usage

• Memory usage

• Load procs per min

Please take a look at the sample RPC code for this machine problem posted on the Canvas:
RPC mechanism must be used for the communication between clients and the server.
