#include "CommandManager.h"
#include <iostream>
#include <chrono>
#include <thread>

/*
* Настройки:
*	1. Цель стрельбы (Shooting target):
*		1.1. Голова. (v.1.3)
*		1.2. Тело. (v.2.1)
*		1.3. Ноги. (v.2.1)
*	2. Выбор режима стрельбы (Shooting mode selection):
*		2.1. Одиночный режим (1 патрон).
*		2.2. Режим очереди (3 патрона).
*		2.3. Автоматический режим (непрерывный).
*	3. Задать статрт турели (set/get StartDelay).
*	4. Выбор задержки выстрела (set/get ShootingDelay).
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
    std::cout << "Версия программы " << versionProgram << std::endl;
    std::cout << "Установленные настройки:" << std::endl;
    switch (target) {
    case 1: std::cout << "\tУстановлен цель стельбы \t— ГОЛОВА (" << target << ")" << std::endl; break;
    case 2: std::cout << "\tУстановлен цель стельбы \t— ТЕЛО (" << target << ")" << std::endl; break;
    case 3: std::cout << "\tУстановлен цель стельбы \t— НОГИ (" << target << ")" << std::endl; break;
    }
    switch (mode) {
    case 1: std::cout << "\tУстановлен режим стрельбы \t— ОДИНОЧНЫМИ (" << mode << ")" << std::endl; break;
    case 2: std::cout << "\tУстановлен режим стрельбы \t— ОЧЕРЕДЬЮ (" << mode << ")" << std::endl; break;
    case 3: std::cout << "\tУстановлен режим стрельбы \t— АВТОМАТИЧЕСКИ (" << mode << ")" << std::endl; break;
    }
    std::cout << "\tЗадержка выстрела турели \t— " << delay << " сек." << std::endl;
    std::cout << "\tЗапуск турели через \t\t— " << startDelay << " сек. \n" << std::endl;
}

void CommandManager::GetHelp() const {
    std::cout << "Список коман:" << std::endl;
    std::cout << "1.\t|\t/start\t\t\t\t|\tЗапуск турели." << std::endl;
    std::cout << "2.\t|\t/stop\t\t\t\t|\tОстановить работу турели." << std::endl;
    std::cout << "3.\t|\t/info\t\t\t\t|\tПолучить всю информацию о настройках турели." << std::endl;
    std::cout << "4.\t|\t/help\t\t\t\t|\tСписок доступных команды." << std::endl;
    std::cout << "5.\t|\t/setTarget <1|2|3>\t\t|\tУстановить цель турели (1 - голова, 2 - тело, 3 - ноги)." << std::endl;
    std::cout << "6.\t|\t/getTarget\t\t\t|\tПолучить информацию о выбранной цели турели." << std::endl;
    std::cout << "7.\t|\t/setMode <1|2|3>\t\t|\tУстаноить режим стрельбы (1 - одиночными, 2 - очередью, 3 - автоматически)." << std::endl;
    std::cout << "8.\t|\t/getMode\t\t\t|\tПолучить информацию о выбранном режиме стрельбы." << std::endl;
    std::cout << "9.\t|\t/setDelay <T(сек)>\t\t|\tУстаноить задержку перед выстрелом в цель." << std::endl;
    std::cout << "10.\t|\t/getDelay>\t\t\t|\tПолучить информацию о заданной задержки стрельбы." << std::endl;
    std::cout << "11.\t|\t/setStartDelay <T(сек)>\t\t|\tУстаноить старт запуска турели." << std::endl;
    std::cout << "12.\t|\t/getStartDelay\t\t\t|\tПолучить информацию о заданном старте турели." << std::endl;
}

int CommandManager::SetTarget(int target) {
    if (target < 1 || target > 3) {
        std::cout << "Ошибка: неверная цель (допустимо 1, 2 или 3)" << std::endl;
        return currentTarget;
    }
    currentTarget = target;
    switch (target)
    {
    case 1: std::cout << "Установленная цель - ГОЛОВА (" << target << ")." << std::endl; break;
    case 2: std::cout << "Установленная цель - ТЕЛО (" << target << ")." << std::endl; break;
    case 3: std::cout << "Установленная цель - НОГИ (" << target << ")." << std::endl; break;
    }
    return currentTarget;
}

int CommandManager::GetTarget() const {
    int target;
    target = currentTarget;
    switch (target)
    {
    default:
    case 1: std::cout << "Установленная цель - ГОЛОВА (" << target << ")." << std::endl; break;
    case 2: std::cout << "Установленная цель - ТЕЛО (" << target << ")." << std::endl; break;
    case 3: std::cout << "Установленная цель - НОГИ (" << target << ")." << std::endl; break;
    }
    return currentTarget;
}

int CommandManager::SetMode(int mode) {
    if (mode < 1 || mode > 3) {
        std::cout << "Ошибка: неверный режим (допустимо 1, 2 или 3)" << std::endl;
        return currentMode;
    }
    currentMode = mode;
    switch (mode) {
    case 1: std::cout << "Установлен режим стрельбы - ОДИНОЧНЫМИ (" << mode << ")" << std::endl; break;
    case 2: std::cout << "Установлен режим стрельбы - ОЧЕРЕДЬЮ (" << mode << ")" << std::endl; break;
    case 3: std::cout << "Установлен режим стрельбы - АВТОМАТИЧЕСКИ (" << mode << ")" << std::endl; break;
    }
    return currentMode;
}

int CommandManager::GetMode() const {
    int mode;
    mode = currentMode;
    switch (mode) {
    case 1: std::cout << "Установлен режим стрельбы - ОДИНОЧНЫМИ (" << mode << ")" << std::endl; break;
    case 2: std::cout << "Установлен режим стрельбы - ОЧЕРЕДЬЮ (" << mode << ")" << std::endl; break;
    case 3: std::cout << "Установлен режим стрельбы - АВТОМАТИЧЕСКИ (" << mode << ")" << std::endl; break;
    }
    return mode;
}

int CommandManager::SetStartDelay(int startDelay) {
     currentStartDelay = startDelay;
    if (currentStartDelay <= 0) {
        std::cerr << "Ошибка: время должно быть положительным числом!" << std::endl;
        return 1;
    }
    std::cout << "Установлено стартовое время в " << currentStartDelay << " сек." << std::endl;
    return currentStartDelay;
}

int CommandManager::GetStartDelay() const {
    std::cout << "Текующая установленная задержка запуска турели = " << currentStartDelay << " сек." << std::endl;
    return currentStartDelay;
}

int CommandManager::SetShootingDelay(int delay) {
    currentShootingDelay = delay;
    if (currentShootingDelay <= 0) {
        std::cerr << "Ошибка: время должно быть положительным числом!" << std::endl;
        return 1;
    }
    std::cout << "Установлено задержка стрельбы в " << currentShootingDelay << " сек." << std::endl;
    return currentShootingDelay;
}

int CommandManager::GetShootingDelay() const {
    std::cout << "Текующая установленная задержка стрельбы в " << currentShootingDelay << " сек." << std::endl;
    return currentShootingDelay;
}