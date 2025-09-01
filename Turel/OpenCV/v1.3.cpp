#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include "CommandManager.h"
using namespace cv;
using namespace std;

int Turel(const double& arrow_rotation_deg);
int target = 1;
int mode = 3;
int startDelay = 0;
int delay = 0;
float versionProgram = 1.3f;

int Turel(const double& arrow_rotation_deg) {
          cout << "��������� ������ �� " << arrow_rotation_deg << " ��������." << endl;
          //cout << "���� ������ " << target << endl;
          //cout << "����� ������ " << mode << endl;
          //cout << mode;
          //cout << "�������� ��������: " << delay << endl;
          switch (mode) {
          case 1: // ����������
              if (delay != 0) {
                  this_thread::sleep_for(std::chrono::seconds(delay));
                  cout << "���" << std::endl; 
              }
              cout << "���" << std::endl; 
              break;
          case 2: // ��������
              if (delay != 0) {
                  this_thread::sleep_for(std::chrono::seconds(delay));
                  cout << "��-��-��" << std::endl;
              }
              std::cout << "��-��-��" << std::endl;
              break;
          case 3: // �������������
              if (delay != 0) {
                  this_thread::sleep_for(std::chrono::seconds(delay));
                  cout << "��-��-��-��-��-��" << std::endl;
              }
              std::cout << "��-��-��-��-��-��" << std::endl; 
              break;
          }
    return 0;
}

int webcam(const std::string& cmd, std::atomic<bool>& stopFlag) {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "�� ������� �������� ������ � ������." << endl;
        return -1;
    }

    Mat img;
    int frame_width = 640;
    double horizontal_FOV = 100.0; // �������� ����������� ������� ������� ����� �������.

    CascadeClassifier profileFaceCascade;
    CascadeClassifier frontalFaceCascadeAlt;
    if (!profileFaceCascade.load("Resources/haarcascade_frontalface_default.xml")) { // haarcascade_profileface.xml
        cout << "�� ������� ��������� haarcascade_profileface.xml.\n��������� ���� �����������." << endl;
        return -1;
    }
    if (!frontalFaceCascadeAlt.load("Resources/haarcascade_frontalface_alt.xml")) { // haarcascade_frontalface_alt.xml
        cout << "�� ������� ��������� haarcascade_frontalface_alt.xml.\n��������� ���� �����������." << endl;
        return -1;
    }
    if (cmd == "/start") {
        while (!stopFlag) {
            bool success = cap.read(img);
            if (!success || img.empty()) {
                cout << "������ ���� ��� ������ �������." << endl;
                break;
            }
            frame_width = img.cols;
            vector<Rect> faces1;
            vector<Rect> faces2;
            profileFaceCascade.detectMultiScale(img, faces1, 1.2, 10);
            frontalFaceCascadeAlt.detectMultiScale(img, faces2, 1.2, 10);

            for (int i = 0; i < faces1.size(); ++i) {
                Rect r = faces1[i];
                float center_x = r.x + r.width * 0.5f;
                float center_y = r.y + r.height * 0.5f;

                rectangle(img, r.tl(), r.br(), Scalar(0, 0, 255), 3); // �������
                circle(img, Point(cvRound(center_x), cvRound(center_y)), 3, Scalar(255, 0, 255), -1);

                double angle_offset = ((center_x - frame_width / 2.0) / (frame_width / 2.0)) * (horizontal_FOV / 2.0);
                double arrow_rotation_deg = 90 + angle_offset;

                cout << "faceCascade: ������ " << i << " ����� (" << center_x << ", " << center_y << ")" << endl;
                //cout << "��������� ������� �� " << arrow_rotation_deg << " ��������." << endl;
                Turel(arrow_rotation_deg);
            }

            for (int i = 0; i < faces2.size(); ++i) {
                Rect r = faces2[i];
                float center_x = r.x + r.width * 0.5f;
                float center_y = r.y + r.height * 0.5f;

                rectangle(img, r.tl(), r.br(), Scalar(0, 255, 0), 3); // ������
                circle(img, Point(cvRound(center_x), cvRound(center_y)), 3, Scalar(255, 255, 0), -1);

                double angle_offset = ((center_x - frame_width / 2.0) / (frame_width / 2.0)) * (horizontal_FOV / 2.0);
                double arrow_rotation_deg = 90 + angle_offset;

                cout << "frontalfaceCascade: ������ " << i << " ����� (" << center_x << ", " << center_y << ")" << endl;
                Turel(arrow_rotation_deg);
            }

            imshow("Image", img);
            waitKey(1);    
            if (cmd == "/stop" || cmd == "/exit") {
                stopFlag = true;
                break;
                // ����� ��������� ���������� ������, ���� �����
            }
        }
    }
	return 0;
}

int main() {
	setlocale(LC_ALL, "Ru");
    CommandManager commandManager;
    atomic<bool> stopFlag(false);
    thread camThread;

    //int target;
    //int mode;
    //int startDelay = 0;
    //float versionProgram = 1.3f;
    string line;

    while (true) {
        std::cout << ">";
        if (!std::getline(std::cin, line)) break; // EOF ��� ������ �����
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "/start") {
            if (startDelay > 0) {
                cout << "������ ������ ����� " << startDelay << " ���." << endl;
                this_thread::sleep_for(std::chrono::seconds(startDelay));
            }
            if (camThread.joinable()) {
                std::cout << "������ ��� ��������." << std::endl;
            }
            else {
                stopFlag = false;
                camThread = std::thread(webcam, "/start", std::ref(stopFlag));
                camThread.detach();
                std::cout << "������ ������." << std::endl;
            }
        }
        else if (cmd == "/stop" || cmd == "/exit") {
            stopFlag = true;
            if (camThread.joinable()) {
                camThread.join();
            }
            std::cout << "������ ������ ����������." << std::endl;
        }
        else if (cmd == "/info") {
            commandManager.GetInfo(versionProgram);
        }
        else if (cmd == "/help") {
            commandManager.GetHelp();
        }
        else if (cmd == "/setTarget") {
            if (iss >> target) {
                commandManager.SetTarget(target);
            }
            else {
                std::cout << "������� ����: " << commandManager.GetTarget()
                    << ". �������������: /setTarget <1|2|3>\n������� ������ ��� ��������� 2 � 3 ������.";
            }
        }
        else if (cmd == "/getTarget") {
            commandManager.GetTarget();
        }
        else if (cmd == "/setMode") {
            if (iss >> mode) {
                commandManager.SetMode(mode);
            }
            else {
                std::cout << "������� �����: " << commandManager.GetMode()
                    << ". �������������: /setMode <1|2|3>" << endl;
            }
        }
        else if (cmd == "/getMode") {
            commandManager.GetMode();
        }
        else if (cmd == "/setStartDelay") {
            if (iss >> startDelay) {
                commandManager.SetStartDelay(startDelay);
            }
            else {
                std::cout << "�������� �����: " << commandManager.GetStartDelay()
                    << ". ����������� �������: /setStartDelay <T> (� ���.)" << std::endl;
            }
        }
        else if (cmd == "/getStartDelay") {
            commandManager.GetStartDelay();
        }
        else if (cmd == "/setDelay") {
            if (iss >> delay) {
                commandManager.SetShootingDelay(delay);
            }
            else {
                std::cout << "�������� �����: " << commandManager.GetShootingDelay()
                    << ". ����������� �������: /setDelay <T> (� ���.)" << std::endl;
            }
        }
        else if (cmd == "/getDelay") {
            commandManager.GetShootingDelay();
        }
        else {
            std::cout << "����������� �������. ����� ������ ������ ��������� �������, �������: /help" << std::endl;
        }
    }
	return 0;
}
