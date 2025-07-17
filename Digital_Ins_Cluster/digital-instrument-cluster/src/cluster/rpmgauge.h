class RPMGauge {
public:
    RPMGauge();
    void setRPM(float rpm);
    float getRPM() const;

private:
    float currentRPM;
};