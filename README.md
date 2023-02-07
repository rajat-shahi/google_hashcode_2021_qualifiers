Task : 
----

City plan and planned paths for all the cars in the city is given. 
We have to optimize the schedule the traffic lights to minimize the total amount of time spent in traffic.
Also, help as many card as possible to reach their destination before a given deadline.


Problem description :
-------------------


CITY PLAN ==>	City plan has : 				1. one way streets		2. intersections
---------
				
				- each street is given some 'unique' name
				- each street is unidirectional and goes from one intersection to another.
				- does not contain any interections other than the given intersections. i.e. does not have intersections in between.
				- every street have some fixed amount of time 'L' to get from the beginning to the end of the street.
				- if a car enters a street which takes 'L' seconds and it enters at time 'T' then it will reach the other end of the street
				  at 'T + L' seconds irrespective of the number of cars on that street. 

				- it is possible that 2 one-way streets connect 2 intersections in opposite directions.
				- there will, never be 2 streets connecting 2 intersections in the same direction.
				- every intersection has a uniqur integer ID (0,1,2 . . .  )
				- has atleast one street comes and goes out of a particular intersection.


TRAFFIC LIGHTS ==>	- there is a traffic light at the end of every street (just before the intersection)
--------------		- each traffic light has 2 startes => 1. red (can't pass the intersection)
														  2. green (can pass the intersection and go to any of the other streets from that intersection)

					- If there are several streets which comes to a particular intersection then out of all the traffic lights, only one of them 
					  can be 'green' at any particular instant of time.



QUEUING UP ==>	- if some traffix light is red coloured then the cars arriving towards that traffic light have to queue and when the light is green
----------		  then 1 car can cross the intersection in 1 second.

				- this means if green light for a given street is open for 'Ti' seconds then only first 'Ti' cars from the street will continue their
				  travel. Other cars on that street have to wait for green light.



SCHEDULE ==>	- for each intersection we can setup a traffic light schedule.
--------		- the traffic light schedule determines the order and duration of green light for the incoming streets of the intersection
				  ans it repeats itself until the end of the simulation.

				- schedule is list of pairs : {incoming_street, duration}
				- each street can appear at most once in the schedule.
				- the schedule can ignore some of the incoming streets - those will never get a green light.




CARS ==>	- each car is decribed by the path (there will be some sequence of streets through which it will travel).
----		- the paths for cars are defined by the input datasets and can't be changed.
			- it is guaranteed that each car goes through a single intersection at most once.
			- initially, all cars start at the end of the first street in their path, waiting for the green light (if light is red)
			  or ready to move (if the traffic light is green).

			- if 2 cars start at the end of the same street then the car listed first in the input file goes first. After that each car follows 
			  their path according to the schedule of traffic lights and finally reach their destinations (i.e. last street in their path)

			- there will some queue of cars at the end of each street. The first car in the queue can pass the intersection just after the light
			  turns green but after that every car takes 1 second and only 1 car can croos the intersection in 1 second.

			- if some car reaches it's last street then it travels the street length and then it disappears (it does not queue up).




INPUT ==>	- integer D (1<=D<=10^4), the duration of simulation in seconds.
-----		- integer I (2<=I<=10^5), the number of intersections (0.....I-1)
 			- integer S (2<=S<=10^5), the number of streets
 			- integer V (1<=V<=10^3), the number of cars
 			- integer F (1<=F<=10^3), the bonus points for each car that reaches its destination before time D

 			- next 'S' (no. of streets) lines contains description of streets :

 					- 2 integers => 'B' and 'E' - the intersections at the start and the end of the street respectively
 					- string => it shows the street name
 					- integer 'L' - length of the street or the time it takes a car to get from the start to the end of the street.

 			- next 'V' (no. of cars) lines describes the paths of each car :

 					- integer 'P' (2<=P<=10^3) - the number of streets the car wants to travel
 					- 'P' strings which shows the names of the strings through which it travels. The path is always valid.




OUTPUT ==>	- first line contains integer 'A' => the number of intersections for which we want to show the schedule.
------		
			- now for every intersection :

					- 1st line --> integer 'i' => it shows the id of the intersection.
					- 2nd line -> integer 'E' => number of incoming streets for this intersection we have scheduled the traffic lights.
					- Ei lines which print the {street name, duration for which this street have green light} seperated by single space.

			NOTE : Each intersection must comes once in the submission file. Each street name must comes once in a schedule.
				   If street name is not present that means for that street traffic lights are always red.


SCORING ==> A score is awarded for each car that finishes its path before the end of the simulation. For a car that finishes it's path
-------		at time T, the awarded score is 'F' points (fixed award for finishing the path) and additionally 'D-T' points (if T<=D)
			

			IF(T<=D)
			{
				SCORE+=(F+D-T);
			}
			ELSE
			{
				SCORE+=0;
			}

			the overall solution is the sum of scores of all the cars.



			
