//#define PIN_LED 7
int led = 7;       
int global_period; 
int global_duty = 0; // 0 ~ 100

void set_period(int period) {
    global_period = period;
}

void set_duty(int duty) {
    if (duty >= 0 && duty <= 100) {
        global_duty = duty;
    }
}


void setup() {
    pinMode(led, OUTPUT);
    // 10ms = 10000, 1ms = 1000, 0.1ms = 100
    set_period(100); 
}

void loop() {
    
    delayMicroseconds(global_period/2);
    digitalWrite(led, LOW);
    delayMicroseconds(global_period/2);
    for (int duty = 0; duty <= 100; duty++) {
        set_duty(duty);
        
        
            long high_time = (long)global_period * global_duty / 200;
            long low_time = global_period - high_time;

            digitalWrite(led, LOW);
            delayMicroseconds(low_time);
                
            digitalWrite(led, HIGH);
            delayMicroseconds(high_time);

        
    }
    delayMicroseconds(global_period/2);
    digitalWrite(led, HIGH);
    delayMicroseconds(global_period/2);

    for (int duty = 100; duty >= 0; duty--) {
        set_duty(duty);

            long high_time = (long)global_period * global_duty / 200;
            long low_time = global_period - high_time;
 
            digitalWrite(led, HIGH);
            delayMicroseconds(high_time);

            digitalWrite(led, LOW);
            delayMicroseconds(low_time);
        
    }
}
