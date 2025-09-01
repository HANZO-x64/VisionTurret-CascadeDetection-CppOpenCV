#include "CommandManager.h"
#include <iostream>
#include <chrono>
#include <thread>

/*
* ���������:
*	1. ���� �������� (Shooting target):
*		1.1. ������. (v.1.3)
*		1.2. ����. (v.2.1)
*		1.3. ����. (v.2.1)
*	2. ����� ������ �������� (Shooting mode selection):
*		2.1. ��������� ����� (1 ������).
*		2.2. ����� ������� (3 �������).
*		2.3. �������������� ����� (�����������).
*	3. ������ ������ ������ (set/get StartDelay).
*	4. ����� �������� �������� (set/get ShootingDelay).
*/

CommandManager::CommandManager(int defaultTarget, int defaultMode, int defaultShootingDelay, int defaultStartDelay)
    : currentTarget(defaultTarget)
    , currentMode(defaultMode)
    , currentShootingDelay(defaultShootingDelay)
    , currentStartDelay(defaultStartDelay)
{}

void CommandManager::GetInfo(float versionProgram) {
    int target, mode, delay, startDelay;
    target = currentTarget;
    mode = currentMode;
    delay = currentShootingDelay;
    startDelay = currentStartDelay;
    std::cout << "������ ��������� " << versionProgram << std::endl;
    std::cout << "������������� ���������:" << std::endl;
    switch (target) {
    case 1: std::cout << "\t���������� ���� ������� \t� ������ (" << target << ")" << std::endl; break;
    case 2: std::cout << "\t���������� ���� ������� \t� ���� (" << target << ")" << std::endl; break;
    case 3: std::cout << "\t���������� ���� ������� \t� ���� (" << target << ")" << std::endl; break;
    }
    switch (mode) {
    case 1: std::cout << "\t���������� ����� �������� \t� ���������� (" << mode << ")" << std::endl; break;
    case 2: std::cout << "\t���������� ����� �������� \t� �������� (" << mode << ")" << std::endl; break;
    case 3: std::cout << "\t���������� ����� �������� \t� ������������� (" << mode << ")" << std::endl; break;
    }
    std::cout << "\t�������� �������� ������ \t� " << delay << " ���." << std::endl;
    std::cout << "\t������ ������ ����� \t\t� " << startDelay << " ���. \n" << std::endl;
}

void CommandManager::GetHelp() const {
    std::cout << "������ �����:" << std::endl;
    std::cout << "1.\t|\t/start\t\t\t\t|\t������ ������." << std::endl;
    std::cout << "2.\t|\t/stop\t\t\t\t|\t���������� ������ ������." << std::endl;
    std::cout << "3.\t|\t/info\t\t\t\t|\t�������� ��� ���������� � ���������� ������." << std::endl;
    std::cout << "4.\t|\t/help\t\t\t\t|\t������ ��������� �������." << std::endl;
    std::cout << "5.\t|\t/setTarget <1|2|3>\t\t|\t���������� ���� ������ (1 - ������, 2 - ����, 3 - ����)." << std::endl;
    std::cout << "6.\t|\t/getTarget\t\t\t|\t�������� ���������� � ��������� ���� ������." << std::endl;
    std::cout << "7.\t|\t/setMode <1|2|3>\t\t|\t��������� ����� �������� (1 - ����������, 2 - ��������, 3 - �������������)." << std::endl;
    std::cout << "8.\t|\t/getMode\t\t\t|\t�������� ���������� � ��������� ������ ��������." << std::endl;
    std::cout << "9.\t|\t/setDelay <T(���)>\t\t|\t��������� �������� ����� ��������� � ����." << std::endl;
    std::cout << "10.\t|\t/getDelay>\t\t\t|\t�������� ���������� � �������� �������� ��������." << std::endl;
    std::cout << "11.\t|\t/setStartDelay <T(���)>\t\t|\t��������� ����� ������� ������." << std::endl;
    std::cout << "12.\t|\t/getStartDelay\t\t\t|\t�������� ���������� � �������� ������ ������." << std::endl;
}

int CommandManager::SetTarget(int target) {
    if (target < 1 || target > 3) {
        std::cout << "������: �������� ���� (��������� 1, 2 ��� 3)" << std::endl;
        return currentTarget;
    }
    currentTarget = target;
    switch (target)
    {
    case 1: std::cout << "������������� ���� - ������ (" << target << ")." << std::endl; break;
    case 2: std::cout << "������������� ���� - ���� (" << target << ")." << std::endl; break;
    case 3: std::cout << "������������� ���� - ���� (" << target << ")." << std::endl; break;
    }
    return currentTarget;
}

int CommandManager::GetTarget() const {
    int target;
    target = currentTarget;
    switch (target)
    {
    default:
    case 1: std::cout << "������������� ���� - ������ (" << target << ")." << std::endl; break;
    case 2: std::cout << "������������� ���� - ���� (" << target << ")." << std::endl; break;
    case 3: std::cout << "������������� ���� - ���� (" << target << ")." << std::endl; break;
    }
    return currentTarget;
}

int CommandManager::SetMode(int mode) {
    if (mode < 1 || mode > 3) {
        std::cout << "������: �������� ����� (��������� 1, 2 ��� 3)" << std::endl;
        return currentMode;
    }
    currentMode = mode;
    switch (mode) {
    case 1: std::cout << "���������� ����� �������� - ���������� (" << mode << ")" << std::endl; break;
    case 2: std::cout << "���������� ����� �������� - �������� (" << mode << ")" << std::endl; break;
    case 3: std::cout << "���������� ����� �������� - ������������� (" << mode << ")" << std::endl; break;
    }
    return currentMode;
}

int CommandManager::GetMode() const {
    int mode;
    mode = currentMode;
    switch (mode) {
    case 1: std::cout << "���������� ����� �������� - ���������� (" << mode << ")" << std::endl; break;
    case 2: std::cout << "���������� ����� �������� - �������� (" << mode << ")" << std::endl; break;
    case 3: std::cout << "���������� ����� �������� - ������������� (" << mode << ")" << std::endl; break;
    }
    return mode;
}

int CommandManager::SetStartDelay(int startDelay) {
     currentStartDelay = startDelay;
    if (currentStartDelay <= 0) {
        std::cerr << "������: ����� ������ ���� ������������� ������!" << std::endl;
        return 1;
    }
    std::cout << "����������� ��������� ����� � " << currentStartDelay << " ���." << std::endl;
    return currentStartDelay;
}

int CommandManager::GetStartDelay() const {
    std::cout << "�������� ������������� �������� ������� ������ = " << currentStartDelay << " ���." << std::endl;
    return currentStartDelay;
}

int CommandManager::SetShootingDelay(int delay) {
    currentShootingDelay = delay;
    if (currentShootingDelay <= 0) {
        std::cerr << "������: ����� ������ ���� ������������� ������!" << std::endl;
        return 1;
    }
    std::cout << "����������� �������� �������� � " << currentShootingDelay << " ���." << std::endl;
    return currentShootingDelay;
}

int CommandManager::GetShootingDelay() const {
    std::cout << "�������� ������������� �������� �������� � " << currentShootingDelay << " ���." << std::endl;
    return currentShootingDelay;
}