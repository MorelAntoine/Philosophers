# Philosophers

Dining philosophers problem with threads

    Dev period: 09 march 2017 - 14 march 2017

Rules
=====

* N philosophers are around one table (N is defined on the command line).

* Each philosopher has one rice bowl in front of him.

* There is a chopstick at the left of each bowl.

* A philosopher can only use a chopstick if it is at the left or at the right of his bowl.

* A philosopher goes through three steps:
    * Eats with two chopsticks. One left and one right.
    * Rests, does not use any chopstick, even if one is available.
    * Thinks, uses one and only one chopstick.

* A philosopher that thinks must eat before resting. In order to get his energy back,
obviously.

* After resting, a philosopher can either eat, or think.

* A chopstick cannot be used by two philosophers at the same time.

Usage
=====

        -p followed by the number of philosophers.
        -e followed by the max eat occurence at which the program exits when one
        philosopher reaches it.

Exemple
=======

        $>./philo -p 5 -e 15
        Played game: 1/1
        Philos used: 5/5
        Mutex used: 7
        Chopsticks used: 5/5
        Max Chopsticks used by Philo: 2
        Eat Cycles: 15/15
        Logical Inconsistences found: 0
        System Inconsistences found: 0
        Philo: 140637458786048
        	Eaten 15 times
        	Slept 15 times
        	Thought 14 times
        Philo: 140637450393344
        	Eaten 15 times
        	Slept 15 times
        	Thought 15 times
        Philo: 140637442000640
        	Eaten 15 times
        	Slept 15 times
        	Thought 15 times
        Philo: 140637433607936
        	Eaten 15 times
        	Slept 15 times
        	Thought 15 times
        Philo: 140637425215232
        	Eaten 14 times
        	Slept 14 times
        	Thought 14 times
        Total Philos: 
        	Eaten 74 times
        	Slept 74 times
        	Thought 73 times
        $>

Help
====

When you launch the binary, if you got:

        ./philo: error while loading shared libraries: libriceferee.so: cannot open shared object file: No such file or directory
        
You can fix it by writing on your shell:

        export LD_LIBRARY_PATH=./include
        