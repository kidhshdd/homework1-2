//
// Created by 32805 on 2023/12/26.
//
#include "motor.h"

CAN_RxHeaderTypeDef can_header;
uint8_t can_data[8];
uint16_t ecd_angle, ecd_speed;
int16_t fdb_intensity;


void MotorDataProcess(uint8_t aData[]);
/*
Motor::Motor(const Type_e &type, const float &ratio, const ControlMethod_e &method, const PID &ppid, const PID &spid) {
    info_.type=type;
    info_.ratio=ratio;
    method_ = method;
    ppid_=ppid;
    spid_=spid;
}
*/
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
    if (hcan == &hcan1){
        HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &can_header, can_data);
				MotorDataProcess(can_data);
    }
}

void MotorDataProcess(uint8_t aData[]){
    ecd_angle=((uint16_t)aData[0]<<8)|aData[1];
    ecd_speed=((uint16_t)aData[2]<<8)|aData[3];
    fdb_intensity=(int16_t)((uint16_t)aData[4]<<8|aData[5]);
}
