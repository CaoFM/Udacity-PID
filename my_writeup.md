
# **PID Controller** 

**Udacity PID Controller Project**

The goals / steps of this project are the following:
* Code a PID controller to control the steering wheel angle of the vehicle
* Run Simulation with Udacity simulation tool
* Tune the PID parameters so that vehicle can drive around the simulation track
* Summarize the results with a written report


## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/1972/view) individually and describe how I addressed each point in my implementation.  

---
### Compilation

#### 1. Your code should compile.
My code compiles.
```sh
cmake .. && make
```

### Implementation

#### 1. The PID procedure follows what was taught in the lessons.
My PID controller uses the error as an input then calculate the P, I and D error as below.
```c
  p_error = -cte * Kp;
  i_error -= cte * Ki;
  d_error = (cte_pre - cte) * Kd; 
  cte_pre = cte; 
  ```
Then combine P, I and D as the final output.
```c
return (p_error + i_error + d_error);
  ```


### Reflection

#### 1. Describe the effect each of the P, I, D components had in your implementation.
The P term is proportional to the error received to correct the steering angle to reduce error.
The I term reduces static error in case the error grows one direction even without input.
The D term increases response to a growing error while damps response to decreasing error.

#### 2. Describe how the final hyperparameters were chosen.
The final gain is chosen in such a way that the vehicle can negate the sharp turns found on the track (with a big enough P gain), and uses D gain to reduce the oscillation caused by the big P gain during relatively straight line driving. The I gain is chosen to be small to avoid I-term wind-up.

### Simulation

#### 1. The vehicle must successfully drive a lap around the track.
The vehicle drives successfully around the track with the tuned controller.

