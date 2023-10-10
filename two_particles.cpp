#include <iostream>
#include <cmath>

using namespace std;


int main() {
    // printf("Hello World");
    cout << "Start of Simulation" << endl;

    // define time of simulation and time and steps
    double t_start, t_end, dt;
    int t_steps;

    t_start = 10;
    t_end = 50;
    dt = 1; // seconds
    t_steps = round((t_end - t_start) / dt); // integer time steps
    
    // ensure causality
    if (t_start > t_end){
        cout << "Causality Broken! Start time (" << t_start << ") is occurs after end time (" << t_end <<").";
    };

    cout << "Number of time steps = " << t_steps << endl;

    for(int i=0; i<=t_steps; i++) {

        cout << "Loop interation = " << i << endl;
    };

    return 0;
}