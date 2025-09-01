#pragma once
class CommandManager {
public:
    CommandManager(int defaultTarget = 1, int defaultMode = 3, int defaultShootingDelay = 0, int defaultStartDelay = 0);
    void GetInfo(float versionProgram);
    void GetHelp() const;
    int SetTarget(int target);
    int GetTarget() const;
    int SetMode(int mode);
    int GetMode() const;
    int SetStartDelay(int startDelay);
    int GetStartDelay() const;
    int SetShootingDelay(int delay);
    int GetShootingDelay() const;
private:
    int currentTarget, currentMode, currentShootingDelay, currentStartDelay;
};