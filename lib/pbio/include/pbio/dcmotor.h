// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2020 The Pybricks Authors

#ifndef _PBIO_DCMOTOR_H_
#define _PBIO_DCMOTOR_H_

#include <stdint.h>
#include <pbio/config.h>
#include <pbio/iodev.h>
#include <pbio/parent.h>
#include <pbio/port.h>

typedef enum {
    PBIO_DIRECTION_CLOCKWISE,         /**< Positive means clockwise */
    PBIO_DIRECTION_COUNTERCLOCKWISE,  /**< Positive means counterclockwise */
} pbio_direction_t;

#define PBIO_DUTY_USER_STEPS (100)

typedef enum {
    PBIO_DCMOTOR_COAST,       /**< dcmotor set to coast */
    PBIO_DCMOTOR_BRAKE,       /**< dcmotor set to brake */
    PBIO_DCMOTOR_DUTY,        /**< dcmotor set to constant duty. */
} pbio_passivity_t;

typedef struct _pbio_dcmotor_t {
    pbio_port_id_t port;
    pbio_iodev_type_id_t id;
    pbio_direction_t direction;
    pbio_passivity_t state;
    int32_t voltage_now;
    int32_t max_voltage;
    pbio_parent_t parent;
} pbio_dcmotor_t;

#if PBIO_CONFIG_DCMOTOR

// Setup and status
pbio_error_t pbio_dcmotor_get_dcmotor(pbio_port_id_t port, pbio_dcmotor_t **dcmotor);
pbio_error_t pbio_dcmotor_setup(pbio_dcmotor_t *dcmotor, pbio_direction_t direction);
pbio_error_t pbio_dcmotor_get_state(pbio_dcmotor_t *dcmotor, pbio_passivity_t *state, int32_t *voltage_now);

// Settings
int32_t pbio_dcmotor_get_max_voltage(pbio_iodev_type_id_t id);
pbio_error_t pbio_dcmotor_set_settings(pbio_dcmotor_t *dcmotor, int32_t max_voltage);
void pbio_dcmotor_get_settings(pbio_dcmotor_t *dcmotor, int32_t *max_voltage);

// System motor controls: Actuation only.
pbio_error_t pbio_dcmotor_stop(pbio_dcmotor_t *dcmotor);
pbio_error_t pbio_dcmotor_set_voltage(pbio_dcmotor_t *dcmotor, int32_t voltage);

// User motor controls: Actuates and handles stopping of parent objects that use this motor
pbio_error_t pbio_dcmotor_coast(pbio_dcmotor_t *dcmotor);
pbio_error_t pbio_dcmotor_brake(pbio_dcmotor_t *dcmotor);
pbio_error_t pbio_dcmotor_set_voltage_passive(pbio_dcmotor_t *dcmotor, int32_t voltage);

#else

static inline pbio_error_t pbio_dcmotor_get_dcmotor(pbio_port_id_t port, pbio_dcmotor_t **dcmotor) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbio_dcmotor_get_state(pbio_dcmotor_t *dcmotor, pbio_passivity_t *state, int32_t *voltage_now) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbio_dcmotor_stop(pbio_dcmotor_t *dcmotor) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbio_dcmotor_coast(pbio_dcmotor_t *dcmotor) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbio_dcmotor_brake(pbio_dcmotor_t *dcmotor) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbio_dcmotor_set_voltage(pbio_dcmotor_t *dcmotor, int32_t voltage) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline pbio_error_t pbio_dcmotor_set_voltage_passive(pbio_dcmotor_t *dcmotor, int32_t voltage) {
    return PBIO_ERROR_NOT_SUPPORTED;
}
static inline int32_t pbio_dcmotor_get_max_voltage(pbio_iodev_type_id_t id) {
    return 9000;
}
static inline void pbio_dcmotor_get_settings(pbio_dcmotor_t *dcmotor, int32_t *max_voltage) {
}
static inline pbio_error_t pbio_dcmotor_set_settings(pbio_dcmotor_t *dcmotor, int32_t max_voltage) {
    return PBIO_ERROR_NOT_SUPPORTED;
}

#endif // PBIO_CONFIG_DCMOTOR

#endif // _PBIO_DCMOTOR_H_
