# C++ Solution Overview

This repository contains a C++ implementation of a basic scheduler for the 2021 Google Hash Code qualification round.

## Approach

- **Input parsing** – `code.cpp` reads the simulation parameters, street descriptions, and car paths. It also builds helper maps for quick lookup of incoming streets and their endpoints.
- **Traffic analysis** – For each street, the program counts how many cars plan to enter an intersection from that street. Intersections without incoming traffic are skipped entirely to reduce the output size.
- **Schedule generation** – For each remaining intersection, the program prints a schedule that assigns a one–second green light to every incoming street. Streets with more cars are listed first by iterating the map in reverse order.

## Building

Compile the solver with a C++17 compiler:

```bash
g++ -std=c++17 -D ONLINE_JUDGE google-hashcode-2021-qual/code.cpp -o google-hashcode-2021-qual/code
```

## Running

Run the compiled binary with an input file:

```bash
./google-hashcode-2021-qual/code < google-hashcode-2021-qual/a.txt > schedule.txt
```

The resulting `schedule.txt` can be submitted to the Hash Code judging system.

