# STM32 PWM LED Controller with ADC, Buttons and Interrupts

## 📌 Project Overview

This project is a bare-metal embedded system implementation for **STM32F303** microcontroller.  
It demonstrates low-level peripheral programming using **register-level CMSIS access** without HAL libraries.

The system controls LED brightness using:
- PWM (Timer 3)
- ADC analog input
- GPIO buttons
- Interrupt handling (SysTick, TIM3)

---

## ⚙️ Features

### 💡 LED Control
- LED brightness controlled via **PWM (TIM3 Channel 1)**
- Duty cycle adjusted dynamically using ADC input

### 🎛 ADC Input
- Reads analog signal from **PA0**
- 12-bit resolution (0–4095)
- Used to control PWM duty cycle

### 🔘 Button Input
- Two buttons connected to GPIO inputs:
  - PA5
  - PA1
- Buttons can override LED brightness

### ⏱ Interrupts
- SysTick interrupt (1 ms tick counter)
- TIM3 interrupt handling (update + compare events)

---

## 🧠 How It Works

1. ADC continuously reads analog value (potentiometer or sensor)
2. Value is scaled to PWM range (0–100%)
3. Timer 3 generates PWM signal on PA6
4. LED brightness changes according to ADC input
5. Buttons can force predefined brightness levels

---

## 🧩 Hardware Setup

| Signal | Pin  | Description |
|--------|------|-------------|
| ADC    | PA0  | Analog input |
| PWM    | PA6  | LED output (TIM3 CH1) |
| Button | PA5  | Input with pull-up |
| Button | PA1  | Input with pull-up |

---

## 📁 Project Structure (layered view)

led_pwm_interrupt_driver/                                                                                                                                                                      
├── Inc/                                                                                                                                                                                       
│ ├── ADC_driver.h                                                                                                                                                                             
│ ├── GPIO_driver.h                                                                                                                                                                            
│ ├── TIMER_driver.h                                                                                                                                                                           
│ ├── SYSTICK_driver.h
│ ├── led_logic.h                                                                                                                                                                              
│ ├── main.h                                                                                                                                                                                   
│ └── prototypes.h                                                                                                                                                                             
│                                                                                                                                                                                              
├── Src/                                                                                                                                                                                       
│ ├── main.c                                                                                                                                                                                   
│ ├── app.c                                                                                                                                                                                    
│ ├── ADC_driver.c                                                                                                                                                                             
│ ├── GPIO_driver.c                                                                                                                                                                            
│ ├── TIMER_driver.c                                                                                                                                                                           
│ ├── SYSTICK_driver.c                                                                                                                                                                         
│ └── led_logic.c                                                                                                                                                                              
│                                                                                                                                                                                              
├── Drivers/                                                                                                                                                                                   
│ └── CMSIS/                                                                                                                                                                                   
│                                                                                                                                                                                              
├── Debug/                                                                                                                                                                                     
├── Release/                                                                                                                                                                                  
└── README.md                                                                                                                                                                                  


<div align="center">

<img src="https://github.com/user-attachments/assets/4e891f63-16fb-4dc5-b992-8d9bfd9e4309"
     width="400"
     style="border: 2px solid #ccc; border-radius: 10px; padding: 5px;">

</div>
<img src="URL"
     width="400"
     style="transform: rotate(-90deg); border: 1px solid #ccc; border-radius: 8px;">


## 🛠️ Tech Stack

- STM32F303RE
- CMSIS (no HAL / LL)
- C (bare-metal programming)
- Timers (PWM mode)
- ADC peripheral
- GPIO configuration
- NVIC interrupts

---

