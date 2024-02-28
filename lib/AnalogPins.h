class AnalogPins{
public:
    static bool is3_3OK();
    static bool is5OK();
    static bool is12OK();
    static bool is44OK();
    float GetValueFromPin(int pin);

private:
    static const uint16_t Val3_3 = 682;   
    static const uint16_t Val5 = 516;     
    static const uint16_t Val12 = 225;    
    static const uint16_t Val44 = 954; 
    static const uint16_t napaka = 41; 
    static const int Pin3_3= A1;
    static const int Pin5= A2;
    static const int Pin12= A3;
    static const int Pin4= A0;

};