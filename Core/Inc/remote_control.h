//
// Created by 32805 on 2023/12/24.
//

#include "main.h"
#include "usart.h"
#ifndef PROJECT_REMOTE_CONTROL_H
#define PROJECT_REMOTE_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

/* ----------------------- RC Channel Definition---------------------------- */
#define RC_CH_VALUE_MIN ((uint16_t)364 )
#define RC_CH_VALUE_OFFSET ((uint16_t)1024)
#define RC_CH_VALUE_MAX ((uint16_t)1684)
/* ----------------------- RC Switch Definition----------------------------- */
#define RC_SW_UP ((uint16_t)1)
#define RC_SW_MID ((uint16_t)3)
#define RC_SW_DOWN ((uint16_t)2)
/* ----------------------- PC Key Definition-------------------------------- */
#define KEY_PRESSED_OFFSET_W ((uint16_t)0x01<<0)
#define KEY_PRESSED_OFFSET_S ((uint16_t)0x01<<1)
#define KEY_PRESSED_OFFSET_A ((uint16_t)0x01<<2)
#define KEY_PRESSED_OFFSET_D ((uint16_t)0x01<<3)
#define KEY_PRESSED_OFFSET_Q ((uint16_t)0x01<<4)
#define KEY_PRESSED_OFFSET_E ((uint16_t)0x01<<5)
#define KEY_PRESSED_OFFSET_SHIFT ((uint16_t)0x01<<6)
#define KEY_PRESSED_OFFSET_CTRL ((uint16_t)0x01<<7)
#define RC_FRAME_LENGTH 18u
/* ----------------------- Data Struct ------------------------------------- */
typedef struct {
    struct {
        uint16_t ch0;
        uint16_t ch1;
        uint16_t ch2;
        uint16_t ch3;
        uint8_t s1;
        uint8_t s2;
    } rc;
    struct {
        int16_t x;
        int16_t y;
        int16_t z;
        uint8_t press_l;
        uint8_t press_r;
    } mouse;
    struct {
        uint16_t v;
    } key;
} RC_Ctl_t;

typedef struct {
    float ch0;
    float ch1;
    float ch2;
    float ch3;
    uint8_t s1;
    uint8_t s2;
} fd;

void RemoteDataProcess(uint8_t *data);
extern uint8_t data[18];
extern uint8_t buffer[18];
extern RC_Ctl_t RC_CtrlData;
#ifdef __cplusplus
};
#endif
#endif //PROJECT_REMOTE_CONTROL_H
