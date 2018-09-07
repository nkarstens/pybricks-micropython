#include <pbio/motorcontrol.h>

pbio_error_t pbio_motor_control_set_constant_settings(pbio_port_t port, int16_t counts_per_unit, float_t gear_ratio){
    pbio_error_t status = pbio_motor_status(port);
    if (status == PBIO_SUCCESS) {
        motor_control_settings[motorindex(port)].counts_per_output_unit = gear_ratio * counts_per_unit;
    }
    return status;
}

pbio_error_t pbio_motor_control_set_variable_settings(
        pbio_port_t port,
        int16_t max_speed,
        int16_t tolerance,
        int16_t acceleration_start,
        int16_t acceleration_end,
        int16_t tight_loop_time_ms,
        int16_t pid_kp,
        int16_t pid_ki,
        int16_t pid_kd
    ){
    pbio_error_t status = pbio_motor_status(port);
    if (status == PBIO_SUCCESS) {
        int8_t port_index = motorindex(port);
        motor_control_settings[port_index].max_speed = max_speed;
        motor_control_settings[port_index].tolerance = tolerance;
        motor_control_settings[port_index].acceleration_start = acceleration_start;
        motor_control_settings[port_index].acceleration_end = acceleration_end;
        motor_control_settings[port_index].tight_loop_time_ms = tight_loop_time_ms;
        motor_control_settings[port_index].pid_kp = pid_kp;
        motor_control_settings[port_index].pid_ki = pid_ki;
        motor_control_settings[port_index].pid_kd = pid_kd;       
    }
    return status;
};


pbio_error_t pbio_motor_run(pbio_port_t port, float_t speed){
    // TODO
    printf("run(port=%c, speed=%f)\n", port, speed);
    return PBIO_SUCCESS;
}

pbio_error_t pbio_motor_stop(pbio_port_t port, pbio_motor_stop_t stop, pbio_motor_wait_t wait){
    // TODO
    printf("stop(%c, stop=%d, wait=%d)\n", port, stop, wait);
    return PBIO_SUCCESS;
}

pbio_error_t pbio_motor_run_time(pbio_port_t port, float_t speed, float_t duration, pbio_motor_stop_t stop, pbio_motor_wait_t wait){
    // TODO
    printf("run_time(port=%c, speed=%f, duration=%f, stop=%d, wait=%d)\n", port, speed, duration, stop, wait);
    return PBIO_SUCCESS;
}

pbio_error_t pbio_motor_run_stalled(pbio_port_t port, float_t speed, float_t *stallpoint, pbio_motor_stop_t stop, pbio_motor_wait_t wait){
    // TODO
    printf("run_stalled(port=%c, speed=%f, stop=%d, wait=%d)\n", port, speed, stop, wait);
    if (wait) {
        *stallpoint = 0.0;
        printf("stallpoint=%f\n", *stallpoint);
    }
    return PBIO_SUCCESS;
}

pbio_error_t pbio_motor_run_angle(pbio_port_t port, float_t speed, float_t angle, pbio_motor_stop_t stop, pbio_motor_wait_t wait){
    // TODO
    printf("run_angle(port=%c, speed=%f, angle=%f, stop=%d, wait=%d)\n", port, speed, angle, stop, wait);
    return PBIO_SUCCESS;
}

pbio_error_t pbio_motor_run_target(pbio_port_t port, float_t speed, float_t target, pbio_motor_stop_t stop, pbio_motor_wait_t wait){
    // TODO
    printf("run_target(port=%c, speed=%f, target=%f, stop=%d, wait=%d)\n", port, speed, target, stop, wait);
    return PBIO_SUCCESS;
}

pbio_error_t pbio_motor_track_target(pbio_port_t port, float_t target){
    // TODO
    printf("track_target(port=%c, target=%f)\n", port, target);
    return PBIO_SUCCESS;
}

void motorcontroller(){
    // TODO:
    // This will be the control task that is to be fired at approximately fixed intervals. 
    // This function does the hard work; the functions above just set/get values that
    // this control task uses to control the motors.
}