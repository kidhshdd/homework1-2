//
// Created by 32805 on 2023/12/24.
//
#include "remote_control.h"

RC_Ctl_t RC_CtrlData;
fd fbdata;
uint8_t data[18];
uint8_t buffer[18];

void RemoteDataProcess(uint8_t *pData) {
    if (pData == NULL) {
        return;
    }

    RC_CtrlData.rc.ch0 = ((int16_t) pData[0] | ((int16_t) pData[1] << 8)) & 0x07FF;
    RC_CtrlData.rc.ch1 = (((int16_t) pData[1] >> 3) | ((int16_t) pData[2] << 5))
                         & 0x07FF;
    RC_CtrlData.rc.ch2 = (((int16_t) pData[2] >> 6) | ((int16_t) pData[3] << 2) |
                          ((int16_t) pData[4] << 10)) & 0x07FF;
    RC_CtrlData.rc.ch3 = (((int16_t) pData[4] >> 1) | ((int16_t) pData[5] << 7)) &
                         0x07FF;

    RC_CtrlData.rc.s1 = ((pData[5] >> 4) & 0x000C) >> 2;
    RC_CtrlData.rc.s2 = ((pData[5] >> 4) & 0x0003);
    RC_CtrlData.mouse.x = ((int16_t) pData[6]) | ((int16_t) pData[7] << 8);
    RC_CtrlData.mouse.y = ((int16_t) pData[8]) | ((int16_t) pData[9] << 8);
    RC_CtrlData.mouse.z = ((int16_t) pData[10]) | ((int16_t) pData[11] << 8);
    RC_CtrlData.mouse.press_l = pData[12];
    RC_CtrlData.mouse.press_r = pData[13];
    RC_CtrlData.key.v = ((int16_t) pData[14]);// | ((int16_t)pData[15] << 8);
    fbdata.ch0=(RC_CtrlData.rc.ch0-1024)/660.0f;
    fbdata.ch1=(RC_CtrlData.rc.ch1-1024)/660.0f;
    fbdata.ch2=(RC_CtrlData.rc.ch2-1024)/660.0f;
    fbdata.ch3=(RC_CtrlData.rc.ch3-1024)/660.0f;
    fbdata.s1=RC_CtrlData.rc.s1;
    fbdata.s2=RC_CtrlData.rc.s2;
}
