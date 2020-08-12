#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  i_error = 0;
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
 
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  p_error = -cte * Kp;
  i_error -= cte * Ki;
  d_error = (cte_pre - cte) * Kd; 

  cte_pre = cte; 
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */  
  return (p_error + i_error + d_error);  // TODO: Add your total error calc here!
}