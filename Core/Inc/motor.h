//
// Created by 32805 on 2023/12/26.
//

#include "main.h"
#include "CAN.h"
extern uint16_t ecd_angle, ecd_speed;
extern int16_t fdb_intensity;
 /*
#ifndef PROJECT_MOTOR_H
#define PROJECT_MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

class PID {
public:
    PID(float kp, float ki, float kd, float i_max, float out_max);
    float Calculate(float ref, float fdb);
public:
    float kp_, ki_, kd_;
    float i_max_, out_max_;
    float output_;
protected:
    float ref_, fdb_;
    float err_, err_sum_, last_err_;
    float p_out_, i_out_, d_out_;
};


class Motor {
public:
    enum Type_e {
        M3508,
        M2006,
        GM6020,
    };
    enum ControlMethod_e {
        POSITION_SPEED, // 位置，速度双环 PID 控制
        SPEED, // 速度单环 PID 控制
    };
    enum Mode_e {
        POWER_OFF, // 断电，控制量置零
        STOP, // 将目标速度置零，计算得出控制量，使得电机停转
        WORKING, // 电机正常工作
    };
public:
    Motor(const Type_e& type, const float& ratio, const ControlMethod_e& method,
          const PID& ppid, const PID& spid);
    void Reset(void); // 重置电机所有状态
    void Handle(void); // 根据当前 mode_ 计算控制量
    void SetAngle(const float& target_angle); // 设置目标角度
    void SetSpeed(const float& target_speed); // 设置目标速度
public:
    struct MotorInfo {
        Type_e type;
        float ratio; // 减速比
    } info_;
    Mode_e mode_;
    ControlMethod_e method_;
    int16_t intensity_; // 控制量
    float target_angle, target_speed; // 期望角度、速度
    struct MotorData {
        float angle; // 减速后的输出端角度
        float ecd_angle; // 编码器角度
        float last_ecd_angle;
        float rotate_speed; // 减速后的输出端转速
        float current; // 转矩电流
        float temp; // 电机温度
    } motor_data_;
    PID ppid_, spid_;

};


#ifdef __cplusplus
};
#endif
#endif //PROJECT_MOTOR_H
*/